/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 11:11:17
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

int n;
int a[N];
ll dp[N], pre[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    pre[1] = a[1];
    for (int i = 3; i <= n; i++) {
        pre[i] = pre[i - 2] + a[i];
    }
    for (int i = 2; i <= n; i += 2) {
        dp[i] = max(dp[i - 2] + a[i], pre[i - 1]);
    }
    reverse(a + 1, a + n + 1);
    ll ans = -1e18;
    if (n % 2 == 0) {
        ans = max(pre[n - 1], dp[n]);
    } else {
        ll now = 0;
        int cnt = 0;
        for (int i = 1; i <= n && cnt < n / 2; i += 2, ++cnt) {
            ans = max(ans, now + dp[n - i]);
            ans = max(ans, now + pre[n - i - 1]);
            now += a[i];
        }
        ans = max(ans, now);
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
