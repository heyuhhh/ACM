//拉格朗日求d次多项式系数，a[i]为系数 
ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}
struct Lagrange {
    ll f[N], a[N], b[N];
    int d;
    void init(int _d) {
        d = _d;
        //y_i
        for(int i = 1; i <= d + 1; i++) f[i] = (f[i - 1] + qpow(i, d - 1)) % MOD; 
        b[0] = 1;
    }
    void work() {
        for(int i = 0; i <= d; i++) {
            for(int j = i + 1; j; j--) b[j] = (b[j - 1] + MOD - 1ll * b[j] * (i + 1) % MOD) % MOD;
            b[0] = 1ll * b[0] * (MOD - i - 1) % MOD;
        }
        for(int i = 0; i <= d; i++) {
            int s = f[i + 1], inv = qpow(i + 1, MOD - 2);
            for(int j = 0; j <= d; j++) if(i != j) s = 1ll * s * qpow((i - j + MOD) % MOD, MOD - 2) % MOD;
            b[0] = 1ll * b[0] * (MOD - inv) % MOD;
            for(int j = 1; j <= d + 1; j++) b[j] = (MOD - 1ll * (b[j] + MOD - b[j - 1]) * inv % MOD) % MOD;
            for(int j = 0; j <= d + 1; j++) a[j] = (a[j] + 1ll * s * b[j]) % MOD;
            for(int j = d + 1; j; j--) b[j] = (b[j - 1] + MOD - 1ll * b[j] * (i + 1) % MOD) % MOD;
            b[0] = 1ll * b[0] * (MOD - i - 1) % MOD;
        }   
    }
}A;
