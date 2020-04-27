/*
 * Author:  heyuhhh
 * Created Time:  2020/4/26 23:01:13
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

int a, b, q;

void run() {
    cin >> a >> b >> q;
    vector <int> v;
    if (a > b) swap(a, b);
    int t;
    for (int i = 1; i <= a; i++) {
        if ((i * b) % a == 0) {
            t = i * b; break;
        }
    }
    auto calc = [&] (ll bd, int x) {
        return bd / t + (x <= (bd % t));
    };
    while (q--) {
        ll l, r; cin >> l >> r;
        ll ans = r - l + 1;
        for (int x = 0; x < b; x++) {
            ans -= calc(r, x) - calc(l - 1, x);
        }
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
