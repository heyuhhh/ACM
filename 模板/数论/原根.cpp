ll qp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int work(ll P) {   //p - 1
    vector <int> div;
    for(int i = 2; 1ll * i * i <= P; i++) {
        if(P % i == 0) {
            div.push_back(i);
            while(P % i == 0) P /= i;
        }
    }
    if(P > 1) div.push_back(P);
    for(int i = 2;; i++) {
        bool ok = true;
        for(auto x : div) {
            if(qp(i, (p - 1) / x) % p == 1) {
                ok = false; break;
            }
        }
        if(ok) return i;
    }
} 
