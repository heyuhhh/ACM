/*
 * Author:  heyuhhh
 * Created Time:  2020/6/25 23:02:08
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
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
    }
    vector <int> b;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            b.push_back(-a[i] + a[i + 1]);
        }
    }
    vector <int> c;
    for (int i = 0; i < n; i += 2) {
        if (i - 1 >= 0) {
            c.push_back(-a[i] + a[i - 1]);
        }
    }
    auto gao = [&] (vector <int>& v) {
        int sz = sz(v);
        if (sz == 0) return 0ll;
        vector <ll> dp(sz);
        dp[0] = max(0, v[0]);
        for (int i = 1; i < sz(v); i++) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + v[i];
            } else {
                dp[i] = v[i];
            }
        }
        return *max_element(all(dp));
    };
    ll res = max(gao(b), gao(c));
    ans += res;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
