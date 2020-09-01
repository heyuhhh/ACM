// Author : heyuhhh
// Created Time : 2020/08/22 10:17:09
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
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
    vector<int> size(n);
    vector<ll> t;
    function<void(int, int)> dfs = [&](int u, int fa) {
        size[u] = 1;
        for (auto v : G[u]) {
            if (v != fa) {
                dfs(v, u);
                size[u] += size[v];
            }
        }
        if (u != 0) {
            t.push_back(1ll * size[u] * (n - size[u]));
        }
    };
    dfs(0, 0);
    sort(t.rbegin(), t.rend());
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());

    int q = 0;
    int ans = 0;
    int r = n - 2;
    for (int i = 0; i < sz(t); i++) {
        if (q >= sz(p)) {
            ans = (ans + t[i]) % MOD;
            continue;
        }
        int res = p[q];
        while (q + 1 < sz(p) && sz(p) - q - 2 >= r) {
            res = 1ll * res * p[++q] % MOD;
        }
        ans = (ans + 1ll * res * t[i] % MOD) % MOD;
        --r, ++q;
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}