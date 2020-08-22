// Author : heyuhhh
// Created Time : 2020/08/06 14:43:02
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

int mu[N], p[N], phi[N];
bool chk[N];
void init() {
    mu[1] = phi[1] = 1;
    int cnt = 0, k = N - 1;
    for(int i = 2; i <= k; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
        for(int j = 1; j <= cnt && i * p[j] <= k; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {mu[i * p[j]] = 0; phi[i * p[j]] = phi[i] * p[j]; break;}
            mu[i * p[j]] = -mu[i]; phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

bool f[N];
int F[N], G[N];
int S[N], val[N];

void run() {
    int T, k, x;
    cin >> T >> k >> x;
    for (int i = 1; i < N; i++) {
        f[i] = 1;
    }
    for (int t = 2; 1ll * t * t < N; t++) {
        for (int i = 1; 1ll * t * t * i < N; i++) {
            f[i * t * t] = 0;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            F[j] = (F[j] + 1ll * mu[i] * f[j / i] % MOD * (j / i) % MOD + MOD) % MOD;
        }
    }
    for (int i = 1; i < N; i++) {
        F[i] = 1ll * F[i] * qpow(i, 1ll * k * x) % MOD;
        G[i] = (G[i - 1] + F[i]) % MOD;
    }
    for (int i = 1; i < N; i++) {
        val[i] = (val[i - 1] + qpow(i, k)) % MOD;
        S[i] = qpow(val[i], x);
    }
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans = (ans + 1ll * S[n / l] * (G[r] - G[l - 1] + MOD) % MOD) % MOD;
        }
        cout << ans << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}