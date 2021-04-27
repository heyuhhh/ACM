// Author : heyuhhh
// Created Time : 2020/11/15 20:24:00
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
void add(int& x, int y) {
    if (y >= MOD) y -= MOD;
    x += y;
    if (x >= MOD) x -= MOD;
}
void run() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;
    vector<vector<int>> r(h, vector<int>(w)), c(h, vector<int>(w)), d(h, vector<int>(w));
    r[0][0] = c[0][0] = d[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) if (s[i][j] != '#') {
            if (i == 0 && j == 0) continue;
            if (i) add(dp[i][j], r[i - 1][j]);
            if (j) add(dp[i][j], c[i][j - 1]);
            if (i && j) add(dp[i][j], d[i - 1][j - 1]);
            if (i) add(r[i][j], r[i - 1][j] + dp[i][j]);
            else r[i][j] = dp[i][j];
            if (j) add(c[i][j], c[i][j - 1] + dp[i][j]);
            else c[i][j] = dp[i][j];
            if (i && j) add(d[i][j], d[i - 1][j - 1] + dp[i][j]);
            else d[i][j] = dp[i][j];
        }
    }
    int ans = dp[h - 1][w - 1];
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