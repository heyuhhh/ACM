// Author : heyuhhh
// Created Time : 2021/03/09 14:58:37
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
    auto solve = [&] (int n, int op = 0) {
        ll s = accumulate(all(a), 0ll);
        sort(all(a));
        reverse(all(a));

        int up = (n + 1) / 2;
        vector<vector<__int128>> f(n + 1, vector<__int128>(up + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(up, i); j++) {
                if (i - j <= j) {
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                    assert(f[i][j] <= 1e20);
                }
            }
        }

        __int128 all = f[n][up];
        vector<vector<__int128>> dp(n + 1, vector<__int128>(up + 1, -1));
        
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, up); j++) {
                if (i - j <= j) {
                    dp[i][j] = 0;
                    if (dp[i - 1][j - 1] != -1) {
                        dp[i][j] += dp[i - 1][j - 1] + a[i - 1];
                    }
                    if (dp[i - 1][j] != -1) {
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }
        }
        if (op) {
            function<ll(int, int)> calc = [&] (int i, int j) {
                if (i - j > j) return 0ll;
                if (i == 1 && j == 1) return 1ll;
                return calc(i - 1, j - 1) + calc(i - 1, j);
            };
            dp[n][up] -= calc(n, up) * 2e9;
            s -= 2e9;
        }
        long double ans1 = (long double)dp[n][up] / all;
        long double ans2 = s - ans1;
        cout << ans1 << ' ' << ans2 << '\n';
    };
    if (n & 1) {
        solve(n);
    } else {
        a.emplace_back(2e9);
        solve(n + 1, 1);
    }

}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    run();
    return 0;
}