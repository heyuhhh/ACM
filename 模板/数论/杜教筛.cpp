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
