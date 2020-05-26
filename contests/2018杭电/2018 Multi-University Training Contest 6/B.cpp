/*
 * Author:  heyuhhh
 * Created Time:  2020/5/15 20:46:04
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
const int N = 2e6 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;   
}

int fib[N], fac[N], inv[N];
void init() {
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % (MOD - 1);   
    }
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;   
}

int n, k;
int f[N];

void run() {
    cin >> n >> k;
    int tot = C(n + k - 1, k - 1);
    int ans = 0;
    vector <int> d;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            f[i] = C(n / i + k - 1, k - 1);
        }
    }
    for (int i = sz(d) - 1; i >= 0; i--) {
        for (int j = i + 1; j < sz(d); j++) {
            if (d[j] % d[i] == 0) {
                f[d[i]] = (f[d[i]] - f[d[j]] + MOD) % MOD;
            }
        }
    }
    for (auto it : d) {
        ans = (ans + 1ll * f[it] * (qpow(2, fib[it] % (MOD - 1)) - 1 + MOD) % MOD) % MOD;
    }
    ans = 1ll * ans * qpow(tot, MOD - 2) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}
