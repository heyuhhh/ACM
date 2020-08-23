// 不要忘了dfs前先findroot一次
int n, m;
vector <pii> G[N];
int tsz, rt;
int sz[N], Max[N], father[N];
bool vis[N];
void getrt(int u, int fa) {
    sz[u] = 1; Max[u] = 0;
    for(auto it : G[u]) {
        int v = it.fi, w = it.se;
        if(v == fa || vis[v]) continue;
        getrt(v, u);
        sz[u] += sz[v];
        if(sz[v] > Max[u]) Max[u] = sz[v];
    }
    Max[u] = max(Max[u], tsz - sz[u]);
    if(Max[u] < Max[rt]) rt = u;
}
void findrt(int u, int fa) {
    tsz = (sz[u] == 0 ? n : sz[u]);
    Max[rt = 0] = INF;
    getrt(u, fa);
}
void dfs(int u, int fa) {
    vis[u] = true;
    for(auto it : G[u]) {
        int v = it.fi;
        if(v != fa && !vis[v]) {
            findrt(v, u);
            father[rt] = u;
            dfs(rt, 0);
        }
    }   
}

int f[N][20], deep[N], d[N];
void dfs2(int u, int fa) {
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;   
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }    
    for(auto it : G[u]) {
        int v = it.fi, w = it.se;
        if(v != fa) {
            d[v] = d[u] + w;
            dfs2(v, u);
        }
    }
}
int LCA(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(deep[f[x][i]] >= deep[y]) x = f[x][i];
    }   
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];   
    }
    return f[x][0];
}
 
int dis(int x, int y) {
    int z = LCA(x, y);
    return d[x] + d[y] - 2 * d[z];   
} 