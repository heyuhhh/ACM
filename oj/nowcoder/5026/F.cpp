/*
 * Author:  heyuhhh
 * Created Time:  2020/4/16 16:22:33
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5, MAX = 1e7 + 5;

int n, m;
vector <pii> G[N];
int tsz, rt;
int sz[N], Max[N], father[N];
bool vis[N];
void getrt(int u, int fa) {
    sz[u] = 1; Max[u] = 0;
    for(auto it : G[u]) {
        int v = it.fi, w = it.se;
        if(v == fa || vis[v]) continue;
        getrt(v, u);
        sz[u] += sz[v];
        if(sz[v] > Max[u]) Max[u] = sz[v];
    }
    Max[u] = max(Max[u], tsz - sz[u]);
    if(Max[u] < Max[rt]) rt = u;
}
void findrt(int u, int fa) {
    tsz = (sz[u] == 0 ? n : sz[u]);
    Max[rt = 0] = INF;
    getrt(u, fa);
}
void dfs(int u, int fa) {
    vis[u] = true;
    for(auto it : G[u]) {
        int v = it.fi;
        if(v != fa && !vis[v]) {
            findrt(v, u);
            father[rt] = u;
            dfs(rt, 0);
        }
    }   
}

int f[N][20], deep[N], d[N];
void dfs2(int u, int fa) {
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;   
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }    
    for(auto it : G[u]) {
        int v = it.fi, w = it.se;
        if(v != fa) {
            d[v] = d[u] + w;
            dfs2(v, u);
        }
    }
}
int LCA(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(deep[f[x][i]] >= deep[y]) x = f[x][i];
    }   
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];   
    }
    return f[x][0];
}
 
int dis(int x, int y) {
    int z = LCA(x, y);
    return d[x] + d[y] - 2 * d[z];   
} 

int minv[MAX], ls[MAX], rs[MAX];
int root[N], tot;

void update(int &o, int l, int r, int p, int v) {
    if(!o) o = ++tot;   
    if(l == r) {
        minv[o] = min(minv[o], v);
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(ls[o], l, mid, p, v);
    else update(rs[o], mid + 1, r, p, v);
    minv[o] = min(minv[ls[o]], minv[rs[o]]);
}
void update(int x, int p) {
    for(int o = x; o; o = father[o]) {
        update(root[o], 1, 10000, p, dis(x, o));
    }
}

int query(int o, int l, int r, int L, int R) {
    if(!o) return INF;
    if(L <= l && r <= R) {
        return minv[o];   
    }
    int mid = (l + r) >> 1, ans = INF;
    if(L <= mid) ans = query(ls[o], l, mid, L, R);
    if(R > mid) ans = min(ans, query(rs[o], mid + 1, r, L, R));
    return ans;
}
int query(int x, int L, int R) {
    int ans = INF;
    for(int o = x; o; o = father[o]) {
        ans = min(ans, dis(x, o) + query(root[o], 1, 10000, L, R));
    }
    return ans;
}

int a[N];
void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
    }
    dfs2(1, 0);
    findrt(1, 0); 
    dfs(rt, 0); 
    memset(minv, INF, sizeof(minv));
    for(int i = 1; i <= n; i++) {
        update(i, a[i]);
    }
    while(m--) {
        int op, u, x; cin >> op >> u >> x;
        if(op == 1) {
            update(u, x);
        } else {
            int y; cin >> y;
            int ans = query(u, x, y);
            if(ans == INF) cout << -1 << '\n';
            else cout << 2 * ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
