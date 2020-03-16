/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 9:23:53
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
const int N = 2000 + 5;

int n, h, l, r;
int dp[N][N];
int a[N];

void run() {
    cin >> n >> h >> l >> r;
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto chk = [&] (int t) {
        if(l <= t && t <= r) return 1;
        return 0;  
    };
    memset(dp, -INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h; j++) {
            int t = (j + a[i + 1]) % h, t2 = (j + a[i + 1] - 1) % h;
            dp[i + 1][t] = max(dp[i + 1][t], dp[i][j] + chk(t));
            dp[i + 1][t2] = max(dp[i + 1][t2], dp[i][j] + chk(t2));
        }   
    }
    int ans = 0;
    for(int i = 0; i < h; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);  
    run();
    return 0;
}
