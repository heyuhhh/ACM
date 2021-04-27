// Author : heyuhhh
// Created Time : 2020/10/05 16:54:44
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
const int N = 1e5 + 5;
void chkmin(ll& x, ll y) {
    if (x > y) x = y;
}
void run() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> x(n), t(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> t[i] >> y[i] >> r[i];
    }
    vector<vector<ll>> dp(s1 + s2 + 1, vector<ll>(s1 + s2 + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<ll>> new_dp = dp;
        for (int j = 0; j <= s1 + s2; j++) {
            for (int k = 0; k <= s1 + s2; k++) if (dp[j][k] != 1e18) {
                if (j < s1) {
                    chkmin(new_dp[j + x[i]][k], dp[j][k] + t[i]);
                }
                if (k < s2) {
                    chkmin(new_dp[j][k + y[i]], dp[j][k] + r[i]);
                }
            }
        }
        swap(dp, new_dp);
    }
    ll ans = 1e18;
    for (int i = s1; i <= s1 + s2; i++) {
        int j = s1 + s2 - i;
        ans = min(ans, dp[i][j]);
    }
    if (ans == 1e18) ans = -1;
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