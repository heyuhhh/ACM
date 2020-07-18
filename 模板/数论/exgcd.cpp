//扩展欧几里得
//求解最小正整数解
//x_0,y_0为方程a'x+b'y=c'的解(除以gcd过后) 
//x=c'*(x_0+k*b'),y=c'*(y_0-k*a')
//注意最后要乘上c/gcd 
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
ll calc(ll a, ll b, ll c) {
    ll x, y;
    ll g = __gcd(a, b);
    if(c % g != 0) return -1;
    a /= g, b /= g, c /= g;
    exgcd(a, b, x, y);
    x = (x % b + b) % b;
    x *= c; //!!!
    return x;
}