// Author : heyuhhh
// Created Time : 2020/08/06 15:43:09
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mu[N], p[N], sum[N];
bool chk[N];
void init() {
    mu[1] = 1;
    int cnt = 0;
    for(int i = 2; i < N; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1;
        for(int j = 1; j <= cnt && i * p[j] < N; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {mu[i * p[j]] = 0; break;}
            mu[i * p[j]] = -mu[i];
        }
    }
} 

int v[N], prime[N], phi[N];
int sump[N];
int num;
void Euler() {
    phi[1] = 1;
    for(int i = 2; i < N; i++) {
        if(v[i] == 0) {
            v[i] = i;
            phi[i] = i - 1;
            prime[++num] = i;
        }
        for(int j = 1; j <= num && prime[j] * i < N; j++) {
            v[prime[j] * i] = prime[j] ;
            phi[prime[j] * i] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]) ;
        }
    }
    for (int i = 1; i < N; i++) {
        sump[i] = (sump[i - 1] + phi[i]) % MOD;
    }
} 

int vv[N], val[N];
int powt[N], sumpow[N];

void run() {
    ll ans = 0;
    for (int d = 1; d <= 5; d++) {
        ll res = qpow(d, 4);
        for (int i = 1; i <= 5 / d; i++) {
            for (int j = 1; j <= 5 / d; j++) {
                for (int k = 1; k <= 5 / d; k++) {
                    int g = __gcd(i, j);
                    g = __gcd(g, k);
                    if (g == 1) {
                        ans += res * i * j * k;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    Euler();
    run();
    return 0;
}