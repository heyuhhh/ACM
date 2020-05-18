/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 16:47:05
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
const int N = 3000 + 5, MOD = 998244353;

int n, s;
int a[N];
int dp[N][N], sum[N];

void run() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][a[i]] = i;
        for (int j = a[i]; j <= s; j++) {
            dp[i][j] += sum[j - a[i]];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
        for (int j = 0; j <= s; j++) {
            sum[j] += dp[i][j];
            if (sum[j] >= MOD) sum[j] -= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * dp[i][s] * (n - i + 1) % MOD;
        ans %= MOD;
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
