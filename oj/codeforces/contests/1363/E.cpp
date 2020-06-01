/*
 * Author:  heyuhhh
 * Created Time:  2020/5/31 23:20:34
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
const int N = 2e5 + 5;

int n;
vector <int> G[N];
int a[N], b[N], c[N];
int cnt[N][2];
ll ans;

void dfs(int u, int fa) {
    if (fa) a[u] = min(a[u], a[fa]);
    int f = -1;
    if (b[u] == 0 && c[u]) f = 0;
    if (b[u] && c[u] == 0) f = 1;
    int c0 = 0, c1 = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        cnt[u][0] += cnt[v][0];
        cnt[u][1] += cnt[v][1];
        if (cnt[v][0] > cnt[v][1]) c0 += cnt[v][0] - cnt[v][1];
        else c1 += cnt[v][1] - cnt[v][0];
    }
    if (f == 0) ++cnt[u][0], ++c0;
    if (f == 1) ++cnt[u][1], ++c1;
    ans += 2ll * a[u] * min(c0, c1);
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    if (cnt[1][0] != cnt[1][1]) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
