/*
 * Author:  heyuhhh
 * Created Time:  2020/5/28 22:56:00
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
const double eps = 1e-6;

void run() {
    int h, c, t; cin >> h >> c >> t;
    if (h + c >= 2 * t) {
        cout << 2 << '\n';
        return;
    }
    auto f = [&] (ll x, ll y) {
        return fabs((double)t - 1.0 * (x * h + y * c) / (x + y));
    };
    ll l = 0, r = INF, lmid, rmid;
    while (l < r) {
        lmid = l + ((r - l) / 3);   
        rmid = r - ((r - l) / 3);
        if (f(lmid + 1, lmid) <= f(rmid + 1, rmid)) {
            r = rmid - 1;
        } else {
            l = lmid + 1;
        }
    }   
    ll ans = 2 * l + 1;
    //if (l > 10000000) {
        //ans = ll(1.0 * (h - t) / (2 * t - h - c) + 0.5);
        //ans = 2ll * ans + 1;
    //}
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
