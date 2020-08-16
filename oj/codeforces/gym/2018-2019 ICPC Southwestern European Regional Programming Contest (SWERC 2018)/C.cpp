// Author : heyuhhh
// Created Time : 2020/08/16 10:16:42
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
const int N = 1e6 + 5;

struct Trie {
    int ch[N][26], tot;
    void insert(const string& s) {
        int n = s.length();
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (!ch[x][s[i] - 'a']) {
                ch[x][s[i] - 'a'] = ++tot;
            }
            x = ch[x][s[i] - 'a'];
        }
    }
}t[2];

int mpN[6][6], mpM[6][6];
int ans;
int n, m, A, B;

void dfs(int x, int y) {
    if (x == n + 1) {
        ++ans;
        return;
    }
    for (int i = 0; i < 26; i++) {
        int lastN = mpN[x - 1][y], lastM = mpM[x][y - 1];
        int nx = t[0].ch[lastN][i], ny = t[1].ch[lastM][i];
        if (!(nx && ny)) continue;
        mpN[x][y] = nx;
        mpM[x][y] = ny;
        
        nx = x, ny = y + 1;
        if (ny > m) ++nx, ny = 1;
        dfs(nx, ny);
    }
}

void run() {
    cin >> n >> A >> m >> B;
    for (int i = 1; i <= A; i++) {
        string s;
        cin >> s;
        t[0].insert(s);
    }
    for (int i = 1; i <= B; i++) {
        string s;
        cin >> s;
        t[1].insert(s);
    }
    dfs(1, 1);
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