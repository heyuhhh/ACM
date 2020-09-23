// Author : heyuhhh
// Created Time : 2020/09/14 23:00:27
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
void chkmin(int& x, int y) {
    if (x > y) x = y;
}
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) if (dp[i][j] != INF) {
            if (j == 0) {
                chkmin(dp[i + 1][1], dp[i][j] + a[i]);
                if (i + 2 <= n) {
                    chkmin(dp[i + 2][1], dp[i][j] + a[i] + a[i + 1]);
                }
            } else {
                chkmin(dp[i + 1][0], dp[i][j]);
                if (i + 2 <= n) {
                    chkmin(dp[i + 2][0], dp[i][j]);
                }
            }
        }
    }
    int ans = min(dp[n][0], dp[n][1]);
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}