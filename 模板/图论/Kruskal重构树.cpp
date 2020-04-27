vector <int> G[N << 1];
int fa[N << 1], val[N << 1];
int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);   
}

int f[N << 1][20], deep[N << 1], dfn[N << 1], T;
void dfs(int u, int fa) {
    dfn[u] = ++T;
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }   
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
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

void Kruskal (vector <pair<int, pii>>& edges) {
    for (int i = 1; i <= n << 1; i++) {
        fa[i] = i;   
    }
    sort(all(edges), [&] (pair<int, pii> A, pair<int, pii> B) {
        return A.fi > B.fi;        
    });
    int cnt = n;
    for (int i = 0; i < sz(edges); i++) {
        int u = edges[i].se.fi, v = edges[i].se.se, w = edges[i].fi;
        int x = find(u), y = find(v);
        if (x != y) {
            val[++cnt] = w;
            fa[x] = fa[y] = cnt;
            G[cnt].push_back(x);
            G[cnt].push_back(y);
        }
    }
    dfs(cnt, 0);   
}
