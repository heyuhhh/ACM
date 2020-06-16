/*
 * Author:  heyuhhh
 * Created Time:  2020/6/13 17:14:24
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
    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <ll> a(40);
    ll all = 0;
    for (int i = 0; i < 40; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] >> i & 1) ++x;
            else ++y;
        }
        a[i] = (1ll << i) * (y - x);
        all += (1ll << i) * x;
    }
    int q; cin >> q;
    while (q--) {
        ll m; cin >> m;
        ll k = 0;
        ll now = all;
        for (int i = 0; i < 40; i++) {
            if (a[i] < 0) {
                now += a[i];
                k += (1ll << i);
            }
        }
        if (now > m) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 60; i > 40; i--) {
            if ((1ll << i) > (m - now) / n) continue;
            now += (1ll << i) * n;
            k += (1ll << i);
        }
        for (int i = 39; i >= 0; i--) {
            if (a[i] >= 0 && now + a[i] <= m) {
                now += a[i];
                k += (1ll << i);
            }
        }
        if (now > m) k = -1;
        cout << k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
