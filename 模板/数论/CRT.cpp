// 求解一元一次同余方程组
// 当模数不互质时，两两的答案可以通过exgcd解方程解得
struct CRT{
    void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
        if(b == 0) {
            x = 1, y = 0, g = a;
            return ;
        }
        exgcd(b, a % b, g, x, y);
        int t = x;
        x = y;
        y = t - (a / b) * y;
    }
    // m：模数；a：模意义下的答案；n：项数
    ll china(int m[], int a[], int n) {
        ll M, Mi, d, X, Y, ans;
        M = 1; ans = 0;
        for(int i = 1; i <= n; i++) M *= m[i];
        for(int i = 1; i <= n; i++) {
            Mi = M / m[i];
            exgcd(Mi, m[i], d, X, Y);
            ans = (ans + Mi * X * a[i]) % M;
        }
        if(ans < 0) ans += M;
        return ans;
    }
}crt; 

// 扩展中国剩余定理，通过exgcd两两合并答案，两个方程合并为一个方程
// 注意M=lcm(m_1,m_2)，相当于通解为 x+kM
void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0, g = a;
        return ;
    }
    exgcd(b, a % b, g, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
}

ll CRT(const vector<int>& a, const vector<int>& m) {
    assert(sz(a) == sz(m));
    ll x0 = a[0], m0 = m[0], n = sz(a);
    for (int i = 1; i < n; i++) {
        ll x1 = a[i], m1 = m[i], x, y, d;
        exgcd(m0, m1, d, x, y);
        if ((x0 - x1) % d) return -1;
        x = (x1 - x0) / d * x % (m0 / d * m1);
        x0 = (x * m0 + x0) % (m0 / d * m1);
        m0 = m0 / d * m1;
        if (x0 < 0) x0 += m0;
    }
    return x0;
}