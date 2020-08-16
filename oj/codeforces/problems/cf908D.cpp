// Author : heyuhhh
// Created Time : 2020/08/10 10:58:13
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
const int N = 1e3 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int dp[N][N];
int k, A, B;

void run() {
    int pa, pb;
    cin >> k >> pa >> pb;
    A = 1ll * pa * qpow(pa + pb, MOD - 2) % MOD;
    B = 1ll * pb * qpow(pa + pb, MOD - 2) % MOD;
    int P = 1ll * A * qpow(B, MOD - 2) % MOD;
    for (int i = k; i >= 1; i--) {
        for (int j = k - 1; j >= 0; j--) {
            if (i + j >= k) {
                dp[i][j] = (i + j + P) % MOD;
            } else {
                dp[i][j] = (1ll * dp[i][j + i] * B % MOD +
                            1ll * dp[i + 1][j] * A % MOD) % MOD;
            }
        }
    }
    cout << dp[1][0] << '\n';
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