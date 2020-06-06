/*
 * Author:  heyuhhh
 * Created Time:  2020/6/2 14:23:52
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
vector <pii> G[N];
bool Find;
bool vis[N], chk[N];
int in[N], out[N];

void dfs(int u) {
    vis[u] = true;
    for (auto it : G[u]) {
        int v = it.fi, id = it.se;
        if (vis[v]) {
            if (!Find) {
                Find = true;
                chk[id] = true;
                ++out[u], ++in[v];
            }
        } else {
            chk[id] = true;
            ++out[u], ++in[v];
            dfs(v); 
        }
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        vis[i] = false;
        in[i] = out[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        chk[i] = false;
    }
    vector <pii> edges;
    edges.push_back(MP(0, 0));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(MP(v, i));
        edges.push_back(MP(u, v));
    }
    Find = false;
    dfs(1);
    for (int i = 1; i <= m; i++) {
        int u = edges[i].fi, v = edges[i].se;
        if (!chk[i] && (out[u] == 0 || in[v] == 0)) {
            chk[i] = true;
            ++out[u], ++in[v];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (!chk[i]) {
            ++cnt;
            cout << edges[i].fi << ' ' << edges[i].se << '\n';
        }
        if (cnt == m - 2 * n) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
