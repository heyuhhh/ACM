//递推式：cat[i]=cat[i-1]*(4i-2)/(i+1)
//通项：cat[n]=C(2n,n)/(n+1) 
int inv[N], cat[N];
void init(int n) {
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    cat[0] = cat[1] = 1;
    for (int i = 2; i <= n; i++) {
        cat[i] = 1ll * cat[i - 1] * (4 * i - 2) % MOD * inv[i + 1] % MOD;
    }
} 
