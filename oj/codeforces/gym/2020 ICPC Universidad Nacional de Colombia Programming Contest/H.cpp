// Author : heyuhhh
// Created Time : 2021/03/01 13:52:48
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;
namespace PAM{
    int ch[N][26], fail[N], len[N], st[N], cnt[N];
    int sz, n, last;
    int New(int l, int f) {
        memset(ch[++sz], 0, sizeof(ch[sz]));
        len[sz] = l, fail[sz] = f;
        return sz;
    }
    void init() {
        sz = -1;
        New(0, 1); last = New(-1, 0);
        st[n = 0] = -1;
        memset(cnt, 0, sizeof(cnt));
    }
    int getf(int x) {
        while(st[n - len[x] - 1] != st[n]) x = fail[x];
        return x;
    }
    bool Insert(int c) { //int
        st[++n] = c;
        int x = getf(last);
        bool F = 0;
        if(!ch[x][c]) {
            F = 1;
            int f = getf(fail[x]);
            ch[x][c] = New(len[x] + 2, ch[f][c]);
        }
        last = ch[x][c];
        cnt[last]++;
        return F;
    }
    void count() {
        for(int i = sz; i >= 1; i--) cnt[fail[i]] += cnt[i];
    }
    int dfs(int x) {
        int res = (x != 1);
        for (int i = 0; i < 26; i++) {
            if (ch[x][i]) res += dfs(ch[x][i]);
        }
        return res;
    }
};  
void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    PAM::init();
    for (int i = 0; i < n; i++) {
        PAM::Insert(s[i] - 'a');
    }
    int ans = PAM::dfs(1);
    vector<bool> v(26);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'] = true;
    }
    ans -= accumulate(all(v), 0);
    cout << ans << '\n';    
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}