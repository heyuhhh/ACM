/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 9:43:02
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
const int N = 1e6 + 5;

int n;
vector <int> G[N];
int bson[N], len[N], ans[N];
int *f[N], tmp[N], *id = tmp;

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
        f[bson[u]] = f[u] + 1;
        dfs2(bson[u], u);
        if (ans[u] != ans[bson[u]]) {
            ans[u] = ans[bson[u]] + 1;
        }
    }
    for (auto v : G[u]) {
        if (v == fa || v == bson[u]) continue;
        f[v] = id, id += len[v];
        dfs2(v, u);
        for (int i = 1; i <= len[v]; i++) {
            f[u][i] += f[v][i - 1];
            if (f[u][ans[u]] < f[u][i]) {
                ans[u] = i;
            } else if (f[u][ans[u]] == f[u][i]) {
                if (i < ans[u]) {
                    ans[u] = i;
                }
            }
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
    f[1] = id, id += len[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
