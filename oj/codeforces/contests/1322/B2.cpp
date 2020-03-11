/*
 * Author:  heyuhhh
 * Created Time:  2020/3/8 10:52:04
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
const int N = 4e5 + 5, M = 26;

int n;
int a[N], b[N];
int sum[1 << M];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int high = 2, k = 0; high < 1 << M; high <<= 1, ++k) {
        for(int i = 0; i < high; i++) sum[i] = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] >> k & 1) b[i] |= (1 << k);
            ++sum[b[i]];
        }
        for(int i = 1; i < high; i++) sum[i] += sum[i - 1];
        ll cnt = 0;
        int T = 1 << k;
        for(int i = 1; i <= n; i++) {
            cnt += sum[2 * T - 1 - b[i]];
            if(T - 1 - b[i] >= 0) cnt -= sum[T - 1 - b[i]];
            cnt += sum[4 * T - 1 - b[i]] - sum[3 * T - 1 - b[i]];
            if((b[i] << 1) >= T && (b[i] << 1) < 2 * T) --cnt;
            if((b[i] << 1) >= 3 * T && (b[i] << 1) < 4 * T) --cnt;
        }
        cnt >>= 1;
        if(cnt & 1) ans += 1 << k;
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
