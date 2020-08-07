/*
min25筛

用于解决一类积性函数前缀和的问题，积性函数$F$满足下面条件：
* $F$为完全积性函数，且$F(p^c)$易求；；
* 对于素数$p$，能够构造完全积性函数使得$f(p)=F(p)$，即在素数位置的取值相同；
* $f$函数的前缀和能在$O(1)$快速求解

*/
//以f(p^k)=p^k(p^k-1)为例 
ll n;
ll sum1[N], sum2[N], prime[N];
ll w[N], ind1[N], ind2[N];
ll g1[N], g2[N];
bool chk[N];
int tot, cnt;
void pre(int n) { //  \sqrt
    chk[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            prime[++tot] = i;
            // 预处理 \sum f(p)，这里只预处理了根号范围内 
            sum1[tot] = (sum1[tot - 1] + i) % MOD;
            sum2[tot] = (sum2[tot - 1] + 1ll * i * i % MOD) % MOD;
        }
        for(int j = 1; j <= tot && prime[j] * i <= n; j++) {
            chk[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
// 筛得\sum f(p), 求出2~n范围内的素数和，注意要去掉1 
void calc_g() {
    int z = sqrt(n);
    // 预处理，首先将质数的取值扩展到所有数，并且建立映射数组，只有O(sqrt(n))个位置有用 
    // ind数组能对于一个数x，快速找到对应的下标，利用了整除的性质 
    for(ll i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        w[++cnt] = n / i;
        g1[cnt] = w[cnt] % MOD;
        g2[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD * (2 * g1[cnt] + 1) % MOD * inv3 % MOD - 1;
        g1[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD - 1;
        if(n / i <= z) ind1[n / i] = cnt;
        else ind2[n / (n / i)] = cnt;
    } 
    // 开始筛法，g[j]-=f(p[i])*(g[k]-sum[i-1]) 
    for(int i = 1; i <= tot; i++) {
        for(int j = 1; j <= cnt && prime[i] * prime[i] <= w[j]; j++) {
            ll tmp = w[j] / prime[i], k;
            if(tmp <= z) k = ind1[tmp]; else k = ind2[n / tmp];
            (g1[j] -= prime[i] * (g1[k] - sum1[i - 1] + MOD) % MOD) %= MOD;
            (g2[j] -= prime[i] * prime[i] % MOD * (g2[k] - sum2[i - 1] + MOD) % MOD) %= MOD;
            if(g1[j] < 0) g1[j] += MOD;
            if(g2[j] < 0) g2[j] += MOD;
        }
    }
}
// 因为F为积性函数，所以先分两种情况：质数和合数进行考虑 
ll S(ll x, int y) { // 2~x >= P_y
    if(x <= 1 || prime[y] > x) return 0;
    ll z = sqrt(n);
    ll k = x <= z ? ind1[x] : ind2[n / x];  
    // 求这部分的质数答案，可扩展性较高 
    ll ans = (g2[k] - g1[k] + MOD - (sum2[y - 1] - sum1[y - 1]) + MOD) % MOD;
    // 枚举最小质因子及次方，然后递归求解
    // ans+=F(p[i]^e) * S(n/p[i],i+1) + F(p[i]^{e+1})
    for(int i = y; i <= tot && prime[i] * prime[i] <= x ; i++) {
        ll pe = prime[i], pe2 = prime[i] * prime[i];
        for(int e = 1; pe2 <= x; ++e, pe = pe2, pe2 *= prime[i]) {
            ans = (ans + pe % MOD * ((pe - 1) % MOD) % MOD * S(x / pe, i + 1) + pe2 % MOD * ((pe2 - 1) % MOD) % MOD) % MOD;
        }
    }
    return ans % MOD;
}