// Author : heyuhhh
// Created Time : 2021/03/27 20:03:27
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
    vector<vector<vector<int>>> G(n, vector<vector<int>>(26));
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        G[u][c - 'a'].emplace_back(v);
        G[v][c - 'a'].emplace_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0][n - 1] = 0;
    queue<pii> que;
    que.emplace(0, n - 1);
    vector<vector<bool>> vis(n, vector<bool>(n));
    while (!que.empty()) {
        pii cur = que.front(); que.pop();
        int s = cur.fi, t = cur.se;
        if (vis[s][t]) continue;
        vis[s][t] = 1;
        for (int c = 0; c < 26; c++) {
            for (auto u : G[s][c]) {
                for (auto v : G[t][c]) {
                    if (dp[u][v] > dp[s][t] + 1) {
                        dp[u][v] = dp[s][t] + 1;
                        que.emplace(u, v);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            for (auto j : G[i][c]) if (dp[i][j] != INF) {
                ans = min(ans, 2 * dp[i][j] + 1);
            }
        }
        ans = min(ans, 2 * dp[i][i]);
    }
    if (ans == INF) ans = -1;
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