#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 3005;
typedef long long ll;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int fac[N], inv[N], powC[N];
int n, c;

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    powC[0] = 1;
    for (int i = 1; i < N; i++) {
        powC[i] = 1ll * powC[i - 1] * c % MOD;
    }
}

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

string s;

void run() {
    n = s.length();
    int ans = 0, has = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = 0; j <= n - i - 1; j++) {
                ans = (ans + 1ll * C(n - i - 1, j) * powC[has + j] % MOD) % MOD;
            }
            ++has;
        }
    }
    ans = (ans + powC[has]) % MOD;
    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> c;
    init();
    run();
    return 0;
}