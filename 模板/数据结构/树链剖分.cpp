void dfs1(int u, int pa, int d) {
    deep[u] = d;
    fa[u] = pa;
    sz[u] = 1;
    int mx = -1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == pa) continue ;
        dfs1(v, u, d + 1) ;
        sz[u] += sz[v] ;
        if(sz[v] > mx) mx = sz[v], son[u] = v;
    }
}
void dfs2(int u, int topf) {
    id[u] = ++cnt;
    v[cnt] = w[u] ;
    top[u] = topf;
    if(!son[u]) return ;
    dfs2(son[u], topf) ;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != son[u] && v != fa[u]) dfs2(v, v) ;
    }
} 
