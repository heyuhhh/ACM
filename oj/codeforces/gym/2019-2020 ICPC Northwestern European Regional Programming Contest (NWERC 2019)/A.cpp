/*
 * Author:  heyuhhh
 * Created Time:  2020/5/28 15:51:27
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

int cnt[N];
ll lazy[N], sum[N], pre[N];
int point[N];

void run() {
    int n, w; cin >> n >> w;
    cnt[0] = n;
    lazy[0] = w;
    for (int i = 0; i < w; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            int& p = point[x];
            sum[x] += lazy[p] - 1ll * cnt[p + 1] * (w - i) - pre[x];
            lazy[p] += w - i;
            
            --cnt[p];
            ++cnt[++p];
            pre[x] = lazy[p];
        }
    }
    for (int i = 1; i <= n; i++) {
        int p = point[i];
        sum[i] += lazy[p] - pre[i];
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
