/*
 * Author:  heyuhhh
 * Created Time:  2020/6/5 20:43:13
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

//p[n]=p[n-1]+p[n-2]-p[n-5]-p[n-7]...
//广义五边形数 P[i]
void init_p(int n, int* p) {
    for (int i = 0; i <= n; i++) {
        p[i] = 0;
    }
    auto P = [&] (int i) {
        return MP(i * (3 * i - 1) / 2, i * (3 * i + 1) / 2);
    };
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;; j++) {
            pii val = P(j);
            if (val.fi > i) break;
            int t = p[i - val.fi];
            if (val.se <= i) {
                t += p[i - val.se];
                if (t >= MOD) t -= MOD;
            }
            if (!(j & 1)) p[i] = (p[i] + MOD - t) % MOD;
            else p[i] = (p[i] + t) % MOD;
        }
    }
}

int n, m, _;
int f[N];

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;   
}

void dec(int& x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

void run() {
    init_p(2 * n, f);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ll t = 1ll * i * (x + 1);
        if (t > 2 * n) continue;
        for (int j = 2 * n; j >= t; j--) {
            dec(f[j], f[j - t]);
        }
    }
    int sum = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        add(sum, f[i - n - 1]);
        dec(f[i], sum);
    }
    cout << "Case #" << ++_ << ": ";
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        add(ans, f[2 * n - x]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n >> m) run();
    return 0;
}
