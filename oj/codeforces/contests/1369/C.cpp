/*
 * Author:  heyuhhh
 * Created Time:  2020/6/23 22:33:03
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
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> w(k);
    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }
    vector <int> p(n), p2(k);
    iota(all(p), 0);
    iota(all(p2), 0);
    sort(all(p), [&](int i, int j) {return a[i] > a[j];});
    sort(all(p2), [&](int i, int j) {return w[i] > w[j];});
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += a[p[i]];
    }
    int t = n - 1, l = 0;
    for (int i = 0; i < k; i++) {
        if (w[p2[i]] > 1) {
            --w[p2[i]];
            ans += a[p[t]];
            t -= w[p2[i]];
        } else {
            ans += a[p[l++]];
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
