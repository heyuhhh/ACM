/*
 * Author:  heyuhhh
 * Created Time:  2020/5/6 22:41:30
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
const int N = 100000 + 5;

ll f[N], k;

void init() {
    for (int i = 1;; i++) {
        f[i] = f[i - 1] + 2 + 3 * (i - 1);
        if (f[i] >= (ll)1e9) {
            k = i; break;   
        }
    }
}

void run() {
    int n; cin >> n;
    int ans = 0;
    dbg(k);
    while(1) {
        int t = upper_bound(f + 1, f + k + 1, n) - f - 1;
        if (f[t] == n) {
            ++ans; break;
        }
        if (t <= 0) break;
        n -= f[t];
        ++ans;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    dbg(k);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
