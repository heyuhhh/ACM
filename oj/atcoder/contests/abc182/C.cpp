// Author : heyuhhh
// Created Time : 2020/11/08 20:08:15
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
void chkmax(int& x, int y) {
    if (y > x) x = y;
}
void run() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 3; k++) {
            dp[i][k] = dp[i - 1][k];
        }
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 3; k++) if (dp[j][k] != -1) {
                chkmax(dp[i][((s[i - 1] - '0') % 3 + k) % 3], dp[j][k] + 1);
            }
        }
    }
    if (dp[n][0] <= 0) {
        cout << -1 << '\n';
    } else {
        cout << n - dp[n][0] << '\n';
    }
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