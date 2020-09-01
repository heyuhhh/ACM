// Author : heyuhhh
// Created Time : 2020/08/23 14:48:59
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
void run() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), c(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    sort(all(a)), sort(all(b)), sort(all(c));
    reverse(all(a)), reverse(all(b)), reverse(all(c));
    
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int t = 0; t <= k; t++) {
                if (dp[i][j][t] != -1) {
                    if (i < n && j < m) dp[i + 1][j + 1][t] = max(dp[i + 1][j + 1][t], dp[i][j][t] + a[i] * b[j]);
                    if (i < n && t < k) dp[i + 1][j][t + 1] = max(dp[i + 1][j][t + 1], dp[i][j][t] + a[i] * c[t]);
                    if (j < m && t < k) dp[i][j + 1][t + 1] = max(dp[i][j + 1][t + 1], dp[i][j][t] + b[j] * c[t]);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int t = 0; t <= k; t++) {
                ans = max(ans, dp[i][j][t]);
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
    run();
    return 0;
}