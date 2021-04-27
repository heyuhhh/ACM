// Author : heyuhhh
// Created Time : 2020/12/10 15:53:48
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
    for (int i = 1; i < n; i++) {
        int f;
        cin >> f;
        --f;
        G[f].emplace_back(i);
    }
    vector<vector<int>> ans(n, vector<int>(2));
    function<void(int)> dfs = [&] (int u) {
        if (sz(G[u]) == 0) {
            ans[u][1] = 1;
            return;
        }
        ans[u][0] = 1;
        for (auto v : G[u]) {
            dfs(v);
            ans[u][0] = 1ll * ans[u][0] * (ans[v][0] + ans[v][1]) % MOD;
        }
        int n = sz(G[u]);
        vector<int> pre(n), suf(n);
        pre[0] = (ans[G[u][0]][0] + ans[G[u][0]][1]) % MOD;
        suf[n - 1] = (ans[G[u][n - 1]][0] + ans[G[u][n - 1]][1]) % MOD;
        for (int i = 1; i < n; i++) {
            pre[i] = 1ll * pre[i - 1] * (ans[G[u][i]][0] + ans[G[u][i]][1]) % MOD;
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = 1ll * suf[i + 1] * (ans[G[u][i]][0] + ans[G[u][i]][1]) % MOD;
        }
        for (int i = 0; i < n; i++) {
            int res = ans[G[u][i]][1];
            if (i) res = 1ll * res * pre[i - 1] % MOD;
            if (i + 1 < n) res = 1ll * res * suf[i + 1] % MOD;
            ans[u][1] = (ans[u][1] + res) % MOD;
        }
    };
    dfs(0);
    cout << (ans[0][0] + ans[0][1]) % MOD << '\n';
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