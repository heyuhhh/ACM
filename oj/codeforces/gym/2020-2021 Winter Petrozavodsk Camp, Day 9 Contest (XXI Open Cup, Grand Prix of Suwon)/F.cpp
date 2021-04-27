// Author : heyuhhh
// Created Time : 2021/03/17 19:47:31
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> P(n);
    vector<bool> vis(n);
    vector<int> circle;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        vis[u] = true;
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (v != fa) {
                if (!vis[v]) {
                    P[v] = (P[u] ^ w);
                    dfs(v, u);
                } else {
                    circle.emplace_back(P[v] ^ P[u] ^ w);
                }
            }
        }
    };
    dfs(0, -1);
    vector<int> b(32);
    auto insert = [&] (int x) {
        for (int i = 31; i >= 0; i--) if (x >> i & 1) {
            if (b[i]) x ^= b[i];
            else {
                b[i] = x;
                break;
            }
        }
    };
    for (auto& it : circle) {
        insert(it);
    }
    for (int i = 31; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) if (b[i] >> j & 1) {
            b[i] ^= b[j];
        }
    }
    vector<vector<int>> sum(n + 1, vector<int>(32));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            sum[i + 1][j] = sum[i][j] + (P[i] >> j & 1);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            ll s1 = sum[r][i] - sum[l - 1][i];
            ll s0 = r - l + 1 - s1;
            if ((s1 * (s1 - 1) / 2 + s0 * (s0 - 1) / 2) & 1) {
                ans ^= b[i];
            }
            if ((s0 * s1) & 1) {
                ans ^= (1 << i);
            }
        }
        cout << ans << '\n';
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