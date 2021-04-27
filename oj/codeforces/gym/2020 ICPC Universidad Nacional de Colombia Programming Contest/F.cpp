// Author : heyuhhh
// Created Time : 2021/03/06 14:29:43
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
struct node {
    int dis;
    int u, k;
    bool operator < (const node& A) const {
        return dis > A.dis;
    }
};
void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> G(n), rG(n);
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        rG[v].emplace_back(u, w);
    }
    auto dij = [&] (int s, vector<vector<pii>>& G) {
        vector<vector<int>> d(n, vector<int>(k + 1, INF));
        d[s][0] = 0;
        priority_queue<node> que;
        que.emplace(node{0, s, 0});
        vector<vector<bool>> vis(n, vector<bool>(k + 1));
        while (!que.empty()) {
            node cur = que.top(); que.pop();
            int u = cur.u, nk = cur.k;
            if (vis[u][nk]) continue;
            vis[u][nk] = true;
            for (auto it : G[u]) {
                int v = it.fi, w = it.se;
                if (nk + 1 <= k && d[v][nk + 1] > d[u][nk]) {
                    d[v][nk + 1] = d[u][nk];
                    que.emplace(node{d[v][nk + 1], v, nk + 1});
                }
                if (d[v][nk] > d[u][nk] + w) {
                    d[v][nk] = d[u][nk] + w;
                    que.emplace(node{d[v][nk], v, nk});
                }
            }
        }
        return d;
    };
    auto solve = [&] (vector<vector<pii>>& G) {
        vector<vector<vector<int>>> d(2);
        d[0] = dij(a, G);
        d[1] = dij(b, G);
        return d;
    };
    vector<vector<vector<vector<int>>>> d(2);
    d[0] = solve(G);
    d[1] = solve(rG);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int p = 0; p < n; p++) {
                for (int t = 1; t <= k; t++) {
                    d[i][j][p][t] = min(d[i][j][p][t], d[i][j][p][t - 1]);
                }
            }
        }
    }
    int ans = INF, id = -1;
    for (int i = 0; i < n; i++) if (i != a && i != b) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, d[0][0][i][j] + d[1][0][i][k - j]);
        }
        int res2 = INF;
        for (int j = 0; j <= k; j++) {
            res2 = min(res2, d[0][1][i][j] + d[1][1][i][k - j]);
        }
        if (res + res2 < ans) {
            ans = res + res2;
            id = i;
        }
    }
    if (ans == INF) cout << ">:(" << '\n';
    else cout << id << ' ' << ans << '\n';
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