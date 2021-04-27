// Author : heyuhhh
// Created Time : 2020/11/19 15:25:54
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

int n, a[N];
vector<int> G[N], V[N];
unordered_map<int, int> mp[2][N];
ll ans;

void dfs(int u, int fa, int bit) {
    int bson = 0, Max = 0;
    mp[0][u].clear(), mp[1][u].clear();
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u, bit);
        if (sz(mp[0][v]) + sz(mp[1][v]) > Max) {
            Max = sz(mp[0][v]) + sz(mp[1][v]);
            bson = v;
        }
    }
    if (bson != 0) {
        mp[0][u].swap(mp[0][bson]);
        mp[1][u].swap(mp[1][bson]);
    }
    ++mp[u >> bit & 1][u][a[u]];
    for (auto v : G[u]) if (v != fa) {
        if (v != bson) {
            for (int k = 0; k < 2; k++) {
                for (auto it : mp[k][v]) {
                    if (mp[k ^ 1][u].find(it.fi ^ a[u]) != mp[k ^ 1][u].end()) {
                        ans += 1ll * (1 << bit) * mp[k ^ 1][u][it.fi ^ a[u]] * it.se;
                    }
                }
            }
            for (int k = 0; k < 2; k++) {
                for (auto it : mp[k][v]) {
                    mp[k][u][it.fi] += it.se;
                }
            }
        }
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int bit = 0; bit < 17; bit++) {
        dfs(1, 0, bit);
    }
    // dfs(1, 0, 0);
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