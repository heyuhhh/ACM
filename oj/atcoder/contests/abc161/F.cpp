/*
 * Author:  heyuhhh
 * Created Time:  2020/5/13 21:33:20
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
    ll n; cin >> n;
    vector <ll> d;
    for (int i = 2; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) d.push_back(n / i);
        }
    }
    d.push_back(n);
    sort(all(d));
    --n;
    vector <ll> d2;
    for (int i = 2; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            d2.push_back(i);
            if (n / i != i) d2.push_back(n / i);
        }
    }
    if (n != 1) d2.push_back(n);
    ll ans = sz(d2);
    ++n;
    for (auto x : d) {
        ll now = n;
        while (now >= x && now % x == 0) {
            now /= x;
        }
        now %= x;
        if (now == 1) ++ans;
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
