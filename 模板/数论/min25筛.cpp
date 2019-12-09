ll n;
ll sum1[N], sum2[N], prime[N];
ll w[N], ind1[N], ind2[N];
ll g1[N], g2[N];
bool chk[N];
int tot, cnt;
void pre(int n) { //  \sqrt
    chk[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            prime[++tot] = i;
            sum1[tot] = (sum1[tot - 1] + i) % MOD;
            sum2[tot] = (sum2[tot - 1] + 1ll * i * i % MOD) % MOD;
        }
        for(int j = 1; j <= tot && prime[j] * i <= n; j++) {
            chk[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
void calc_g() {
    int z = sqrt(n);
    for(ll i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        w[++cnt] = n / i;
        g1[cnt] = w[cnt] % MOD;
        g2[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD * (2 * g1[cnt] + 1) % MOD * inv3 % MOD - 1;
        g1[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD - 1;
        if(n / i <= z) ind1[n / i] = cnt;
        else ind2[n / (n / i)] = cnt;
    }
    for(int i = 1; i <= tot; i++) {
        for(int j = 1; j <= cnt && prime[i] * prime[i] <= w[j]; j++) {
            ll tmp = w[j] / prime[i], k;
            if(tmp <= z) k = ind1[tmp]; else k = ind2[n / tmp];
            (g1[j] -= prime[i] * (g1[k] - sum1[i - 1] + MOD) % MOD) %= MOD;
            (g2[j] -= prime[i] * prime[i] % MOD * (g2[k] - sum2[i - 1] + MOD) % MOD) %= MOD;
            if(g1[j] < 0) g1[j] += MOD;
            if(g2[j] < 0) g2[j] += MOD;
        }
    }
}
ll S(ll x, int y) { // 2~x >= P_y
    if(x <= 1 || prime[y] > x) return 0;
    ll z = sqrt(n);
    ll k = x <= z ? ind1[x] : ind2[n / x];
    ll ans = (g2[k] - g1[k] + MOD - (sum2[y - 1] - sum1[y - 1]) + MOD) % MOD;
    for(int i = y; i <= tot && prime[i] * prime[i] <= x ; i++) {
        ll pe = prime[i];
        for(int e = 1; pe <= x; ++e, pe = pe * prime[i]) {
            ll tmp = pe % MOD;
            ans = (ans + tmp * (tmp - 1) % MOD * (S(x / pe, i + 1) + (e != 1)) % MOD) % MOD;
        }
    }
    return ans % MOD;
} 
