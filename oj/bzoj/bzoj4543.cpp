/*
 * Author:  heyuhhh
 * Created Time:  2020/6/10 23:23:27
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

int n;
vector <int> G[N];

ll *f[N], *g[N], ans;
ll tmp[N << 2], *id = tmp;

int len[N], bson[N];
void dfs(int u, int fa) {
    int Max = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        if (len[v] > Max) {
            Max = len[v];
            bson[u] = v;
        }
    }
    len[u] = len[bson[u]] + 1;
}
void dfs2(int u, int fa) {
    f[u][0] = 1;
    if (bson[u]) {
        //处理重链
        int v = bson[u];
        f[v] = f[u] + 1;
        g[v] = g[u] - 1;
        dfs2(v, u);
    }
    ans += g[u][0];
    for (auto v : G[u]) {
        if (v == fa || v == bson[u]) continue;
        //分配空间
        f[v] = id, id += (len[v] << 1);
        g[v] = id, id += (len[v] << 1);
        dfs2(v, u);
        //从轻链转移
        for (int i = 0; i < len[v]; i++) {
            ans += f[v][i] * g[u][i + 1];
            if (i) {
                ans += f[u][i - 1] * g[v][i];
            }
        }
        for (int i = 1; i <= len[v]; i++) {
            if (i < len[v]) {
                g[u][i - 1] += g[v][i];
            }
            g[u][i] += f[u][i] * f[v][i - 1];
            f[u][i] += f[v][i - 1];
        }
    }
}
void run() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    f[1] = id, id += (len[1] << 1);
    g[1] = id, id += (len[1] << 1);
    dfs2(1, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
