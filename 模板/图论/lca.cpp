int f[N][20], deep[N];
 
struct Edge {
    int v, next;   
}e[N << 1];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;   
}
 
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }    
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa) dfs(v, u);
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
    return deep[x] + deep[y] - 2 * deep[z];   
} 
