struct MaxMatch {
    int n;
    vector<int> G[N];
    int vis[N], Match[N], clk;
    
    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; i++) G[i].clear();
        fill(vis + 1, vis + n + 1, -1);
        fill(Match + 1, Match + n + 1, -1);
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
                    Match[u] = v;
                    Match[v] = u;
                    return true;
                }
            }
        return false;
    }

    int solve() {
        int res = 0;
        for (int i = 1; i <= n; i++, ++clk) {
            res += dfs(i);
        }
        return res;
    }
} MM;

