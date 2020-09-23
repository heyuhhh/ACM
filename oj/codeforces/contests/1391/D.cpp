// Author : heyuhhh
// Created Time : 2020/09/06 19:45:59
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
    vector<string> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    if (min(n, m) >= 4) {
        cout << -1 << '\n';
        return;
    }
    vector<string> s;
    if (n >= m) {
        s.resize(m);
        for (int i = 0; i < m; i++) {
            string tmp = "";
            for (int j = 0; j < n; j++)
                tmp += t[j][i];
            s[i] = tmp;
        }
        swap(n, m);
    } else {
        s = t;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    auto calc = [&](int i, int x) {
        string now = "";
        for (int j = 0; j < n; j++)
            now += s[j][i];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (now[i] - '0' != (x >> i & 1));
        }
        return ans;
    };
    auto sum = [&] (int x, int y) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (x >> i & 1);
            ans += (y >> i & 1);
        }
        return ans;
    };
    int lim = (1 << n);
    vector<vector<int>> dp(m, vector<int>(lim, INF));  
    for (int i = 0; i < lim; i++) {
        dp[0][i] = calc(0, i);
    }
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < lim; i++) {
            for (int k = 0; k < lim; k++) {
                if (n == 2 && sum(i, k) & 1) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][k] + calc(j, i));
                }
                if (n == 3 && (sum(i | 1, k | 1) & 1) && (sum(i | 4, k | 4) & 1)) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][k] + calc(j, i));
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < lim; i++)
        ans = min(ans, dp[m - 1][i]);
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