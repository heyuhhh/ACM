/*
 * Author:  heyuhhh
 * Created Time:  2020/6/26 9:16:53
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

ll calc(int n, int k, int c9, int r) {
    int res = 0;
    for (int i = 0; i <= k; i++) {
        if (i + r < 10) {
            res += i + r + 9 * c9;
        } else {
            res += i + r - 9;
        }
    }
    int need = n - res;
    if (need % (k + 1) || need < 0) {
        return 1e18;
    }
    need /= k + 1;
    ll ans = 0;
    if (need < 9) {
        ans = need;
    } else {
        need -= 8;
        int t = need % 9;
        ans = t;
        for (int i = 1; i <= need / 9; i++) {
            ans = ans * 10 + 9;
        }
        ans = ans * 10 + 8;
    }
    for (int i = 1; i <= c9; i++) {
        ans = ans * 10 + 9;
    }
    ans = ans * 10 + r;
    return ans;
}

void run() {
    int n, k; cin >> n >> k;
    ll ans = 1e18;
    for (int c9 = 0; c9 <= 16; c9++) {
        for (int r = 0; r < 10; r++) {
            ans = min(ans, calc(n, k, c9, r));
        }
    }
    if (ans == 1e18) ans = -1;
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
