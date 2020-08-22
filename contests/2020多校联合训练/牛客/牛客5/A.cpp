// Author : heyuhhh
// Created Time : 2020/07/25 15:29:35
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
const int N = 300 + 5;
 
int n, m, k;
ll dis[N][N];
ll dp[N << 1][N];
 
void chkmin(ll& x, ll y) {
    if (x > y) x = y;
}
 
void run() {
    cin >> n >> m >> k;
    memset(dis, INF, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int u, v, W;
        cin >> u >> v >> W;
        if ((ll)W <= dis[u][v]) {
            dis[u][v] = dis[v][u] = W;
        }
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    vector<int> vs;
    vs.push_back(1);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        vs.push_back(u);
        vs.push_back(v);
    }
    int sz = sz(vs);
    memset(dp, INF, sizeof(dp));
    ll MAX = ll(0x3f3f3f3f3f3f3f3f);
    dp[0][1] = 0;
    for (int i = 0; i < sz - 1; i++) {
        int u = vs[i], v = vs[i + 1];
        for (int p = 1; p <= n; p++) {
            if (dp[i][p] != MAX) {
                chkmin(dp[i + 1][p], dp[i][p] + dis[u][v]);
                chkmin(dp[i + 1][p], dp[i][p] + dis[p][v]);
                for (int q = 1; q <= n; q++) {
                    chkmin(dp[i + 1][q], min(dp[i][p] + dis[u][q] + dis[p][v], dp[i][p] + min(dis[u][q], dis[p][q]) + dis[q][v]));
                }
            }
        }
    }
    ll ans = MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[sz - 1][i]);
    }
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