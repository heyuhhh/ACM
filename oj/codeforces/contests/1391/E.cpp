// Author : heyuhhh
// Created Time : 2020/09/06 20:35:05
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
    vector<int> d(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++d[u], ++d[v];
    }
    int rt = 0;
    for (int i = 0; i < n; i++)
        if (d[i] > 1) 
            rt = i;
    vector<int> deep(n), up(n), size(n);
    vector<bool> check(n);
    vector<vector<int>> D(n + 1);
    deep[rt] = 1;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        D[deep[u]].push_back(u);
        up[u] = fa;
        size[u] = 1;
        check[u] = true;
        for (auto v : G[u]) if (v != fa && !check[v]) {
            deep[v] = deep[u] + 1;
            dfs(v, u);
            size[u] += size[v];
        }
    };
    dfs(rt, -1);
    int Max = *max_element(all(deep));
    if (Max >= (n + 1) / 2) {
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (deep[i] >= (n + 1) / 2)
                x = i;
        }
        vector<int> path;
        while (x != -1) {
            path.push_back(x);
            x = up[x];
        }
        cout << "PATH" << '\n';
        cout << sz(path) << '\n';
        for (auto& it : path) {
            cout << it + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    vector<pii> pairs;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < sz(D[i]); j += 2) {
            pairs.emplace_back(D[i][j - 1], D[i][j]);
        }
    }
    cout << "PAIRING" << '\n';
    cout << sz(pairs) << '\n';
    for (auto& it : pairs) {
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