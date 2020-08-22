// Author : heyuhhh
// Created Time : 2020/08/11 10:36:47
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

int n, q;
pair<pii, int> edges[N];
vector<pii> G[N];
pii f[N];
ll sum[N];
multiset<int> s[N];
ll ans;

ll calc(int x) {
    int w = f[x].se;
    if (sum[x] <= w) {
        return w - sum[x];
    }
    auto it = s[x].end(); --it;
    int Max = *it;
    if (w + sum[x] - Max >= Max) {
        return -(sum[x] - w) / 2;
    }
    return Max - sum[x];
}

void dfs(int u, int fa, int w) {
    f[u] = MP(fa, w);
    for (auto& it : G[u]) {
        int v = it.fi, W = it.se;
        if (v != fa) {
            sum[u] += W;
            s[u].insert(W);
            dfs(v, u, W);
        }
    }
    ans += calc(u);
}

void run() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = MP(MP(u, v), w);
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
    }
    dfs(1, 0, 0);
    cout << ans << '\n';
    while (q--) {
        int p, w;
        cin >> p >> w;
        int u = edges[p].fi.fi, v = edges[p].fi.se, W = edges[p].se;
        if (f[u].fi != v) swap(u, v);
        ans -= calc(u) + calc(v);

        sum[v] += w - W;
        auto it = s[v].lower_bound(W);
        s[v].erase(it);
        s[v].insert(w);
        f[u].se = w;
        edges[p].se = w;

        ans += calc(u) + calc(v);
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