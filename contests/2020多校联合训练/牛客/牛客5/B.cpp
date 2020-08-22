// Author : heyuhhh
// Created Time : 2020/07/25 18:53:18
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
const int N = 1e5 + 5;

int n;
vector<pii> G[N];
int a[N];

void dfs(int u, int fa, int val) {
    a[u] = val;
    for (auto it : G[u]) {
        int v = it.fi, w = it.se;
        if (v == fa) continue;
        dfs(v, u, val ^ w);
    }
}

int ch[N * 31][2];
int tot;

void insert(int x) {
    int p = 0;
    for (int i = 29; i >= 0; i--) {
        int op = 0;
        if (x >> i & 1) {
            op = 1;
        }
        if (!ch[p][op]) {
            ch[p][op] = ++tot;
        }
        p = ch[p][op];
    }
}

ll ans;

int calc(int p1, int p2, int dep) {
    int res = INF;
    if (ch[p1][0] && ch[p2][0]) {
        res = calc(ch[p1][0], ch[p2][0], dep - 1);
    }
    if (ch[p1][1] && ch[p2][1]) {
        res = min(res, calc(ch[p1][1], ch[p2][1], dep - 1));
    }
    if (res != INF) return res;
    if (ch[p1][0] && ch[p2][1]) {
        res = min(res, calc(ch[p1][0], ch[p2][1], dep - 1) + (1 << dep));
    }
    if (ch[p1][1] && ch[p2][0]) {
        res = min(res, calc(ch[p1][1], ch[p2][0], dep - 1) + (1 << dep));
    }
    if (res == INF) res = 0;
    return res;
}

void work(int p, int dep) {
    if (ch[p][0]) {
        work(ch[p][0], dep - 1);
    }
    if (ch[p][1]) {
        work(ch[p][1], dep - 1);
    }
    if (ch[p][0] && ch[p][1]) {
        ans += (1 << dep);
        ans += calc(ch[p][0], ch[p][1], dep - 1);
    }
}

void run() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ++u, ++v;
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        insert(a[i]);
    }
    work(0, 29);
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