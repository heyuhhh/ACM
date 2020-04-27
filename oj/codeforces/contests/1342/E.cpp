/*
 * Author:  heyuhhh
 * Created Time:  2020/4/27 0:38:49
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
const int N = 2e5 + 5, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll n, k;
int fac[N], inv[N];

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void run() {
    cin >> n >> k;
    if (k >= n) {
        cout << 0 << '\n';
        return;
    }
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        int res = 1ll * C(n - k, i) * qpow(n - k - i, n) % MOD;
        if(i & 1) res = MOD - res;
        ans = (ans + res) % MOD;
    }
    ans = 1ll * ans * C(n, n - k) % MOD;
    if(k) (ans <<= 1) %= MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
