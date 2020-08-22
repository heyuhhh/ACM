// Author : heyuhhh
// Created Time : 2020/07/23 20:36:09
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
const int N = 1e5 + 5, M = 20 + 5;

char s[N], t[M];
int n, m;
int val[N];
int dp[M][M];


void run() {
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int p = 1; p <= n - m + 1; p++) {
        memset(dp, INF, sizeof(dp));
        dp[0][0] = 0;
        for (int i = p; i < p + m; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i] == t[j]) {
                    dp[i - p + 1][j] = dp[i - p][j - 1] + 1;
                }
                dp[i - p + 1][j] = max(dp[i - p][j], dp[i - p + 1][j - 1]);
            }
        }
        val[p] = dp[p + m - 1][m];
    }
    
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