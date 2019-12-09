//	若秩小于$n$，则有无穷多组解，但首先排除无解的情况。
//高斯消元求解异或方程组
int ans = 1;
for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
        if(a[j] > a[i])
            swap(a[i], a[j]);
    }
    if(a[i] == 0) {
        ans = 1 << (n - i + 1);
        break ;
    }
    if(a[i] == 1) {
        ans = 0;
        break ;
    }
    for(int k = n; k >= 1 ; k--) {
        if((1 << k) & a[i]) {
            for(int j = 1; j <= n ; j++) {
                if(i != j && (1 << k) & a[j])
                    a[j] ^= a[i];
            }
            break ;
        }
    }
} 
//高斯消元求解同余模方程
int now = 1;
for(int i = 1 ; i <= n ; i++) {
    int j = now ;
    while(j <= m && !a[j][i]) j++;
    if(j > m) continue ;
    if(j != now) {	
        for(int k = 1 ; k <= n + 1 ; k++) {
            swap(a[now][k] , a[j][k]) ;
        }
    }
    for(int j = now + 1 ; j <= m ; j++)
        if(a[j][i]) {
            int t = a[j][i] * inv[a[now][i]] % MOD;
            for(int k = i ; k <= n + 1 ; k++) {
                a[j][k] = (((a[j][k] - t * a[now][k]) % MOD) + MOD) % MOD;
            }
        }
    now++;
} 
