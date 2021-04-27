// Author : heyuhhh
// Created Time : 2020/12/20 16:22:04
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
 
map<char, int> mp;
 
void init() {
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['M'] = 4;
    mp['Y'] = 5;
    mp['K'] = 6;
}
 
void run() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(7, -INF)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            if (mp[s[i]] == j) dp[i][i][j] = 1;
        }
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            // [i, j]
            for (int k = i; k < j; k++) {
                // [i, k], [k + 1, j]
                bool flag1 = 0, flag2 = 0;
                for(int t = 0; t < 7; t++) {
                    if(dp[i][k][t] >= m) {
                        flag1 = 1;
                        break;
                    }
                }
                for(int t = 0; t < 7; t++) {
                    if(dp[k + 1][j][t] >= m) {
                        flag2 = 1;
                        break;
                    }
                }
                if(flag1) {
                    for(int t = 0; t < 7; t++) {
                        if(dp[k + 1][j][t] > dp[i][j][t])  dp[i][j][t] = dp[k + 1][j][t];
                    }
                }
                if(flag2) {
                    for(int t = 0; t < 7; t++) {
                        if(dp[i][k][t] > dp[i][j][t])  dp[i][j][t] = dp[i][k][t];
                    }
                }
                for(int t = 0; t < 7; t++) {
                    if(dp[i][k][t] + dp[k + 1][j][t] > dp[i][j][t])  dp[i][j][t] = dp[i][k][t] + dp[k + 1][j][t];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int c = 0; c < 3; c++)  if (dp[i][j][c] > 0) {
                cout << "i=" << i + 1 << ",j=" << j + 1 << ",c=" << c << ",dp=" << dp[i][j][c] << '\n';
            }
        }
    }
    // cout << dp[0][n - 1][2] << '\n';
    for (int i = 0; i < 7; i++) {
        // cout << dp[0][n - 1][i] << '\n';
        if (dp[0][n - 1][i] >= m) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}