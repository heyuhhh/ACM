/*
 * Author:  heyuhhh
 * Created Time:  2020/4/1 20:29:05
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
const int N = 3e5 + 5, MOD = 998244353;

int n;
vector <int> G[N];
int dp[N][3];

void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        dp[u][0] = 1ll * dp[u][0] * (2ll * dp[v][0] + 2 * dp[v][1] - dp[v][2] + MOD) % MOD;
        dp[u][1] = 1ll * dp[u][1] * (2ll * dp[v][0] + dp[v][1] - dp[v][2] + MOD) % MOD;
        dp[u][2] = 1ll * dp[u][2] * (1ll * dp[v][0] + dp[v][1] - dp[v][2] + MOD) % MOD;
    }   
}

void run() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0);
    int ans = ((ll)dp[1][0] + dp[1][1] - dp[1][2] + MOD - 1) % MOD;
    cout << ans << '\n';
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
