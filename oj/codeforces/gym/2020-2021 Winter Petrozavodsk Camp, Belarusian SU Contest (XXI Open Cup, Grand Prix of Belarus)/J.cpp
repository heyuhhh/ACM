// Author : heyuhhh
// Created Time : 2021/02/19 13:20:56
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
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> col(n, -1);
    function<void(int, int)> dfs = [&] (int u, int c) {
        col[u] = c;
        for (auto v : G[u]) {
            if (col[v] == -1) {
                dfs(v, 1 - c);
            } else if (col[v] == col[u]) {
                cout << -1 << '\n';
                exit(0);
            }
        }
    };
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        dfs(i, 0);
    }
    int ans = 0;
    int t0 = 0, t1 = 0;
    vector<bool> vis(n);
    function<void(int)> dfs2 = [&] (int u) {
        if (col[u] == 0) ++t0;
        else ++t1;
        vis[u] = true;
        for (auto v : G[u]) if (!vis[v]) {
            dfs2(v);
        }
    };
    for (int i = 0; i < n; i++) if (!vis[i]) {
        t0 = t1 = 0;
        dfs2(i);
        ans += min(t0, t1);
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