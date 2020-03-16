/*
 * Author:  heyuhhh
 * Created Time:  2020/3/15 21:07:21
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

int n, m, k, q;
int l[N], r[N];
int b[N];

ll dp[N][2];

void run() {
    cin >> n >> m >> k >> q;
    l[1] = r[1] = 1;
    for(int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        if(!l[x]) {
            l[x] = r[x] = y;
        } else {
            l[x] = min(l[x], y);
            r[x] = max(r[x], y);
        }
    }
    for(int i = 1; i <= q; i++) cin >> b[i];
    sort(b + 1, b + q + 1);
    auto calc = [&] (int p, int se, int fi) {
        int p1 = lower_bound(b + 1, b + q + 1, p) - b;
        int p2 = p1 - 1;
        int ans = INF;
        if(p1 <= q) {
            ans = abs(p - b[p1]) + abs(b[p1] - fi) + abs(fi - se);
        }
        if(p2) {
            ans = min(ans, abs(p - b[p2]) + abs(b[p2] - fi) + abs(fi - se));   
        }
        return ans;
    };
    dp[1][0] = r[1] - 1 + r[1] - l[1];
    dp[1][1] = r[1] - 1;
    while(!l[n]) --n;
    for(int i = 2; i <= n; i++) {
        if(!l[i]) {
            l[i] = l[i - 1], r[i] = r[i - 1];
            dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;   
        } else {
            dp[i][0] = min(dp[i - 1][0] + calc(l[i - 1], l[i], r[i]), dp[i - 1][1] + calc(r[i - 1], l[i], r[i])) + 1;
            dp[i][1] = min(dp[i - 1][0] + calc(l[i - 1], r[i], l[i]), dp[i - 1][1] + calc(r[i - 1], r[i], l[i])) + 1;
        }
    }
    ll ans = min(dp[n][0], dp[n][1]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
