// Author : heyuhhh
// Created Time : 2020/09/22 14:46:09
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
void run(int Case) {
    int n, m, R, B;
    cin >> n >> m >> R >> B;
    vector<bool> op(n);
    for (int i = 0; i < B; i++) {
        int x;
        cin >> x;
        --x;
        op[x] = 1;
    }
    vector<int> dis(n);
    for (int i = 0; i < n; i++) {
        cin >> dis[i];
    }
    vector<vector<int>> G(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[v].emplace_back(u);
        ++deg[u];
    }
    priority_queue<pii> que;
    for (int i = 0; i < n; i++) {
        que.emplace(dis[i], i);
    }
    
    vector<int> white_d(n, R + 1), white_deg(n);
    vector<bool> vis(n);
    while (!que.empty()) {
        auto cur = que.top(); que.pop();
        int u = cur.se, d = cur.fi;
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto v : G[u]) if (!vis[v]) {
            if (op[v]) {
                if (d > dis[v]) {
                    dis[v] = d;
                    que.emplace(dis[v], v);
                }
            } else if (white_deg[v] != -1) {
                ++white_deg[v];
                white_d[v] = min(white_d[v], d);
                if (d <= dis[v]) {
                    white_deg[v] = -1;
                }
                if (white_deg[v] == deg[v]) {
                    dis[v] = max(dis[v], white_d[v]);
                    que.emplace(dis[v], v);
                    white_deg[v] = -1;
                }
            }
        }
    }
    cout << "Case #" << Case << ":" << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << dis[i];
    }
    cout << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        run(i);
    }
    return 0;
}