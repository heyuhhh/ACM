const int N = 4e5 + 5, M = 2e6 + 5, P = 998244353, G = 3, Gi = 332748118;
int n, m, lim = 1, L, r[N];
ll a[N], b[N];
ll qp(ll a, ll k) {
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
        ll Wn = qp( type == 1 ? G : Gi , (P - 1) / (mid << 1)); //Wn = g ^ ((p - 1) / n)  (mod p)
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
    for(int i = n + 1; i < lim; i++) a[i] = 0;  //a,b need init
    for(int i = m + 1; i < lim; i++) b[i] = 0;
    NTT(a, 1); NTT(b, 1);
    for(int i = 0; i < lim; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1);
    ll inv = qp(lim, P - 2);
    for(int i = 0; i < lim; i++) a[i] = a[i] * inv % P;
}
