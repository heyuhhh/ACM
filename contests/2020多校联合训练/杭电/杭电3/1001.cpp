// Author : heyuhhh
// Created Time : 2020/07/31 11:10:13
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;

namespace PAM{
    int ch[N][26], fail[N], len[N], st[N], cnt[N];
    int slink[N], diff[N];
    int val[N];
    int sz, n, last;
    // 0: len=0  1: len=-1
    int New(int l, int f) {
        memset(ch[++sz], 0, sizeof(ch[sz]));
        len[sz] = l, fail[sz] = f;
        diff[sz] = slink[sz] = 0;
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
    bool Insert(int c, int i) { //int
        st[++n] = c;
        int x = getf(last);
        bool F = 0;
        if(!ch[x][c]) {
            F = 1;
            int f = getf(fail[x]);
            int now;
            now = ch[x][c] = New(len[x] + 2, ch[f][c]);
            diff[now] = len[now] - len[fail[now]];
            if (diff[now] == diff[fail[now]]) slink[now] = slink[fail[now]];
            else slink[now] = fail[now];
        }
        last = ch[x][c];
        val[i] = last;
        cnt[last]++;
        return F;
    }

    int f[N][20];
    void build() {
        for (int i = 0; i <= sz; i++) {
            f[i][0] = fail[i];
        }
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i <= sz; i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }
    }
    int find(int x, int l) {
        x = val[x];
        for (int i = 19; i >= 0; i--) {
            if (len[f[x][i]] >= l) {
                x = f[x][i];
            }
        }
        return x;
    }
    int cmp(int u, int v) {
        while (u > 1 && v > 1) {
            if (len[u] != len[v]) {
                return len[u] > len[v] ? 1 : -1;
            }
            if (diff[u] != diff[v]) {
                return diff[u] < diff[v] ? 1 : -1;
            }
            if (len[u] - len[slink[u]] != len[v] - len[slink[v]]) {
                if (len[u] - len[slink[u]] > len[v] - len[slink[v]]) {
                    return diff[slink[v]] > diff[u] ? 1 : -1;
                } else {
                    return diff[slink[u]] > diff[v] ? -1 : 1;
                }
            }
            u = slink[u], v = slink[v];
        }
        if (u <= 1 && v <= 1) return 0;
        return u > v ? 1 : -1;
    }
};

void run() {
    PAM::init();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        PAM::Insert(s[i] - 'a', i);
    }
    PAM::build();
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        a = PAM::find(b, b - a + 1);
        b = PAM::find(d, d - c + 1);
        int cmp = PAM::cmp(a, b);
        if (cmp == -1) {
            cout << "sjfnb" << '\n';
        } else if (cmp == 1) {
            cout << "cslnb" << '\n';
        } else {
            cout << "draw" << '\n';
        }
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}