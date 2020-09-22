// Author : heyuhhh
// Created Time : 2020/09/21 10:19:22
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> Poly;
#define ri register int
#define cs const
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
const int MOD = 998244353, inv2 = (MOD + 1) >> 1;
const int N = 4e5 + 5, M = (1 << 19); //四倍空间,M=2^x且M>=N
typedef vector <int> Poly;
#define ri register int
#define cs const
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD;}
inline int qpow(int a, int b) {int res = 1; while(b) {if(b & 1) res = mul(res, a); a = mul(a, a); b >>= 1;} return res;}
int fac[N], rev[N], inv[N], pw[M], W[2][M];
int INV[N];
inline void init() {
    inv[0] = inv[1] = 1;
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    INV[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        INV[i] = 1ll * INV[i + 1] * (i + 1) % MOD;
    }
    for(ri i = 2; i < N; i++) inv[i] = mul(inv[MOD % i], MOD - MOD / i);
    int w0 = qpow(3, (MOD - 1) / M), w1 = qpow((MOD + 1) / 3, (MOD - 1) / M);
    W[0][0] = W[1][0] = 1;
    for(ri i = 1; i < M; i++) {
        W[0][i] = mul(W[0][i - 1], w0);
        W[1][i] = mul(W[1][i - 1], w1);
    }
}      
inline void init_rev(int len) {
    for(ri i = 0; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * (len >> 1));   
}
inline void NTT(Poly &a, int n, int op) {
    for(ri i = 0; i < n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(ri i = 1; i < n; i <<= 1) {
        int t = M / (i << 1), t2 = (op == -1 ? 1 : 0);
        for(ri j = 0; j < i; ++j) pw[j] = W[t2][j * t];
        int wn = (op == -1 ? W[1][i] : W[0][i]);
        for(ri j = 0; j < n; j += (i << 1)) {
            for(ri k = 0, x, y; k < i; ++k) {
                x = a[j + k], y = mul(pw[k], a[j + k + i]);
                a[j + k] = add(x, y);
                a[j + k + i] = dec(x, y);
            }   
        }
    }   
    if(op == -1) for(ri i = 0; i < n; i++) a[i] = mul(a[i], inv[n]);
}
inline Poly operator * (Poly a, Poly b) {
    int n = sz(a), m = sz(b), l = 1;
    while(l < n + m - 1) l <<= 1;
    init_rev(l);
    a.resize(l), NTT(a, l, 1);
    b.resize(l), NTT(b, l, 1);
    for(ri i = 0; i < l; i++) a[i] = mul(a[i], b[i]);
    NTT(a, l, -1);
    a.resize(n + m - 1);
    return a;
}

int n;

Poly calc(const Poly& c, const Poly& b, int l, int r) {
    if (l == r) {
        Poly res(2);
        res[0] = c[l + 2], res[1] = b[l + 2];
        return res;
    }
    int mid = (l + r) >> 1;
    Poly res = calc(c, b, l, mid);
    res = res * calc(c, b, mid + 1, r);
    if (sz(res) >= n + 1) {
        res.resize(n + 1);
    }
    return res;
}

void run() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1), c(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> c[i];
    }
    Poly A = calc(c, b, 0, n - 2);
    Poly B(n + 1);
    for (int i = 0; i <= n; i++) {
        B[i] = 1ll * a[i] * fac[i] % MOD;
    }
    reverse(all(B));
    Poly C = A * B;
    for (int i = n; i >= 0; i--) {
        int ans = 1ll * C[i] * INV[n - i] % MOD;
        if (i < n) cout << ' ';
        cout << ans;
    }
    cout << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}