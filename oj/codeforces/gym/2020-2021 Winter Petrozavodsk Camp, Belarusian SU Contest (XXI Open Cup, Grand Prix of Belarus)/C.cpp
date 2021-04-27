// Author : heyuhhh
// Created Time : 2021/02/21 10:45:32
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
void add(int& x, int y) {
    y = (y % MOD + MOD) % MOD;
    x += y;
    if (x >= MOD) x -= MOD;
}
void dec(int& x, int y) {
    y = (y % MOD + MOD) % MOD;
    x -= y;
    if (x < 0) x += MOD;
}
void run() {
    int n;
    cin >> n;
    vector<int> dp(n + 1), sum(n + 1);
    dp[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = sum[i - 1];
        int hbit = -1;
        for (int j = 0; j < 20; j++) if (i >> j & 1) {
            hbit = j;
        }
        if (hbit != -1) {
            int x = (i ^ (1 << hbit));
            int bit = -1;
            for (int j = 0; j < 20; j++) if (x >> j & 1) {
                bit = j;
            }
            if (bit != -1) {
                int lim = (1 << bit + 1) - 1;
                dec(dp[i], sum[lim] - sum[0]);
                for (int j = 0; j < bit; j++) if (!(x >> j & 1)) {
                    int l = (1 << j);
                    int r = (1 << j + 1) - 1;
                    add(dp[i], sum[r] - sum[l - 1]);
                }
            }
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, dp[i]);
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