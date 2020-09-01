// Author : heyuhhh
// Created Time : 2020/07/18 10:10:42
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
    vector<int> in(n), out(n);
    vector<pii> edges;
    for (int i = 1; i <= m; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        --u, --v;
        if (op) {
            G[u].push_back(v);
            ++out[u], ++in[v];
        } else {
            edges.push_back(MP(u, v));
        }
    }
    vector<int> vis(n);
    function <void(int)> dfs;
    bool flag = true;
    dfs = [&] (int u) {
        vis[u] = 2;
        for (auto v : G[u]) {
            if (vis[v] == 2) {
                flag = false;
                return;
            }
            if (vis[v]) {
                continue;
            }
            dfs(v);
        }
        vis[u] = 1;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    if (!flag) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    vector<vector<pii>> G2(n);
    int t = 0;
    for (auto it : edges) {
        int u = it.fi, v = it.se;
        G2[u].push_back(MP(v, t));
        G2[v].push_back(MP(u, t));
        ++t;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<pii> ans;
    vector<bool> check(m + 1);
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (auto v : G[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
            ans.push_back(MP(u, v));
        }
        for (auto it : G2[u]) {
            int v = it.fi, id = it.se;
            if (check[id]) continue;
            check[id] = true;
            ans.push_back(MP(u, v));
        }
    }
    t = 0;
    for (auto it : edges) {
        if (check[t]) {
            ++t;
            continue;
        }
        int u = it.fi, v = it.se;
        if (in[u] == 0 || out[v] == 0) {
            cout << u + 1 << ' ' << v + 1 << '\n';
            ++out[u], ++in[v];
        } else if (out[u] == 0 || in[v] == 0) {
            cout << v + 1 << ' ' << u + 1 << '\n';
            ++out[v], ++in[u];
        }
        ++t;
    }
    for (auto it : ans) {
        cout << it.fi + 1 << ' ' << it.se + 1 << '\n';
    }
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