/*
 * Author:  heyuhhh
 * Created Time:  2020/5/26 23:50:38
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
const int N = 5e5 + 5;

int n;
int a[N];
ll sum[N];

void run() {
    cin >> n;
    int k = (n + 1) / 2;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int x; cin >> x;
    auto calc = [&] (ll t) {
        return sum[k] - sum[t - 1];  
    };
    ll Min = 1e18;
    int ans = -1;
    for (int i = 1; i <= k; i++) {
        ll res = calc(i) + 1ll * (n / 2) * x;
        if (Min == 1e18) {
            Min = res;
        } else {
            Min -= x;
            Min = min(Min, res);           
        }   
        if (Min > 0) ans = n - i + 1;
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
