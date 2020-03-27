void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    ll z = x ;
    x = y;
    y = z - y * (a / b);
} 
//求解最小正整数解
//x=c*x_0+k*b,y=c*y_0-k*a
ll calc(ll a, ll b, ll c) {
    ll x, y;
    ll g = __gcd(a, b);
    if(c % g != 0) return -1;
    a /= g, b /= g, c /= g;
    exgcd(a, b, x, y);
    x *= c;
    x = (x % b + b) % b;
    return x;
}
