/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 8:57:22
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
int a[N], f[N], g[N];
vector <int> G[N];

void dfs(int u, int fa) {
    f[u] = a[u];
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        f[u] += max(f[v], 0);
    }
}

void dfs2(int u, int fa, int w) {
    g[u] = f[u] + max(0, w);
    for(auto v : G[u]) if(v != fa) {
        dfs2(v, u, g[u] - max(0, f[v]));
    }
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) --a[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << g[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
