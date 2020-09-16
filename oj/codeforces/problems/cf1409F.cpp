// Author : heyuhhh
// Created Time : 2020/09/10 09:26:36
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
const int N = 200 + 5;

int dp[N][N][N];

void chkm(int& x, int y) {
    if (x < y) x = y;
}

void run() {
    int n, K;
    cin >> n >> K;
    string s, t;
    cin >> s >> t;
    if (t[0] == t[1]) {
        for (int i = 0; i < n; i++)
            if (s[i] != t[0] && K)
                s[i] = t[0], --K;
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == t[0] && s[j] == t[1]) ++ans;
        cout << ans << '\n';
        return;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= min(K, i); j++)
            for (int k = 0; k <= i; k++) if (dp[i][j][k] != -1) {
                if (s[i] == t[0])
                    chkm(dp[i + 1][j][k + 1], dp[i][j][k]);
                if (s[i] == t[1])
                    chkm(dp[i + 1][j][k], dp[i][j][k] + k);
                chkm(dp[i + 1][j][k], dp[i][j][k]);
                if (j < K) {
                    chkm(dp[i + 1][j + 1][k], dp[i][j][k] + k);
                    chkm(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                }
            }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                ans = max(ans, dp[i][j][k]);
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