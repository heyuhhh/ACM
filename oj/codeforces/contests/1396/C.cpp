// Author : heyuhhh
// Created Time : 2020/08/31 11:47:35
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
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1000000000000000000));
    dp[1][0] = a[1] * r1 + r3;
    dp[1][1] = min(r2, a[1] * r1 + r1);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i] * r1 + r3 + d;
        if (i == n) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * d + r1 + min(a[i] * r1 + r3, min(a[i] * r1 + r1, r2) + d + r1));
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + r1) + 2 * d + min(a[i] * r1 + r1, r2) + d + r1;
        } else {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * d + r1 + min(a[i] * r1 + r3, min(a[i] * r1 + r1, r2) + r1) + d);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 2 * d + r1) + min(a[i] * r1 + r1, r2) + d;
        } 
    }
    ll ans = min(dp[n][0], dp[n][1]);
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