// Author : heyuhhh
// Created Time : 2020/08/23 09:40:54
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
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(z + 1));
    dp[1][0] = a[0];
    for (int i = 2; i <= k + 1; i++) {
        for (int j = 0; j <= z; j++) {
            if (i - 1 + 2 * j <= k) {
                dp[i][j] = dp[i - 1][j] + a[i - 1];
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i - 1] + a[i - 2]);
                }
            }
        }
    }
    for (int i = 1; i <= k + 1; i++) {
        for (int j = 0; j <= z; j++) {
            if (i - 1 + 2 * j == k - 1 && j < z && i > 1) {
                ans = max(ans, dp[i][j] + a[i - 2]);
            }
            if (i - 1 + 2 * j == k) {
                ans = max(ans, dp[i][j]);
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}