// Author : heyuhhh
// Created Time : 2020/08/05 16:45:03
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
const int N = 5000 + 5, MOD = 998244353;

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

void run() {
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        for (int i = 1; i <= n; i++) {
            cout << 1 << " \n"[i == n];
        }
        return;
    }
    int r = n % (k + 1);
    if (r == 0) {
        for (int i = 1; i <= n; i++) {
            cout << 0 << " \n"[i == n];
        }
        return;
    }
    vector<int> ans(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= r; i++) {
        dp[r][i] = 1;
    }
    vector<int> pre(n + 1);
    for (int i = k; i <= n; i++) {
        pre[i] = qpow(C(i, k), MOD - 2);
    }   
    for (int i = r + k + 1; i <= n; i += k + 1) {
        for (int j = 2; j <= i; j++) {
            int L = j - 2, R = i - j;
            for (int t = 0; t <= k; t++) {
                if (t <= L && k - t <= R) {
                    dp[i][j] = (dp[i][j] + 1ll * C(L, t) * C(R, k - t) % MOD * pre[i - 1] % MOD
                     * dp[i - k - 1][j - t - 1] % MOD) % MOD;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[n][i] << " \n"[i == n];
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