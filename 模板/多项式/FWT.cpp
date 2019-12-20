void FWT_or(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[i + j + k] = (a[j + k] + a[i + j + k]) % MOD;
                else a[i + j + k] = (a[i + j + k] + MOD - a[j + k]) % MOD;
}
void FWT_and(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[j + k] = (a[j + k] + a[i + j + k]) % MOD;
                else a[j + k] = (a[j + k] + MOD - a[i + j + k]) % MOD;      
}
void FWT_xor(int *a, int n, int op) {
    static int inv2 = (MOD + 1) / 2;
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                int X = a[j + k], Y = a[i + j + k];
                a[j + k] = (X + Y) % MOD; a[i + j + k] = (X + MOD - Y) % MOD;
                if(op == -1) a[j + k] = 1ll * a[j + k] * inv2 % MOD, a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
            }                
}


FWT_or(a, l, 1); FWT_or(b, l, 1);
for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
FWT_or(c, l, -1);
for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
FWT_or(a, l, -1); FWT_or(b, l, -1);

FWT_and(a, l, 1); FWT_and(b, l, 1);
for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
FWT_and(c, l, -1);
for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
FWT_and(a, l, -1); FWT_and(b, l, -1);

FWT_xor(a, l, 1); FWT_xor(b, l, 1);
for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
FWT_xor(c, l, -1);
for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
FWT_xor(a, l, -1); FWT_xor(b, l, -1);
