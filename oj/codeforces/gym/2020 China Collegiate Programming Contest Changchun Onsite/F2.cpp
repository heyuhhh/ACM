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
vector<int> G[N];
map<pii, int> mp[N];
ll ans;

void dfs(int u, int fa, int bit) {
    int bson = 0, Max = 0;
    mp[u].clear();
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u, bit);
        if (sz(mp[v]) > Max) {
            Max = sz(mp[v]);
            bson = v;
        }
    }
    if (bson != 0) mp[u].swap(mp[bson]);
    ++mp[u][MP(a[u], u >> bit & 1)];
    for (auto v : G[u]) {
        if (v != bson) {
            for (auto it : mp[v]) {
                int now = (it.fi.fi ^ a[u]);
                if (mp[u].find(MP(now, it.fi.se ^ 1)) != mp[u].end()) {
                    ans += 1ll * mp[u][MP(now, it.fi.se ^ 1)] * it.se * (1 << bit);
                }
            }
            for (auto it : mp[v]) {
                mp[u][it.fi] += it.se;
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