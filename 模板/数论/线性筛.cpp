int v[N], prime[N], phi[N];
int num;
void Euler() {
    for(int i = 2; i <= n; i++) {
        if(v[i] == 0) {
            v[i] = i;
            phi[i] = i - 1;
            prime[++num] = i;
        }
        for(int j = 1; j <= num && prime[j] * i <= n; j++) {
            v[prime[j] * i] = prime[j] ;
            phi[prime[j] * i] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]) ;
        }
    }
} 

int mu[N], p[N], sum[N];
bool chk[N];
void init() {
    mu[1] = 1;
    int cnt = 0, k = min(n, m);
    for(int i = 2; i <= k; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1;
        for(int j = 1; j <= cnt && i * p[j] <= k; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {mu[i * p[j]] = 0; break;}
            mu[i * p[j]] = -mu[i];
        }
    }
} 
