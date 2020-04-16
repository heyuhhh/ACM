/*
 * Author:  heyuhhh
 * Created Time:  2020/4/15 22:36:55
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

int n, k;
vector <int> G[N];
int d[N], sz[N];

void dfs(int u, int fa) {
    d[u] = d[fa] + 1;
    sz[u] = 1;
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        sz[u] += sz[v];
    }   
}

void run() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0);
    vector <int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(d[i] - sz[i]);   
    }
    sort(all(v));
    reverse(all(v));
    ll ans = 0;
    for(int i = 0; i < k; i++) ans += v[i];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
