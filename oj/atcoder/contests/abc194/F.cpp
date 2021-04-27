// Author : heyuhhh
// Created Time : 2021/03/07 19:18:55
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
const int N = 2e5 + 5, M = 17, MOD = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int dec(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

string s;
int n, k;
int dp[N][M];
int cnt[M];

int trans(char t) {
    if (t >= '0' && t <= '9') {
        return t - '0';
    }
    return t - 'A' + 10;
}

void run() {
    cin >> s >> k;
    n = s.length();
    int pre = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (j == 0) {
                if (i > 0) {
                    dp[i + 1][1] = add(dp[i + 1][1], 15);
                    dp[i + 1][0] = add(dp[i + 1][0], 1);
                }
            } else {
                dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(16 - j, dp[i][j]));
                dp[i + 1][j] = add(dp[i + 1][j], mul(j, dp[i][j]));
            }
        }
        for (int t = (pre == 0); t < trans(s[i]); ++t) {
            if (++cnt[t] == 1) dp[i + 1][pre + 1] = add(dp[i + 1][pre + 1], 1);
            else dp[i + 1][pre] = add(dp[i + 1][pre], 1);
            --cnt[t];
        }
        if (++cnt[trans(s[i])] == 1) ++pre;
    }
    int ans = dp[n][k] + (pre == k);
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