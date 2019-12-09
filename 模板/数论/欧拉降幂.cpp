ll Mod(ll a, ll b) { //可以直接避免分类讨论
    return a < b ? a : a % b + b;
}
int qp(ll a, ll b, ll p) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = Mod(ans * a, p);
        a = Mod(a * a, p);
        b >>= 1;
    }
    return ans;
}
int calc(ll a, ll b, ll m) {
    if(m == 1 || !b) return 1;
    int p = phi[m];
    int x = calc(a, b - 1, p);
    return qp(a, x, m);
}
