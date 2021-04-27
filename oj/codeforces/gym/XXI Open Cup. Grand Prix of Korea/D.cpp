// Author : heyuhhh
// Created Time : 2020/11/09 10:07:19
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
const int N = 3e5 + 5;

int n, m;
struct Edge {
    int u, v, w;
    bool operator < (const Edge& A)const {
        return w > A.w;
    }
} e[N];

bool chk[N];

int f[N], sz[N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

ll ans;

bool Union(int x, int y, int w) {
    x = find(x), y = find(y);
    if (x == y) return false;
    ans += 1ll * sz[x] * sz[y] * w;
    sz[y] += sz[x];
    f[x] = y;
    return true;
}

vector<pii> G[N];
bool vis[N];
int up[N][21], g[N][21];
int deep[N];

void dfs(int u, int fa, int fw) {
    deep[u] = deep[fa] + 1;
    vis[u] = true;
    up[u][0] = fa;
    g[u][0] = fw;
    for (int j = 1; j <= 20; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
        g[u][j] = min(g[u][j - 1], g[up[u][j - 1]][j - 1]);
    }
    for (auto it : G[u]) {
        int v = it.fi, w = it.se;
        if (v != fa) {
            dfs(v, u, w);
        }
    }
}

int query(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int res = INF;
    for (int i = 20; i >= 0; i--) {
        if (deep[up[x][i]] >= deep[y]) {
            res = min(res, g[x][i]);
            x = up[x][i];
        }
    }
    if (x == y) return res;
    for (int i = 20; i >= 0; i--) {
        if (up[x][i] != up[y][i]) {
            res = min(res, min(g[x][i], g[y][i]));
            x = up[x][i];
            y = up[y][i];
        }
    }
    res = min(res, min(g[x][0], g[y][0]));
    return res;
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = Edge{u, v, w};
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = e[i].u, v = e[i].v, w = e[i].w;
        if (Union(u, v, w)) {
            chk[i] = true;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
    }
    ll tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            tmp += 1ll * sz[i] * (n - sz[i]);
        }
    }
    ans += tmp / 2;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs(i, 0, INF);
    }
    bool flag = true;
    for (int i = 1; i <= m; i++) if (!chk[i]) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (query(u, v) != w) {
            flag = false;
            break;
        }
    }
    if (!flag) ans = -1;
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