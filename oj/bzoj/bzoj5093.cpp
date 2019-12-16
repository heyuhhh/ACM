/*
 * Author:  heyuhhh
 * Created Time:  2019/12/11 22:57:14
 * 推式子后NTT预处理第二类斯特林数
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
const int N = 2e5 + 5, MOD = 998244353;

int n, k, m;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}
const int P = 998244353, G = 3, Gi = 332748118;
int lim = 1, L, r[N * 4];
ll a[N * 4], b[N * 4];
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
    while(lim <= m + m) lim <<= 1, L++;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for(int i = n + 1; i < lim; i++) a[i] = 0;  //a,b need init
    for(int i = m + 1; i < lim; i++) b[i] = 0;
    NTT(a, 1); NTT(b, 1);
    for(int i = 0; i < lim; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1);
    ll inv = qpow(lim, P - 2);
    for(int i = 0; i < lim; i++) a[i] = a[i] * inv % P;
}

int fac[N], inv[N], c[N];

void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    c[0] = 1;
    for(int i = 1; i < N; i++) c[i] = 1ll * c[i - 1] * (n - i) % MOD * qpow(i, MOD - 2) % MOD;
    m = k;
    for(int i = 0; i <= m; i++) {
        a[i] = (i & 1) ? MOD - inv[i] : inv[i];
        b[i] = qpow(i, k) * inv[i] % MOD; 
    }
    solve(a, b);
}

void run(){
    ll ans = 1ll * n * qpow(2, 1ll * (n - 1) * (n - 2) / 2) % MOD;
    ll res = 0;
    for(int i = 0; i <= m; i++) {
        res = (res + a[i] * fac[i] % MOD * c[i] % MOD * qpow(2, n - i - 1) % MOD) % MOD;
    }
    ans = ans * res % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    cin >> n >> k;
    init();
    run();
    return 0;
}
