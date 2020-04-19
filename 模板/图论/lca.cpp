int f[N][20], deep[N];
vector <int> G[N];
void dfs(int u, int fa) {
    in[u] = ++T;
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }   
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
    }
    out[u] = T;
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
    return deep[x] + deep[y] - 2 * deep[z];  
} 
