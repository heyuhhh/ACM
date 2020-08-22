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
int nxt[N][26];
int dp[M][M];

void run() {
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 0; i < 26; i++) {
        nxt[n][i] = n + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    int q; 
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        dp[0][0] = l - 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] >= 0 && dp[i][j] <= r) {
                    int pos = dp[i][j];
                    int go = nxt[pos][t[i + 1] - 'a'];
                    if (dp[i + 1][j + 1] == -1) {
                        dp[i + 1][j + 1] = go;
                    } else {
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], go);
                    }
                    if (dp[i + 1][j] == -1) {
                        dp[i + 1][j] = dp[i][j];
                    } else {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                    }
                }
            }
        }
        int ans = r - l + 1 + m;
        for (int i = m; i >= 0; i--) {
            if (dp[m][i] >= l && dp[m][i] <= r) {
                ans -= 2 * i;
                break;
            }
        }
        cout << ans << '\n';
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