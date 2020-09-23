// Author : heyuhhh
// Created Time : 2020/09/07 09:29:10
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
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dep(n), up(n);
    int L = 0, rt = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        up[u] = fa;
        if (dep[u] > L) {
            L = dep[u];
            rt = u;
        }
        for (auto v : G[u]) if (v != fa) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    dep[rt] = 0;
    int node = rt;
    dfs(rt, -1);
    int x = a, y = b;
    if (dep[a] < dep[b]) 
        swap(a, b);
    while (dep[a] > dep[b]) 
        a = up[a];
    while (a != b)
        a = up[a], b = up[b];
    int dis = dep[x] + dep[y] - 2 * dep[a];
    if (da >= dis || min(L, db) <= 2 * da) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
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