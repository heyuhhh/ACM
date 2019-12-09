#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[10005];
int dp[10005][65];
int c[10005];
mt19937 gen(233);

int iteration() {
    memset(dp, -1, sizeof(dp[0]) * (n + 1));
    for (int i = 1; i <= n; i++) {
        c[i] = gen() % k;
        dp[i][1<<c[i]] = 0;
    }
    for (unsigned mask = 0; mask < (1 << k); mask++) {
        for (int v = 1; v <= n; v++) if (mask & (1 << c[v])) {
            for (auto& p : adj[v]) {
                int u, w; tie(u, w) = p;
                if (dp[u][mask ^ (1 << c[v])] >= 0) 
                    dp[v][mask] = max(dp[v][mask], dp[u][mask ^ (1 << c[v])] + w);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][(1 << k) - 1]);
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int ans = 0;
        for (int iter = 0; iter < 250; iter++) ans = max(ans, iteration());
        if (ans == 0) puts("impossible"); else printf("%d\n", ans);
    }
    return 0;
}

