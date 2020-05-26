/*
 * Author:  heyuhhh
 * Created Time:  2020/5/22 20:20:45
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
const int MOD = 998244353;
const int N = 8000 + 5; 

int n;
int c[N];
int f[N];

void run() {
    cin >> n;
    set <int> s;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ++c[x];
    }
    vector <int> b;
    for (int i = 1; i <= n; i++) if (c[i]) {
        b.push_back(c[i]);
    }
    f[0] = 1;
    f[1] = b[0];
    for (int i = 1; i < sz(b); i++) {
        for (int j = i + 1; j >= 0; j--) {
           if (j) f[j] = (f[j] + 1ll * f[j - 1] * b[i] % MOD) % MOD;
        }
    }
    vector <int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    int ans = fac[n];
    for (int i = 1; i <= n; i++) {
        int t = 1ll * f[i] * fac[n - i] % MOD;
        if (i & 1) t = MOD - t;
        ans = (ans + t) % MOD;
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
