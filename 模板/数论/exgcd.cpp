//扩展欧几里得
//求解最小正整数解
//若x_0,y_0为方程a'x+b'y=c'的解(除以gcd过后) 
//x=c'*(x_0+k*b'),y=c'*(y_0-k*a')
//若x_0,y_0为方程ax+by=c的解
//x=x_0+k*b/g,y=y_0-k*a/g
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }   
    ll d = exgcd(b, a % b, x, y);
    ll z = x;
    x = y;
    y = z - y * (a / b);
    return d;
} 
// don't consider g = 0
bool find_any(ll a, ll b, ll c, ll& x, ll& y, ll& g) {
    g = exgcd(abs(a), abs(b), x, y);
    if (c % g == 0) {
        return false;
    }
    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}
// x>=0
ll solve(ll a, ll b, ll c) {
    ll x, y, g;
    bool f = find_any(a, b, c, x, y, g);
    if (f == false) return -1;
    ll k = 1e18;
    a /= g;
    if (x < 0) {
        k = (-x + abs(a) - 1) / abs(a);
    } else {
        k = -(x / abs(a));
    }    
    if (a < 0) x -= k * a;
    else x += k * a;
    return x;
}