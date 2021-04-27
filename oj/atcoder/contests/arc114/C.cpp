// Author : heyuhhh
// Created Time : 2021/03/15 09:27:30
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
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int dec(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int powm[N][N];
void run() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        powm[i][0] = 1;
        for (int j = 1; j < N; j++) {
            powm[i][j] = mul(powm[i][j - 1], i);
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        int m = 1;
        dp[1][i] = 1;
    }
    for (int i = 2; i <= m; i++) {
        ll S = 0, S2 = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = add(mul(j, powm[i - 1][j - 1]), add(S, S2));
            dp[i][j] = add(dp[i - 1][j],  dp[i][j]);
            S = add(dp[i - 1][j], mul(S, i));
            S2 = add(dp[i][j], mul(S2, i - 1));
        }
    }
    cout << dp[m][n] << '\n';
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