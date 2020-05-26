/*
 * Author:  heyuhhh
 * Created Time:  2020/5/23 20:42:25
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
#include <bits/stdc++.h>
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
const int N = 1e6 + 5;

int n;
int a[N];
struct Edge {
    int u, v;
}e[N];

vector <int> G[N];
bool vis[N];
int f[N][2], g[N];

void run() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[i] = Edge {u, v};
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pii ans(INF, INF);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cout << "0/1" << '\n';
            return;
        }
        ans = min(ans, MP(a[i], 1));
    }
    if (ans.fi > 1) {
        cout << ans.fi << '/' << ans.se << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        int u = e[i].u, v = e[i].v;
        if (a[u] == 1 && a[v] == 1) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    
    int m = 0, rt;
    function <void(int, int, int)> dfs;
    dfs = [&](int u, int fa, int d) -> void {
        if (d > m) {
            m = d, rt = u;   
        }
        vis[u] = 1;
        for (auto v : G[u]) if (v != fa) {
            dfs(v, u, d + 1);
        }
    };
    
    function <void(int, int)> dfs2;
    dfs2 = [&](int u, int fa) -> void {
        f[u][0] = 1, f[u][1] = -1;
        for (auto v : G[u]) if (v != fa) {
            dfs2(v, u);
            if (f[v][0] + 1 > f[u][0]) {
                f[u][1] = f[u][0];
                f[u][0] = f[v][0] + 1;
            } else if(f[v][0] + 1 > f[u][1]) {
                f[u][1] = f[v][0] + 1;   
            }
        }       
    };
    
    function <void(int, int, int)> dfs3;
    dfs3 = [&](int u, int fa, int h) -> void {
        for (auto v : G[u]) if (v != fa) {
            g[v] = f[v][0];
            if (f[v][0] + 1 == f[u][0]) {
                g[v] = max(g[v], max(h, f[u][1]) + 1);
                dfs3(v, u, max(h, f[u][1]) + 1);
            } else {
                g[v] = max(g[v], max(h, f[u][0]) + 1);
                dfs3(v, u, max(h, f[u][0]) + 1);
            }
        }
    };
    
    int MAX = 0;
    for (int i = 1; i <= n; i++) if (a[i] == 1 && !vis[i]) {
        rt = i, m = 0;
        dfs(rt, 0, 1), dfs(rt, 0, 1);
        MAX = max(m, MAX);
        dfs2(i, 0);
        g[i] = f[i][0];
        dfs3(i, 0, 0);
    }
    ans = MP(1, MAX);
    vector <int> d(n + 1);
    for (int i = 1; i < n; i++) {
        int u = e[i].u, v = e[i].v;
        if (a[u] > a[v]) swap(u, v);
        if (a[u] == 1 && a[v] == 2) {
            if (g[u] == MAX) ++d[v];
            if (d[v] >= 2) {
                ans = MP(2, 2 * MAX + 1);
                break;
            }
        }
    }
    cout << ans.fi << '/' << ans.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
