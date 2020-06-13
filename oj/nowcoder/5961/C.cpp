/*
 * Author:  heyuhhh
 * Created Time:  2020/6/12 20:05:30
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

int n, q;
int x[N], y[N];

map <pii, int> mp, mp2;

void run() {
    cin >> n >> q;
    int nn = 0;
    for (int i = 1; i <= n; i++) {
        int xx, yy; cin >> xx >> yy;
        if (yy == 0 && xx == 0) {
            continue;
        }
        if (mp2[MP(xx, yy)]) {
            continue;
        }
        mp2[MP(xx, yy)] = 1;
        x[++nn] = xx, y[nn] = yy;
        int g = __gcd(x[nn], y[nn]);
        ++mp[MP(x[nn] / g, y[nn] / g)];
    }
    while (q--) {
        int tx, ty; cin >> tx >> ty;
        if (tx == 0 && ty == 0) {
            cout << 0 << '\n';
            continue;
        }
        int g = __gcd(tx, ty);
        if (mp.find(MP(tx / g, ty / g)) != mp.end()) {
            cout << 1 << '\n';
            continue;
        }
        if (nn <= 0 || sz(mp) == 1) {
            cout << -1 << '\n';
            continue;
        }
        if (nn == 1) {
            cout << -1 << '\n';
        } else if (nn == 2) {
            int ans = 3;
            for (int i = 1; i <= nn; i++) {
                if (1ll * x[3 - i] * (ty - y[i]) == 1ll * y[3 - i] * (tx - x[i])) {}
                else ans = 2;
            }
            cout << ans << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
