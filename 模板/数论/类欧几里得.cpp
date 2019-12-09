const int MOD = 1000000007, inv2 = (MOD + 1) / 2;
ll f(ll n, ll a, ll b, ll c) {
	//sum_{i=0}^n (ai+b)/c
    if(a <= 0) return 0;
    if(a >= c || b >= c) {
        return (n * (n + 1) % MOD * inv2 % MOD * (a / c) % MOD
        + (n + 1) * (b / c) % MOD + f(n, a % c, b % c, c)) % MOD;
    }
    ll m = (a * n + b) / c;
    return (m * n % MOD - f(m - 1, c, c - b - 1, a) + MOD) % MOD;
} 
