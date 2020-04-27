/*
 * Author:  heyuhhh
 * Created Time:  2020/4/27 17:26:05
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
const int N = 1e5 + 5;

void run() {
    int a, b, q;
    cin >> a >> b >> q;
    if (a > b) swap(a, b);
    int g = __gcd(a, b);
    a /= g;
    auto calc = [&] (ll x) {
        ll now = x / b;
        ll res = (now / a + 1) * b;
        if (now % a == 0) {
            (res -= b) += x % b + 1;   
        }
        return res;
    };
    while (q--) {
        ll l, r; cin >> l >> r;
        ll ans = r - l + 1;
        ans -= calc(r) - calc(l - 1);
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
