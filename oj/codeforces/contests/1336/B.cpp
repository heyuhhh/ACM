/*
 * Author:  heyuhhh
 * Created Time:  2020/4/15 22:47:16
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
//#define Local
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

int na, nb, nc;

ll a[N], b[N], c[N];

ll calc(int x, int y, int z) {
    if(x && y && z && x <= na && y <= nb && z <= nc)
        return (a[x] - b[y]) * (a[x] - b[y]) + (a[x] - c[z]) * (a[x] - c[z]) + (b[y] - c[z]) * (b[y] - c[z]);
    return 8e18;
}

ll calc_a(int y, int z) {
    int t = lower_bound(a + 1, a + na + 1, b[y]) - a;
    ll res = 9e18;
    res = min(res, calc(t, y, z));
    res = min(res, calc(t - 1, y, z));
    t = lower_bound(a + 1, a + na + 1, c[z]) - a;
    res = min(res, calc(t, y, z));
    res = min(res, calc(t - 1, y, z));
    return res;
}

ll calc_c(int x, int y) {
    int t = lower_bound(c + 1, c + nc + 1, b[y]) - c;
    ll res = 9e18;
    res = min(res, calc(x, y, t));
    dbg(x, y, t, res);
    res = min(res, calc(x, y, t - 1));
    t = lower_bound(c + 1, c + nc + 1, a[x]) - c;
    res = min(res, calc(x, y, t));
    res = min(res, calc(x, y, t - 1));
    return res;
}

ll calc_b(int x, int z) {
    int t = lower_bound(b + 1, b + nb + 1, c[z]) - b;
    ll res = 9e18;
    res = min(res, calc(x, t, z));
    res = min(res, calc(x, t - 1, z));
    t = lower_bound(b + 1, b + nb + 1, a[x]) - b;
    res = min(res, calc(x, t, z));
    res = min(res, calc(x, t - 1, z));
    return res;   
}

void run() {
    cin >> na >> nb >> nc;
    for(int i = 1; i <= na; i++) cin >> a[i];
    for(int i = 1; i <= nb; i++) cin >> b[i];
    for(int i = 1; i <= nc; i++) cin >> c[i];
    sort(a + 1, a + na + 1);
    sort(b + 1, b + nb + 1);
    sort(c + 1, c + nc + 1);
    ll ans = 9e18;
    for(int i = 1, t; i <= na; i++) {
        t = lower_bound(b + 1, b + nb + 1, a[i]) - b;
        if(t <= nb) ans = min(ans, calc_c(i, t));
        if(t > 1) ans = min(ans, calc_c(i, t - 1));
        t = lower_bound(c + 1, c + nc + 1, a[i]) - c;
        if(t <= nc) ans = min(ans, calc_b(i, t));
        if(t > 1) ans = min(ans, calc_b(i, t - 1));
    }
    for(int i = 1, t; i <= nb; i++) {
        t = lower_bound(a + 1, a + na + 1, b[i]) - a;
        ans = min(ans, calc_c(t, i));
        ans = min(ans, calc_c(t - 1, i));
        t = lower_bound(c + 1, c + nc + 1, b[i]) - c;
        ans = min(ans, calc_a(i, t));
        ans = min(ans, calc_a(i, t - 1));
    }
    for(int i = 1, t; i <= nc; i++) {
        t = lower_bound(b + 1, b + nb + 1, c[i]) - b;
        ans = min(ans, calc_a(t, i));
        ans = min(ans, calc_c(t - 1, i));
        t = lower_bound(a + 1, a + na + 1, c[i]) - a;
        ans = min(ans, calc_b(t, i));
        ans = min(ans, calc_b(t - 1, i));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
