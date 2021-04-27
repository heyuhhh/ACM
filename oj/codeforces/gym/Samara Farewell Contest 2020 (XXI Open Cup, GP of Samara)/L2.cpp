// Author : heyuhhh
// Created Time : 2021/03/10 15:42:45
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> last(k + 2, n + 1);
    vector<int> nxt(n + 1), nxt2(n + 1);
    for (int i = n; i >= 0; i--) {
        nxt[i] = last[a[i] + 1];
        nxt2[i] = last[a[i]];
        last[a[i]] = i;
    }
    vector<int> dp(n + 1, INF);
    vector<int> from(n + 1);
    int ans = INF, p;
    dp[0] = 0;
    for (int i = 0; i <= n; i++) if (dp[i] != INF) {
        int to = nxt[i];
        if (to <= n && dp[to] > dp[i]) {
            dp[to] = dp[i];
            from[to] = from[i];
        }
        int to2 = nxt2[i];
        if (to2 <= n && dp[to2] > dp[i] + 1) {
            dp[to2] = dp[i] + 1;
            from[to2] = i;
        }
        if (a[i] < k && to > n) {
            if (dp[i] < ans) {
                ans = dp[i];
                p = from[i];
            }
        }
        if (a[i] && to2 > n) {
            if (dp[i] + 1 < ans) {
                ans = dp[i] + 1;
                p = i;
            }
        }
        // cout << ans << '\n';
    }
    // cout << p << ' ' << dp[p] << '\n';
    if (ans == INF) {
        cout << 0 << '\n';
    } else {
        vector<int> res;
        while (p) {
            res.emplace_back(p);
            p = from[p];
        }
        reverse(all(res));
        cout << ans << '\n';
        for (auto& it : res) {
            cout << it << ' ';
        }
    }
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