const int N = 4e5 + 5, P = 998244353, G = 3, Gi = 332748118, MOD = 998244353;
int n, m, r[N];
ll a[N], b[N], c[N];//注意空间要开四倍
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
        for(int i = 0; i < n; i++) A[i] = A[i] * inv % MOD;   
    }
}

void solve(int n) {
    if(n == 1) {
        b[0] = qpow(a[0], MOD - 2);
        return;
    }    
    solve((n + 1) >> 1);
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
