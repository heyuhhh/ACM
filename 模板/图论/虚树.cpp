int in[N], out[N], T;
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
 
int V[N << 1], tot;
vector <int> vt[N];
void clear() {
    for(int i = 1; i <= tot; i++) vt[V[i]].clear();  
}
int buildVT(vector<int>& nodes) {
    static int st[N], top;
    auto cmp = [&](int x, int y) {
        return in[x] < in[y];
    };
    auto chk = [&](int x, int y) {
        return in[y] >= in[x] && in[y] <= out[x];
    };
     
    tot = 0;
    for(auto it : nodes) V[++tot] = it;
    sort(V + 1, V + 1 + tot, cmp);
    for(int i = 1, tmp = tot; i < tmp; i++) V[++tot] = LCA(V[i], V[i + 1]);
    sort(V + 1, V + 1 + tot, cmp);
    tot = unique(V + 1, V + 1 + tot) - V - 1;
 
    st[top = 1] = V[1];
    for(int i = 2; i <= tot; i++) {
        while(top > 1 && !chk(st[top], V[i])) --top;
        vt[st[top]].push_back(V[i]);  
        st[++top] = V[i];
    }
    return V[1];
}
