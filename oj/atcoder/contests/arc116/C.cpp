// Author : heyuhhh
// Created Time : 2021/03/28 20:23:45
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
const int N = 1e5 + 5, MOD = 998244353;
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}
void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<vector<int>> d(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            d[j].emplace_back(i);
        }
    }
    function<int(int, int)> dfs = [&] (int n, int m) {
        if (n == 1) return int(m > 0);
        if (m <= 0) return 0;
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        dp[n][m] = 0;
        for (auto& ds : d[m]) {
            dp[n][m] = add(dp[n][m], dfs(n - 1, m / ds - 1));
        }
        return dp[n][m];
    };
    int ans = dfs(n, m);
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