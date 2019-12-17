/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 10:30:30
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

int n, a, b;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;    
    }
    return ans;
}
int inv[N], fac[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;   
}
ll C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int r[N], W[N];
void NTT(int *P, int opt, int N) {
    int l = 0; for(int i = 1; i < N; i <<= 1) ++l;
    for(int i = 0; i < N; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for(int i = 0; i < N; i++) if(i < r[i]) swap(P[i], P[r[i]]);
    for(int i = 1; i < N; i <<= 1) {
        int w = qpow(3, (MOD - 1) / (i << 1)); W[0] = 1;
        for(int k = 1; k < i; k++) W[k] = 1ll * W[k - 1] * w % MOD;
        for(int p = i << 1, j = 0; j < N; j += p) {
            for(int k = 0; k < i; k++) {
                int X = P[j + k], Y = 1ll * W[k] * P[i + j + k] % MOD;
                P[j + k] = (X + Y) % MOD;
                P[i + j + k] = (X + MOD - Y) % MOD;
            }   
        }
    }
    if(opt == -1) {
        reverse(P + 1, P + N);
        int inv = qpow(N, MOD - 2);
        for(int i = 0; i < N; i++) P[i] = 1ll * P[i] * inv % MOD;   
    }
}
int S[N];
int A[N], B[N], pw[N];
void solve(int len) {
    if(len == 0) {S[0] = 1; return;}
    if(len == 1) {S[1] = 1; return;}
    if(len & 1) {
        solve(len - 1);
        for(int i = len; i; i--) S[i] = (S[i - 1] + 1ll * S[i] * (len - 1)) % MOD;   
    } else {
        solve(len >> 1); int l = len >> 1, N;
        for(N = 1; N <= len; N <<= 1);
        pw[0] = 1;
        for(int i = 1; i <= l; i++) pw[i] = 1ll * pw[i - 1] * l % MOD;
        for(int i = 0; i <= l; i++) A[i] = 1ll * S[i] * fac[i] % MOD;
        for(int i = 0; i <= l; i++) B[i] = 1ll * pw[i] * inv[i] % MOD;
        reverse(B, B + l + 1);
        NTT(A, 1, N); NTT(B, 1, N);
        for(int i = 0; i < N; i++) A[i] = 1ll * A[i] * B[i] % MOD;
        NTT(A, -1, N);
        for(int i = 0; i <= l; i++) A[i] = 1ll * A[i + l] * inv[i] % MOD;
        for(int i = l + 1; i < N; i++) A[i] = B[i] = 0;
        for(int i = 0; i <= l; i++) B[i] = S[i];
        NTT(A, 1, N); NTT(B, 1, N);
        for(int i = 0; i < N; i++) A[i] = 1ll * A[i] * B[i] % MOD;
        NTT(A, -1, N);
        for(int i = 0; i <= len; i++) S[i] = A[i];
        for(int i = 0; i < N; i++) A[i] = B[i] = 0;
    }
}
void run(){
    init();
    solve(5);
    for(int i = 0; i <= 5; i++) cout << S[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
