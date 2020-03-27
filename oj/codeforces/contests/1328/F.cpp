/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 9:35:07
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

int a[N];
ll pre[N], suf[N];

void run() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];   
    }
    for(int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];   
    }
    ll ans = 1e18;
    for(int i = 1; i <= n; i++) {
        int v = a[i];
        int p1 = lower_bound(a + 1, a + n + 1, v) - a - 1;
        int p2 = upper_bound(a + 1, a + n + 1, v) - a;
        int t = p2 - p1 - 1;
        ll tsum = suf[p2] - 1ll * (n - p2 + 1) * (v + 1);
        ll tsum2 = 1ll * p1 * (v - 1) - pre[p1];
        int d = k - t;
        if(d <= 0) {ans = 0; break;}
        if(n - p1 >= k) ans = min(ans, tsum + d);
        if(p2 - 1 >= k) ans = min(ans, tsum2 + d);
        ans = min(ans, tsum + tsum2 + d);
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
