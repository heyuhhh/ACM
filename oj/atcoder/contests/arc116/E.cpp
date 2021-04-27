// Author : heyuhhh
// Created Time : 2021/03/29 15:21:12
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
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> f(n); // 最远未覆盖的关键点
    vector<int> g(n); // 最近选择点
    int tot;
    function<void(int, int, int)> dfs = [&] (int u, int fa, int x) {
        f[u] = -INF;
        g[u] = INF;
        for (auto v : G[u]) if (v != fa) {
            dfs(v, u, x);
            f[u] = max(f[u], f[v] + 1);
            g[u] = min(g[u], g[v] + 1);
        }
        if (f[u] + g[u] <= x) {
            f[u] = -INF;
        }
        if (g[u] > x) {
            f[u] = max(f[u], 0);
        }
        if (f[u] == x) {
            g[u] = 0;
            f[u] = -INF;
            ++tot;
        }
    };
    auto check = [&] (int x) {
        tot = 0;
        dfs(0, -1, x);
        if (f[0] >= 0) ++tot;
        return tot <= m;
    };
    int l = 0, r = n + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
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