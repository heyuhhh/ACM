// Author : heyuhhh
// Created Time : 2021/03/31 17:08:52
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
const int N = 3e5 + 5, M = 2e5 + 5;

int n, m;
struct Edge {
    int u, v, w;
    bool operator < (const Edge& A) const {
        return w < A.w;
    }
} e[M];

int v[N], lson[N], rson[N];

int tot;
int f[N], siz[N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void Union(int x, int y, int w) {
    x = find(x), y = find(y);
    if (x == y) return;
    siz[++tot] = siz[x] + siz[y];
    if (siz[x] > siz[y]) swap(x, y);
    lson[tot] = x, rson[tot] = y;
    f[x] = f[y] = tot;
    v[tot] = w;
}

ll ans;
int p[N];
bool vis[N];
int cur, r;

void dfs2(int u, int w) {
    if (!r) return;
    if (u <= n) {
        p[cur] = u;
        if (cur < n) {
            ans += 2 * w;
            r -= 2;
        } else if (cur == n) {
            ans += w;
            --r;
        }
        vis[u] = true;
        cur += 2;
        return;
    }
    dfs2(lson[u], w);
    dfs2(rson[u], w);
}

void dfs(int u) {
    if (u <= n) return;
    dfs2(lson[u], v[u]);
    if (r) dfs(rson[u]);
}

void dfs3(int u) {
    if (u == 0) return;
    if (u <= n) {
        if (!vis[u]) {
            vis[u] = true;
            p[cur] = u;
            cur += 2;
            return;
        }
    }
    dfs3(lson[u]);
    dfs3(rson[u]);
}

void run() {
    cin >> n >> m;
    tot = n;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = Edge{u, v, w};
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i < N; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        siz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        Union(u, v, w);
    }
    r = n - 1, cur = 2;
    dfs(tot);
    cur = 1;
    dfs3(tot);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
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