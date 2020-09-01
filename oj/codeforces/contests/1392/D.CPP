// Author : heyuhhh
// Created Time : 2020/08/22 15:21:47
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
    string s;
    cin >> s;
    vector<int> a(n + 2);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == 'L' ? 0 : 1);
    }
    
    auto solve = [&] (int x, int y) {
        vector<int> b = a;
        vector<vector<int>> dp(n + 2, vector<int>(2, INF));
        b[0] = b[n] = x, b[1] = b[n + 1] = y;
        dp[0][0] = dp[1][0] = 0;
        for (int i = 2; i < n + 2; i++) {
            if (b[i] == b[i - 2]) {
                if (b[i] != b[i - 1] && i == n + 1) {}
                else dp[i][0] = dp[i - 2][1] + (b[i] != b[i - 1]);
            } else {
                if (b[i] != b[i - 1] && i == n + 1) {}
                else dp[i][0] = dp[i - 2][0] + (b[i] != b[i - 1]);
            }
            if (b[i] == b[i - 1]) {
                if (i != n + 1) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            } else {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            if (i < n) {
                if (b[i] == b[i - 1]) {
                    dp[i][1] = dp[i - 1][0] + 1;   
                } else {
                    dp[i][1] = dp[i - 1][1] + 1;
                }
                if (b[i] == b[i - 2]) {
                    dp[i][1] = min(dp[i][1], dp[i - 2][0] + 1 + (b[i] == b[i - 1]));
                } else {
                    dp[i][1] = min(dp[i][1], dp[i - 2][1] + 1 + (b[i] == b[i - 1]));
                }
            }
        }
        int res = dp[n + 1][0] + (x != a[0]) + (y != a[1]);
        return res;
    };
    int ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, solve(i, j));
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