// Author : heyuhhh
// Created Time : 2020/08/04 16:15:23
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
const int N = 5e6 + 5, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int fac[N], inv[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int cat(int n) {
    if (n == 0) return 1;
    return 1ll * C(2 * n, n) * qpow(n + 1, MOD - 2) % MOD;
}

int ans[N];

void run() {
    int n;
    cin >> n;
    int k = n / 2;
    for (int i = 1; i <= k; i++) {
        ans[i] = 0;
    }
    for (int i = k + 1; i <= n; i++) {
        int p = i - 1 - (n - i);
        int res = 1ll * C(i - 1, n - i) % MOD * fac[n - i] % MOD;
        int res2 = 1ll * fac[p] * qpow(1ll * qpow(2, p / 2) * fac[p / 2] % MOD, MOD - 2) % MOD;
        res = 1ll * res * res2 % MOD;
        ans[i] = res;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += ans[i];
        if (tot >= MOD) tot -= MOD;
    }
    tot = qpow(tot, MOD - 2);
    for (int i = k; i <= n; i++) {
        ans[i] = 1ll * ans[i] * tot % MOD;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}