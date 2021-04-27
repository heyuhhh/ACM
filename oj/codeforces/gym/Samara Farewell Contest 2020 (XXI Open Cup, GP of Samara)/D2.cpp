// Author : heyuhhh
// Created Time : 2021/03/10 10:25:42
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    int op = (n & 1);
    for (int i = 1; i <= n; i++, op ^= 1) {
        for (int j = 1; j <= i; j++) {
            if (op) {
                if (j < i) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = 1;
                }
            } else {
                double P = 1.0 / i;
                dp[i][j] = P * (1.0 * (j - 1) * dp[i - 1][j - 1] + 1.0 * (i - j) * dp[i - 1][j]);
            }
        }
    }
    double ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 += dp[n][i] * a[i - 1];
        ans2 += (1 - dp[n][i]) * a[i - 1];
    }
    cout << ans1 << ' ' << ans2 << '\n';
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