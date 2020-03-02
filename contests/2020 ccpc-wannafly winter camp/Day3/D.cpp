#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 5;
int mu[N], p[N];
ll phi[N];
bool chk[N];
unordered_map <int, ll> mp1, mp2;
int MOD, inv6;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;  
    }
    return ans;  
}
void init() {
    inv6 = qpow(6, MOD - 2);
    phi[1] = 1;
    int cnt = 0, k = N - 1;
    for(int i = 2; i <= k; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
        for(int j = 1; j <= cnt && i * p[j] <= k; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {phi[i * p[j]] = phi[i] * p[j] % MOD; break;}
            phi[i * p[j]] = phi[i] * (p[j] - 1) % MOD;
        }
    }
    for(int i = 1; i < N; i++) {
        phi[i] = (phi[i - 1] + phi[i]) % MOD;
    }
}

ll djs_phi(int n) {
    if(n <= 5000000) return phi[n];
    if(mp2[n]) return mp2[n];
    ll ans = 1ll * (n + 1) * n / 2 % MOD;
    for(int i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans -= 1ll * (j - i + 1) * djs_phi(n / i) % MOD;
        if(ans < 0) ans += MOD;
    }
    return mp2[n] = ans;
}
int n;
int S(int n) {
    return 1ll * n * (n + 1) % MOD * (2 * n + 1) % MOD * inv6 % MOD;
}
int main() {
    cin >> n >> MOD;
    init();
    int ans = 0;
    for(int i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        int up = n / i;
        int res = S(up);
        ans = (ans + 1ll * res * (djs_phi(j) - djs_phi(i - 1) + MOD) % MOD) % MOD;   
    }
    cout << ans << '\n';
    return 0;
}
