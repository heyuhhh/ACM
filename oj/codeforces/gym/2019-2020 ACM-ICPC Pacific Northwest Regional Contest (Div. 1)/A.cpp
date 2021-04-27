// Author : heyuhhh
// Created Time : 2020/09/26 13:42:30
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
    int n;
    cin >> n;
    vector<int> a(n);
    ll S = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S += a[i];
    }
    vector<vector<pii>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<ll> ans(n), path(n), sum(n);
    
    vector<int> size(n);

    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
        size[u] = 1;
        sum[u] = a[u];
        ans[0] += 1ll * d * a[u];
        path[0] += d;
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (v != fa) {
                dfs(v, u, d + w);
                size[u] += size[v];
                sum[u] += sum[v];
            }
        }
    };
    dfs(0, -1, 0);
    
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (v == fa) continue;
            ans[v] = ans[u] - 1ll * w * sum[v] + 1ll * w * (S - sum[v]);
            path[v] = path[u] - 1ll * size[v] * w + 1ll * (n - size[v]) * w;
            dfs2(v, u);
        }
    };
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        ans[i] += 1ll * a[i] * path[i];
        cout << ans[i] << '\n';
    }
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