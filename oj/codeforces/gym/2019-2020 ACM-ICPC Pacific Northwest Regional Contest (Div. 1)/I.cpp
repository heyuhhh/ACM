// Author : heyuhhh
// Created Time : 2020/09/26 14:15:55
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

struct MaxMatch {
    int n, m;
    vector<int> G[N];
    int vis[N], Match[N], clk;
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        fill(vis, vis + n, -1);
        fill(Match, Match + n, -1);
    }
    
    void adde(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool dfs(int u) {
        for (int v: G[u])
            if (vis[v] != clk) {
                vis[v] = clk;
                if (Match[v] == -1 || dfs(Match[v])) {
                    Match[v] = u;
                    Match[u] = v;
                    return true;
                }
            }
        return false;
    }
    
    int solve(vector<int>& points) {
        int res = 0;
        for (int i = 0; i < sz(points); ++i, ++clk) if (vis[points[i]] == -1) {
            res += dfs(points[i]);
        }
        return res;
    }
} MM;

void run() {
    int n;
    cin >> n;
    MM.init(n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m = s[0].length();
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                if (s[i][k] != s[j][k]) ++cnt;
            }
            if (cnt == 2) {
                MM.adde(i, j);
                G[i].emplace_back(j);
                G[j].emplace_back(i);
            }
        }
    }
    
    vector<int> points;
    vector<bool> vis(n);
    function<void(int)> dfs = [&] (int u) {
        vis[u] = true;
        points.emplace_back(u);
        for (auto v : G[u]) if (!vis[v]) {
            dfs(v);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            points.clear();
            dfs(i);
            ans += sz(points) - MM.solve(points);
        }
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