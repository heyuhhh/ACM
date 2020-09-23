// Author : heyuhhh
// Created Time : 2020/09/09 11:25:07
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
    vector<vector<pii>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        G[v].emplace_back(u, t);
    }
    vector<int> col(n, -1), dis(n, INF);
    vector<bool> vis(n);
    queue<int> q;
    dis[n - 1] = col[n - 1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        vis[v] = true;
        for (auto& it : G[v]) {
            int u = it.fi, t = it.se;
            if (vis[u]) continue;
            if (col[u] == -1) {
                col[u] = 1 - t;
            } else {
                if (col[u] == t && dis[u] > dis[v] + 1) {
                    dis[u] = dis[v] + 1;
                    q.push(u);
                }
            }
        }
    }
    int ans = dis[0];
    if (ans == INF) ans = -1;
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << max(0, col[i]);
    cout << '\n';
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