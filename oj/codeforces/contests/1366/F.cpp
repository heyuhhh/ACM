/*
 * Author:  heyuhhh
 * Created Time:  2020/6/17 18:34:51
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
const int N = 2000 + 5, MOD = 1e9 + 7;

int n, m;
ll q;
int u[N], v[N], w[N];

ll dp[2][N], b[N];
int ans;

void run() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    memset(dp, -INF, sizeof(dp));
    memset(b, -INF, sizeof(b));
    dp[0][1] = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i & 1][u[j]] = max(dp[i & 1][u[j]], dp[(i - 1) & 1][v[j]] + w[j]);
            dp[i & 1][v[j]] = max(dp[i & 1][v[j]], dp[(i - 1) & 1][u[j]] + w[j]);
        }
        for (int j = 1; j <= m; j++) {
            b[j] = max(b[j], max(dp[i & 1][u[j]], dp[i & 1][v[j]]) - 1ll * i * w[j]);
        }
        ans = (ans + *max_element(dp[i & 1] + 1, dp[i & 1] + n + 1)) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        ll l = n, r = q;
        for (int j = 1; l <= r && j <= m; j++) if (i != j) {
            ll K = w[i] - w[j];
            ll B = b[j] - b[i];
            if (K > 0) {
                l = max(l, B / K + 1);
            } else if (K < 0) {
                r = min(r, B / K);
            } else {
                if (!(B < 0 || (B == 0 && j > i))) {
                    r = -1;
                }
            }
        }
        if (l <= r) {
            ans = ((ll)ans + (l + r) * (r - l + 1) / 2 % MOD * w[i] % MOD + b[i] * (r - l + 1) % MOD) % MOD;
            if (ans < 0) ans += MOD;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
