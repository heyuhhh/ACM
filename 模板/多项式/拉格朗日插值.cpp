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
	static const int SIZE = N;
	ll f[SIZE], fac[SIZE], inv[SIZE], pre[SIZE], suf[SIZE];
	int n;
	inline void add(ll &x, int y) {
		x += y;
		if(x >= MOD) x -= MOD;
	}
	void init(int _n) {
		n = _n;
		fac[0] = 1;
		for (int i = 1; i < SIZE; ++i) fac[i] = fac[i - 1] * i % MOD;
	    inv[SIZE - 1] = qpow(fac[SIZE - 1], MOD - 2);
		for (int i = SIZE - 1; i >= 1; --i) inv[i - 1] = inv[i] * i % MOD;
		//设置f初值，可以根据需要修改
		f[0] = 0;
		for (int i = 1; i <= n; ++i)
			f[i] = (f[i - 1] + qpow(i, k)) % MOD;
	}
	ll calc(ll x) {
		if (x <= n) return f[x];
		pre[0] = x % MOD;
		for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * ((x - i) % MOD) % MOD;
		suf[n] = (x - n) % MOD;
		for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * ((x - i) % MOD) % MOD;
		ll res = 0;
		for (int i = 0; i <= n; ++i) {
			ll tmp = f[i] * inv[n - i] % MOD * inv[i] % MOD;
			if (i) tmp = tmp * pre[i - 1] % MOD;
			if (i < n) tmp = tmp * suf[i + 1] % MOD;
			if ((n - i) & 1) tmp = MOD - tmp;
			add(res, tmp);
		}
		return res;
	}
}lagrange;
