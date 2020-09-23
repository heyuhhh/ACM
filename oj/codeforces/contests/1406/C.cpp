// Author : heyuhhh
// Created Time : 2020/09/12 22:07:43
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
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> size(n), up(n);
    int Max = INF, x = -1, y = -1;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        up[u] = fa;
        size[u] = 1;
        for (auto& v : G[u]) if (v != fa) {
            dfs(v, u);
            size[u] += size[v];
        }
        int tot = 0;
        int maxv = 0;
        for (auto& v : G[u]) if (v != fa) {
            tot += size[v];
            maxv = max(maxv, size[v]);
        }
        maxv = max(maxv, n - 1 - tot);
        if (Max > maxv) {
            Max = maxv;
            x = u, y = -1;
        } else if (Max == maxv) {
            y = u;
        }
    };
    dfs(0, -1);
    if (n & 1 || y == -1) {
        cout << 2 << ' ' << up[1] + 1 << '\n';
        cout << 2 << ' ' << up[1] + 1 << '\n';
        return;
    }
 
    int lf;
    for (auto v : G[x]) {
        if (v != y) {
            lf = v;
            break;
        }
    }
 
    cout << lf + 1 << ' ' << up[lf] + 1 << '\n';
    cout << lf + 1 << ' ' << y + 1 << '\n';
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