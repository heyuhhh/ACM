/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 22:17:52
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
    int n; cin >> n;
    vector <ll> a(n);
    vector <int> lg(N);
    lg[2] = 1;
    for (int i = 3; i < N; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    int t = 1;
    ll ans = 0, Max = a[1];
    while (1) {
        while (t + 1 < n && a[t + 1] == a[t]) ++t;
        if (t == n - 1) {
            int k = lg[t];
            ll D = a[0] - Max;
            ll A = D / k;
            Max += A * k;
            ans += 1ll * (k + 1) * A;
            ans += D % k;
            break;           
        } else {
            ll d = a[t] - a[t + 1];
            int k = lg[t]; //+=k
            if (1ll * k * d + Max <= a[0]) {
                Max += 1ll * k * d;
                ans += 1ll * (k + 1) * d;
            } else {
                ll D = a[0] - Max;
                ll A = D / k;
                Max += A * k;
                ans += 1ll * (k + 1) * A;
                ans += D % k;
                break;
            }
        }
        ++t;
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
