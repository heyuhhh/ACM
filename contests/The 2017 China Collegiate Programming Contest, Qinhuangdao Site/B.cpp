/*
 * Author:  heyuhhh
 * Created Time:  2020/6/20 16:34:50
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
const int N = 2e6 + 5;

int n, MOD;
ll A, B, a[N], b[N];

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inv[N], cat[N];
void init(int n) {
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    cat[0] = cat[1] = 1;
    for (int i = 2; i <= n; i++) {
        cat[i] = 1ll * cat[i - 1] * (4 * i - 2) % MOD * inv[i + 1] % MOD;
    }
}

int dp[N];

void run() {
    cin >> n >> MOD >> b[0] >> A >> B;
    for (int i = 1; i <= 2 * n; i++) {
        b[i] = (1ll * A * b[i - 1] % MOD + B) % MOD;
        a[i] = (a[i - 1] + b[i] + 1) % MOD;
    }
    init(n);
    for (int i = 2; i <= 2 * n; i++) {
        dp[i] = (dp[i - 2] + 1ll * cat[i / 2 - 1] * cat[n - i / 2] % MOD) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i != 1) {
            ans = (ans + 1ll * a[i] * dp[i] % MOD) % MOD;
        }
        if (i != 2 * n) {
            ans = (ans - 1ll * a[i] * dp[2 * n - i + 1] % MOD) % MOD;
        }
    }
    ans = 1ll * ans * qpow(cat[n], MOD - 2) % MOD;
    if (ans < 0) ans += MOD;
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
