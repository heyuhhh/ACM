/*
 * Author:  heyuhhh
 * Created Time:  2020/6/3 16:43:39
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

void sayNo() {
    cout << "No" << '\n';
    exit(0);   
}

int n, m;
vector <int> G[N];

int f[N][20], deep[N];
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }   
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
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

int d[N];
pii path[N];

vector <int> nG[N];
int deg[N];

void dfs2(int u, int fa) {
    for (auto v : G[u]) {
        if (v != fa) {
            dfs2(v, u);
            d[u] += d[v];
        }
    }
    if (fa && d[u]) {
        nG[fa].push_back(u);
        nG[u].push_back(fa);
        ++deg[fa], ++deg[u];
    }
}

bool vis[N];
int dfn[N], T;

vector <int> a;
void dfs3(int u, int fa) {
    vis[u] = true;
    dfn[u] = ++T;
    a.push_back(u);
    for (auto v : nG[u]) {
        if (v != fa) {
            dfs3(v, u);
        }
    }
}

vector <pii> vl[N], vr[N];
void solve() {
    vector <int> sta;
    for (auto it : a) {
        for (auto pairs : vl[it]) {
            sta.push_back(pairs.fi);
        }
        for (auto pairs : vr[it]) {
            if (sz(sta) && sta.back() == pairs.fi) {
                sta.pop_back();
            } else {
                sayNo();
            }
        }
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        path[i] = MP(u, v);
        ++d[u], ++d[v], d[LCA(u, v)] -= 2;
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            sayNo();
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && deg[i] == 1) {
            a.clear();
            dfs3(i, 0);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dfn[path[i].fi] > dfn[path[i].se]) {
            swap(path[i].fi, path[i].se);
        }        
    }
    for (int i = 1; i <= m; i++) {
        int u = path[i].fi, v = path[i].se;
        if (u == v) continue;
        vl[u].push_back(MP(i, dfn[v]));
        vr[v].push_back(MP(i, dfn[u]));
    }
    for (int i = 1; i <= n; i++) {
        if (sz(vl[i]) && sz(vr[i])) {
            sayNo();
        }
        sort(all(vl[i]), [&] (pii A, pii B) {
            if (A.se != B.se) return A.se > B.se;
            return A.fi > B.fi;
        });
        sort(all(vr[i]), [&] (pii A, pii B) {
            if (A.se != B.se) return A.se > B.se;
            return A.fi < B.fi;
        });
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && deg[i] == 1) {
            a.clear();
            dfs3(i, 0);
            solve();
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
