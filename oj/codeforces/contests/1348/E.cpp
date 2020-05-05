/*
 * Author:  heyuhhh
 * Created Time:  2020/5/4 15:43:15
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
const int N = 500 + 5;

int n, k;
pair <ll, int> dp[N][N];

void run() {
    cin >> n >> k;
    memset(dp, -INF, sizeof(dp));
    dp[0][0] = MP(0, 0);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;   
        for (int j = 0; j < k; j++) if (dp[i][j].fi >= 0) { 
            for (int t = 0; t < k && t <= a; t++) {
                ll val = dp[i][j].fi;
                int p = j + t;
                val += p / k;
                p %= k;
                int all = a + b - t;
                val += all / k;
                all %= k;
                int r = min(b, all) + dp[i][j].se;
                val += r / k;
                r %= k;
                if (val > dp[i + 1][p].fi) {
                    dp[i + 1][p] = MP(val, r);   
                } else if (val == dp[i + 1][p].fi) {
                    dp[i + 1][p].se = max(dp[i + 1][p].se, r);   
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans = max(ans, dp[n][i].fi);
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
