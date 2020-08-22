// Author : heyuhhh
// Created Time : 2020/08/04 19:16:59
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;
void run() {
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> G(n);
    vector<int> d(n);
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        --u, --v;
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
        ++d[u], ++d[v];
    }
    if (*max_element(all(d)) <= k) {
        cout << sum << '\n';
        return;
    }
    if (k == 0) {
        cout << 0 << '\n';
        return;
    }
    if (k == 1) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll res = 0;
            for (auto it : G[i]) {
                int v = it.fi, w = it.se;
                res += w;
            }
            ans = max(ans, res);
        }
        cout << ans << '\n';
        return;
    }

    vector<vector<ll>> dp(n, vector<ll>(2));

    function<ll(int, int, int)> calc = [&](int u, int c, int fa) {
        vector<pair<ll, pair<int, int>>> dp0;
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (v != fa) {
                dp0.push_back(MP(dp[v][0] + w, MP(v, w)));
            }
        }
        sort(dp0.rbegin(), dp0.rend());
        ll res = 0, Max = -1e18;
        for (int i = 0; i < min(sz(dp0), c); i++) {
            res += dp0[i].fi;
        }
        for (int i = c; i < sz(dp0); i++) {
            int v = dp0[i].se.fi, w = dp0[i].se.se;
            Max = max(Max, dp[v][1] + w);
        }
        if (sz(dp0) >= c + 1) {
            for (int i = 0; i < c; i++) {
                int v = dp0[i].se.fi;
                Max = max(Max, -dp[v][0] + dp[v][1] + dp0[c].fi);
            }
        } else {
            for (int i = 0; i < sz(dp0); i++) {
                int v = dp0[i].se.fi;
                Max = max(Max, -dp[v][0] + dp[v][1]);
            }
        }
        res += Max;
        return res;
    };

    ll ans = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        vector<pair<ll, int>> dp0;
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (v != fa) {
                dfs(v, u);
                dp[u][1] += dp[v][0] + w;
                dp0.push_back(MP(dp[v][0] + w, v));
            }
        }
        sort(dp0.rbegin(), dp0.rend());
        for (int i = 0; i < min(sz(dp0), k - 1); i++) {
            dp[u][0] += dp0[i].fi;
        }
        dp[u][1] = max(dp[u][1], calc(u, k - 2, fa));
        ans = max(ans, max(dp[u][1], calc(u, k - 1, fa)));
    };

    dfs(0, 0);
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}