int mu[N], p[N];
ll phi[N];
bool chk[N];
unordered_map <int, ll> mp1, mp2;
void init() {
    mu[1] = phi[1] = 1;
    int cnt = 0, k = N - 1;
    for(int i = 2; i <= k; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
        for(int j = 1; j <= cnt && i * p[j] <= k; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {mu[i * p[j]] = 0; phi[i * p[j]] = phi[i] * p[j]; break;}
            mu[i * p[j]] = -mu[i]; phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for(int i = 1; i < N; i++) mu[i] += mu[i - 1], phi[i] += phi[i - 1];
}
ll djs_mu(int n) {
    if(n <= 5000000) return mu[n];
    if(mp1[n]) return mp1[n];
    ll ans = 1;
    for(int i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans -= (j - i + 1) * djs_mu(n / i);
    }
    return mp1[n] = ans;
}
ll djs_phi(int n) {
    if(n <= 5000000) return phi[n];
    if(mp2[n]) return mp2[n];
    ll ans = 1ll * (n + 1) * n / 2;
    for(int i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans -= (j - i + 1) * djs_phi(n / i);
    }
    return mp2[n] = ans;
}