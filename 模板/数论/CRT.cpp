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
