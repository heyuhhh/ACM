/*
 * Author:  heyuhhh
 * Created Time:  2020/3/23 21:16:35
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

const int N = 4e5 + 5, P = 998244353, G = 3, Gi = 332748118, MOD = 998244353;
int n, m, r[N];
ll a[N], b[N], c[N], d[N], e[N];//注意空间要开四倍
ll qpow(ll a, ll k) {
    ll ans = 1;
    while(k) {
        if(k & 1) ans = (ans * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return ans;
}
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

void Poly_inv(ll *a, ll *b, int n) {
    if(n == 1) {
        b[0] = qpow(a[0], MOD - 2);
        return;
    }    
    Poly_inv(a, b, (n + 1) >> 1);
    int lim = 1, L = 0;
    while(lim < (n << 1)) lim <<= 1, ++L;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for(int i = 0; i < n; i++) c[i] = a[i];
    for(int i = n; i < lim; i++) c[i] = 0;
    NTT(c, 1, lim); NTT(b, 1, lim);
    for(int i = 0; i < lim; i++) {
        b[i] = b[i] * (2 - b[i] * c[i] % MOD + MOD) % MOD;   
    }
    NTT(b, -1, lim);
    for(int i = n; i < lim; i++) b[i] = 0;
}

void Poly_sqrt(ll *a, ll *b, int n) {
    if(n == 1) {
        b[0] = 1; 
        return;  
    }
    Poly_sqrt(a, b, (n + 1) >> 1);
    int lim = 1, L = 0;
    while(lim < (n << 1)) lim <<= 1, ++L;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));   
    for(int i = 0; i < n; i++) e[i] = b[i], c[i] = a[i];
    for(int i = n; i < lim; i++) e[i] = c[i] = 0;
    NTT(e, 1, lim), NTT(c, 1, lim);
    for(int i = 0; i < lim; i++) {
        e[i] = (e[i] * e[i] % MOD + c[i]) % MOD;   
    }
    for(int i = 0; i < n; i++) b[i] = 2 * b[i] % MOD;
    for(int i = 0; i < lim; i++) c[i] = d[i] = 0;
    Poly_inv(b, d, n);
    NTT(d, 1, lim);
    for(int i = 0; i < lim; i++) b[i] = e[i] * d[i] % MOD;
    NTT(b, -1, lim);
    for(int i = n; i < lim; i++) b[i] = 0;
}

void run() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    Poly_sqrt(a, b, n);
    for(int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
