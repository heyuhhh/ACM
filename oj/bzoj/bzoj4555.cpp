/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 11:16:54
 * NTT+第二类斯特林数
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 4e5 + 5, M = 2e6 + 5, P = 998244353, G = 3, Gi = 332748118, MOD = 998244353;
int n, m, lim = 1, L, r[N];
ll a[N], b[N];//注意空间要开四倍
ll qpow(ll a, ll k) {
    ll ans = 1;
    while(k) {
        if(k & 1) ans = (ans * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return ans;
}
void NTT(ll *A, int type) {
    for(int i = 0; i < lim; i++)
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < lim; mid <<= 1) {
        ll Wn = qpow( type == 1 ? G : Gi , (P - 1) / (mid << 1)); //Wn = g ^ ((p - 1) / n)  (mod p)
        for(int j = 0; j < lim; j += (mid << 1)) {
            ll w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 int x = A[j + k], y = w * A[j + k + mid] % P;
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y + P) % P;
            }
        }
    }
}
void solve(ll *a, ll *b) {
    while(lim <= n + m) lim <<= 1, L++;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for(int i = m + 1; i < lim; i++) a[i] = 0;  //a,b need init
    for(int i = m + 1; i < lim; i++) b[i] = 0;
    NTT(a, 1); NTT(b, 1);
    for(int i = 0; i < lim; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1);
    ll inv = qpow(lim, P - 2);
    for(int i = 0; i < lim; i++) a[i] = a[i] * inv % P;
}

int fac[N], inv[N], f[N], two[N];

void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    for(int i = 0; i <= m; i++) {
        a[i] = (i & 1) ? MOD - inv[i] : inv[i];
        b[i] = 1ll * qpow(i, n + 1) * inv[i] % MOD;
    }
    solve(a, b);
    f[1] = n;
    for(int i = 2; i <= n; i++) f[i] = 1ll * (a[i] - f[i - 1] + MOD) % MOD * qpow(i - 1, MOD - 2) % MOD;
    two[0] = 1;
    for(int i = 1; i <= n; i++) two[i] = 1ll * two[i - 1] * 2 % MOD;
}

void run(){
    cin >> n; m = n + 1;
    init();
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = (ans + 1ll * two[i] * fac[i] % MOD * f[i] % MOD) % MOD;
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
