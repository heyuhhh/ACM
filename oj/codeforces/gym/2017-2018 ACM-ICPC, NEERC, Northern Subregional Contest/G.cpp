/*
 * Author:  heyuhhh
 * Created Time:  2020/6/12 15:31:13
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
#include <functional>
#include <numeric>
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
const int N = 1e5 + 5;
 
int n, m;
vector <pii> G[N], edges;
vector <int> nG[N];
pii color[N], f[N];
int vis[N], dfn, c1, c2;
bool flag;
 
int paint(int x, int c) {
    if (color[x].fi == -1) {
        color[x].fi = c;
        return 0;
    }
    color[x].se = c;
    return 1;
}
 
void paint(int x, int y, int c) {
    while (x != y) {
        pii now = f[x];
        if (paint(now.se, c)) {
            flag = true;
            c1 = color[now.se].fi;
            c2 = color[now.se].se;
        }   
        x = now.fi;
    }
}
 
void dfs(int u, int fa, int t) {
    f[u] = MP(fa, t);
    vis[u] = ++dfn;
    for (auto it : G[u]) {
        int v = it.fi, id = it.se;
        if (v == fa) continue;
        if (!vis[v]) {
            dfs(v, u, id);
        } else if (vis[v] < vis[u]) {
            if (flag) continue;
            paint(u, v, id);
        }
    }
}
 
int d[N];
 
bool ok(int id, int c) {
    return color[id].fi == c || color[id].se == c || id == c;
}
 
void find() {
    for (int i = 1; i <= m; i++) {
        if (ok(i, c1) || ok(i, c2)) {
            int u = edges[i].fi, v = edges[i].se;
            nG[u].push_back(v);
            nG[v].push_back(u);
            ++d[u], ++d[v];
        }
    }
}
 
vector <vector <int>> cyc(3);
int S, T, t;
 
void go(int u, int fa) {
    if (u == T) return;
    for (auto v : nG[u]) if (v != fa) {
        cyc[t].push_back(v);
        go(v, u);
        if (u == S) ++t;
    }
}
 
void run() {
    cin >> n >> m;
    flag = false;
    t = dfn = 0;
    for (int i = 0; i < 3; i++) {
        cyc[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        nG[i].clear();
        vis[i] = d[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        color[i] = MP(-1, -1);
    }
    edges.clear(), edges.push_back(MP(0, 0));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(MP(v, i));
        G[v].push_back(MP(u, i));
        edges.push_back(MP(u, v));
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, 0);
        }
    }
    
    if (!flag) {
        cout << -1 << '\n';
        return;
    }
    find();
    S = -1, T = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] >= 3) {
            if (S == -1) {
                S = i;
            } else if (T == -1) {
                T = i;
            }
        }
    }
    go(S, 0);
    cout << S << ' ' << T << '\n';
    for (int i = 0; i < 3; i++) {
        cout << sz(cyc[i]) + 1 << ' ' << S;
        for (auto it : cyc[i]) {
            cout << ' ' << it;
        }
        cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    freopen("grand.in", "r", stdin);
    freopen("grand.out", "w", stdout);
    int T; cin >> T; while(T--)
    run();
    return 0;
}

