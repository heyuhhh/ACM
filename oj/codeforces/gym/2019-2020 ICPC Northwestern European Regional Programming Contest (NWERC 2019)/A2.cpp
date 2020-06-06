/*
 * Author:  heyuhhh
 * Created Time:  2020/5/28 16:33:31
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
const int N = 1e6 + 5;

int rk[N], point[N], lazy[N];
ll sum[N], num[N], pre[N];

void run() {
    int n, w; cin >> n >> w;
    for (int i = 0; i < N; i++) rk[i] = 1;
    for (int i = 0; i < w; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            int& p = point[x];
            num[p] += 1ll * (i - lazy[p]) * rk[p];
            lazy[p] = i;
            ++rk[p];
            sum[x] += num[p] - pre[x];
            
            ++p;
            num[p] += 1ll * (i - lazy[p]) * rk[p];
            lazy[p] = i;
            pre[x] = num[p];
        }
    }
    for (int i = 1; i <= n; i++) {
        int& p = point[i];
        num[p] += 1ll * (w - lazy[p]) * rk[p];
        lazy[p] = w;
        sum[i] += num[p] - pre[i];
        double ans = 1.0 * sum[i] / w;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
