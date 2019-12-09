ll mul(ll a, ll b, ll p) {
    a %= p, b %= p;
    ll ans = 0;
    while(b) {
        if(b & 1) {
            ans = ans + a;
            if(ans > p) ans -= p;
        }
        a = a + a;
        if(a > p) a -= p;
        b >>= 1;
    }
    return ans;
}
ll qp(ll a, ll b, ll p) {
    ll ans = 1; a %= p;
    while(b) {
        if(b & 1) ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans;
}
bool check(ll a, ll n, ll x, ll t) {
    ll ans = qp(a, x, n);
    ll last = ans;
    for(int i = 1; i <= t; i++) {
        ans = mul(ans, ans, n);
        if(ans == 1 && last != 1 && last != n - 1) return true;
        last = ans;
    }
    if(ans != 1) return true;
    return false;
}
bool Miller_Rabin(ll n) {
    if(n == 1 || (n & 1) == 0) return false;
    if(n == 2) return true;
    ll x = n - 1, t = 0;
    while((x & 1) == 0) {x >>= 1, ++t;}
    srand(time(NULL));
    for(int i = 0; i < 8; i++) {
        ll a = rand() % (n - 1) + 1;
        if(check(a, n, x, t)) return false;
    }
    return true;
} 
