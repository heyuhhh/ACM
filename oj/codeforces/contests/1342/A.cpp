/*
 * Author:  heyuhhh
 * Created Time:  2020/4/26 22:36:10
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

int x, y, a, b;

void run() {
    cin >> x >> y >> a >> b;
    if(x > y) swap(x, y);
    ll ans = 0;
    if(1ll * x * y < 0) {
        ans += 1ll * (-x) * a + 1ll * y * a;
    } else if(1ll * x * y == 0) {
        ans += 1ll * y * a;   
    } else {
        int d = abs(x - y);
        ans += 1ll * d * a;
        if (x < 0) x += d;
        else y -= d;
        x = abs(x);
        ll res = min(1ll * x * b, 2ll * x * a);
        ans += res;
    }
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
