/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 17:42:54
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
const int N = 2e5 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

int n;
vector <int> G[N];
int sz[N], f[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int fa) {
    for (auto v : G[u]) if (v != fa) {
        f[v] = 1ll * f[u] * sz[v] % MOD * qpow(n - sz[v], MOD - 2) % MOD;
        dfs2(v, u);
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
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        f[1] = 1ll * f[1] * i % MOD;
    }
    for (int i = 1; i <= n; i++) {
        f[1] = 1ll * f[1] * qpow(sz[i], MOD - 2) % MOD;
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << f[i] << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
