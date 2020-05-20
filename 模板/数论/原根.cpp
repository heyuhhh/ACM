ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
//求模m的原根
int work(ll P, ll m) {   //P = phi(m)
    vector <int> div;
    ll x = P;
    for(int i = 2; 1ll * i * i <= x; i++) {
        if(x % i == 0) {
            div.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) div.push_back(x);
    for(int i = 2;; i++) {
        bool ok = true;
        for(auto x : div) {
            if(qpow(i, P / x, m) == 1) {
                ok = false; break;
            }
        }
        if(ok) return i;
    }
    return -1;
} 
