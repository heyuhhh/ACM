ll *f[N], *g[N], ans;
ll tmp[N << 2], *id = tmp;

int len[N], bson[N];
void dfs(int u, int fa) {
    int Max = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        if (len[v] > Max) {
            Max = len[v];
            bson[u] = v;
        }
    }
    len[u] = len[bson[u]] + 1;
}
void dfs2(int u, int fa) {
    f[u][0] = 1;
    if (bson[u]) {
        //处理重链
        int v = bson[u];
        f[v] = f[u] + 1;
        g[v] = g[u] - 1;
        dfs2(v, u);
    }
    ans += g[u][0];
    for (auto v : G[u]) {
        if (v == fa || v == bson[u]) continue;
        //分配空间
        f[v] = id, id += (len[v] << 1);
        g[v] = id, id += (len[v] << 1);
        dfs2(v, u);
        //从轻链转移
        for (int i = 0; i < len[v]; i++) {
            ans += f[v][i] * g[u][i + 1];
            if (i) {
                ans += f[u][i - 1] * g[v][i];
            }
        }
        for (int i = 1; i <= len[v]; i++) {
            if (i < len[v]) {
                g[u][i - 1] += g[v][i];
            }
            g[u][i] += f[u][i] * f[v][i - 1];
            f[u][i] += f[v][i - 1];
        }
    }
}

dfs(1, 0);
f[1] = id, id += (len[1] << 1);
g[1] = id, id += (len[1] << 1);
dfs2(1, 0);
