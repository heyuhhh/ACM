// Author : heyuhhh
// Created Time : 2020/08/20 12:59:45
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
void run() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        int cnt = 0, cnt2 = 0;
        for (int j = i; j < n; j++) {
            if (b[j] == 1) ++cnt;
            else break;
        }
        for (int j = i - 1; j > 0; j--) {
            if (b[j] == 0) ++cnt2;
            else break;
        }
        l[i] = cnt + cnt2 + 1;
        cnt = cnt2 = 0;
        for (int j = i; j < n; j++) {
            if (b[j] == 0) ++cnt;
            else break;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (b[j] == 1) ++cnt2;
            else break;
        }
        r[i] = n - cnt - cnt2;
        if (l[i] > r[i]) {
            cout << 0 << '\n';
            return;
        }
        cout << l[i] << ' ' << r[i] << endl;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<int> val(n + 1);
    vector<int> sum(n + 1);
    for (int i = l[1]; i <= r[1]; i++) {
        dp[1][i] = 1;
        val[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + dp[1][i];
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < l[i] || j > r[i]) dp[i][j] = 0;
            else {
                if (b[i - 1]) {
                    dp[i][j] = (sum[n] - sum[j] + MOD - val[j] + MOD) % MOD;
                } else {
                    dp[i][j] = (sum[j] - val[j] + MOD) % MOD;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            sum[j] = (sum[j - 1] + dp[i][j]) % MOD;
            val[j] = (val[j] + dp[i][j]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[n][i] << ' ';
    } cout << '\n';
    int ans = sum[n];
    cout << ans << '\n';
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