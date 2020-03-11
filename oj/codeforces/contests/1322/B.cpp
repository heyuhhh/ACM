/*
 * Author:  heyuhhh
 * Created Time:  2020/3/7 20:20:27
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
const int N = 4e5 + 5;

int n;
int a[N], b[N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int k = 24; k >= 0; k--) {
        int T = 1 << k, cnt = 0;
        for(int i = 1; i <= n; i++) b[i] = a[i] % (T << 1);
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++) {
            int p1 = lower_bound(b + i + 1, b + n + 1, T - b[i]) - b;
            int p2 = lower_bound(b + i + 1, b + n + 1, 2 * T - b[i]) - b;
            cnt += p2 - p1;
            p1 = lower_bound(b + i + 1, b + n + 1, 3 * T - b[i]) - b;
            p2 = lower_bound(b + i + 1, b + n + 1, 4 * T - b[i]) - b;
            cnt += p2 - p1;
        }
        if(cnt & 1) ans += (1 << k);
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
