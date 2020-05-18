/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 18:38:57
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
const int N = 2e5 + 5;

int n;
int c[N], cnt[N];
vector <int> G[N];

int sz[N], sum[N];
ll ans[N];

ll f(int x) {
    return 1ll * x * (x + 1) / 2;   
}

void dfs(int u, int fa) {
    sz[u] = 1;
    int t = sum[c[u]];
    for (auto v : G[u]) if (v != fa) {
        sum[c[u]] = 0;
        dfs(v, u);
        sz[u] += sz[v];
        ans[c[u]] -= f(sz[v] - sum[c[u]]);
    }
    sum[c[u]] = t + sz[u];
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        ++cnt[c[i]];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] += f(n) - f(n - sum[i]);
    }
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
