/*
 * Author:  heyuhhh
 * Created Time:  2020/5/20 10:25:31
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

int primes[N], tot;
bool vis[N];
int fac[N], inv[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            primes[++tot] = i;
            if (tot >= 100000) break;
            for (ll j = 1ll * i * i; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void run() {
    int n, c, k; cin >> c >> n >> k;
    int p = primes[c];
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int d = C(i + p, p - 1);
        if (d == 1) ans = (ans + n) % MOD;
        else ans = (ans + 1ll * d * (1 - qpow(d, n) + MOD) % MOD * qpow(1 - d + MOD, MOD - 2) % MOD) % MOD;
    }
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
