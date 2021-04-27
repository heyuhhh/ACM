// Author : heyuhhh
// Created Time : 2021/03/01 13:27:46
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void run() {
    int n, m;
    cin >> n >> m;
    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= m; i++) {
        f[i] = 1ll * f[i - 1] * i % MOD * (2 * i - 1) % MOD;
    }
    vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    vector<int> inv(n + 1);
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    auto C = [&] (int n, int m) {
        return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
    }
    int ans = 1ll * C(n, 2 * m) * f[m] % MOD * fac[n - 2 * m] % MOD;
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}