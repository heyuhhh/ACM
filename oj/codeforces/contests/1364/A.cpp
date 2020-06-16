/*
 * Author:  heyuhhh
 * Created Time:  2020/6/13 23:07:56
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
    int n, x; cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= x;
    }
    vector <int> sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % x;
    }
    int last = -1;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (sum[i] != 0) {
            ans = i + 1;
        } else if (last != -1) {
            ans = max(ans, i - last);
        }
        if (sum[i] > 0 && last == -1) {
            last = i;
        }
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
