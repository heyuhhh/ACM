/*
 * Author:  heyuhhh
 * Created Time:  2020/5/26 23:06:52
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
const int N = 1e5 + 5;

void run() {
    ll n, x; cin >> n >> x;
    vector <ll> a(n << 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    a.pb(a[0]);
    auto calc = [&] (int l, int r) {
        return 1ll * (r - l + 1) * (l + r) / 2;  
    };
    vector <ll> sum(n << 1), sum2(n << 1);
    for (int i = 0; i < n << 1; i++) {
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i < n << 1; i++) {
        if (i == 0) sum2[i] = calc(1, a[i]);
        else sum2[i] = sum2[i - 1] + calc(1, a[i]);
    }
    auto chk = [&] (int i, int j) {
        return sum[j] - (i == 0 ? 0 : sum[i - 1]);
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = 2 * n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (chk(i, mid) <= x) l = mid + 1;
            else r = mid;
        }
        int j = l - 1;
        ll s = x - chk(i, j);
        if (s > 0) {
            ll k = min(a[i] - 1, a[j + 1] - s);
            ans = max(ans, calc(1 + k, a[i]) + calc(1, s + k) + sum2[j] - sum2[i]);
        } else if (s == 0) {
            ans = max(ans, sum2[j] - (i == 0 ? 0 : sum2[i - 1]));   
        } else {
            ans = max(ans, calc(a[i] - x + 1, a[i]));
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
