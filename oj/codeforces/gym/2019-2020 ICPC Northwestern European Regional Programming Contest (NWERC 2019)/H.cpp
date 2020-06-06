/*
 * Author:  heyuhhh
 * Created Time:  2020/5/28 18:37:16
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
const double eps = 1e-7;

int n, k;
int h[N];
pii a[N];

void run() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        cin >> h[i];
    }

    int Min;
    auto get = [&] (int i, int g) {
        long double k = h[i + 1] - h[i];
        long double l = i, r = i + 1, x;
        for (int j = 0; j < 50; j++) {
            x = (l + r) / 2;
            long double y = h[i] + k * (x - i);
            if (y - h[Min] >= (long double)g * (x - Min)) {
                l = x;
            } else {
                r = x;
            }
        }       
        return l;
    };
    
    auto get2 = [&] (int i, int g) {
        long double k = h[Min] - h[Min - 1];
        long double l = Min - 1, r = Min, x;
        for (int j = 0; j < 50; j++) {
            x = (l + r) / 2;
            long double y = h[Min - 1] + k * (x - Min + 1);
            if (h[i] - y >= (long double)g * ((long double)i - x)) {
                r = x;
            } else {
                l = x;
            }
        }       
        return l;
    };   
    
    auto calc = [&] (int g) {
        long double ans = -1;
        for (int i = 0; i <= n; i++) {
            a[i].fi = h[i] - g * i;
            a[i].se = i;
        }
        sort(a, a + n + 1, [&](pii A, pii B) {
            if (A.fi != B.fi) return A.fi < B.fi;
            return A.se < B.se;
        });
        
        Min = INF;
        for (int i = 0; i <= n; i++) {
            Min = min(Min, a[i].se);
            if (a[i].se > Min) {
                if (a[i].se != n) {
                    long double can = get(a[i].se, g);
                    ans = max(ans, can - (long double)Min);
                }   
                if (Min) {
                    long double can = get2(a[i].se, g);
                    ans = max(ans, (long double)a[i].se - can);
                }
                ans = max(ans, (long double)a[i].se - Min);
            }
        }       
        if (ans <= eps) ans = -1;
        return ans;
    };
    while (k--) {
        double t; cin >> t;
        int g = int(t * 10 + 0.5);
        long double ans = calc(g);
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
