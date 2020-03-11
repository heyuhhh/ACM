/*
 * Author:  heyuhhh
 * Created Time:  2020/3/3 19:59:10
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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

int n, k;
int a[N], b[N];
int fac[N], inv[N];

void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

ll c[N << 2], d[N << 2];//注意空间要开四倍
namespace ntt{
    const int P = 998244353, G = 3, Gi = 332748118;
    int n, m, r[N << 2];
    void NTT(ll *A, int type, int n) {
        for(int i = 0; i < n; i++)
            if(i < r[i]) swap(A[i], A[r[i]]);
        for(int mid = 1; mid < n; mid <<= 1) {
            ll Wn = qpow( type == 1 ? G : Gi , (P - 1) / (mid << 1)); //Wn = g ^ ((p - 1) / n)  (mod p)
            for(int j = 0; j < n; j += (mid << 1)) {
                ll w = 1;
                for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                     int x = A[j + k], y = w * A[j + k + mid] % P;
                     A[j + k] = (x + y) % P,
                     A[j + k + mid] = (x - y + P) % P;
                }
            }
        }
        if(type == -1) {
            ll inv = qpow(n, P - 2);
            for(int i = 0; i < n; i++) A[i] = A[i] * inv % P;   
        }
    }
    void solve(ll *a, ll *b) {
        int lim = 1, L = 0;
        while(lim <= n + m) lim <<= 1, L++;
        for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
        for(int i = n + 1; i < lim; i++) a[i] = 0;  //a,b need init
        for(int i = m + 1; i < lim; i++) b[i] = 0;
        NTT(a, 1, lim); NTT(b, 1, lim);
        for(int i = 0; i < lim; i++) a[i] = a[i] * b[i] % P;
        NTT(a, -1, lim);
    }   
};

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) b[i] = a[i % n + 1];
    int ans = 1, t = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == b[i]) {
            ans = 1ll * ans * k % MOD;
        } else ++t;
    }
    for(int i = 0; i <= t; i++) c[i] = d[i] = inv[i];
    ntt::n = ntt::m = t;
    ntt::solve(c, d);
    int tot = 0;
    for(int x = 1; x <= t; x++) {
        int res = 1ll * qpow(k - 2, t - x) * fac[t] % MOD * inv[t - x] % MOD;
        if(x % 2 == 0) c[x] -= 1ll * inv[(x + 1) / 2] % MOD * inv[(x + 1) / 2] % MOD;
        if(c[x] < 0) c[x] += MOD;
        c[x] = 1ll * c[x] * inv[2] % MOD;
        res = 1ll * res * c[x] % MOD;
        tot = (tot + res) % MOD;
    }
    ans = 1ll * ans * tot % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
