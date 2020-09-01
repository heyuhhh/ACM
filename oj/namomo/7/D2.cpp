// Author : heyuhhh
// Created Time : 2020/08/29 21:51:27
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    auto sum = [&] (int x) {
        return 1ll * x * (x + 1) / 2;
    };
    int x;
    for (x = 1; x <= m; x++)
        if (sum(x) >= m) 
            break;
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 1;
    auto calc = [&] (int v) {
        int l = 1, r = x + 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (1ll * mid * (2 * v - mid + 1) / 2 >= m) r = mid;
            else l = mid + 1;
        }
        return r;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j && dp[i - 1][j - 1] + x - 1 <= a[i - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + calc(a[i - 1] - dp[i - 1][j - 1] + 1));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (dp[n][i] != INF) 
            ans = i;
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