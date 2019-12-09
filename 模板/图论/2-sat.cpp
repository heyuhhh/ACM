/*
	通过在反图上求强连通分量，优先选择序号较大者。
*/
vector<int> G[N], rG[N], vs;
int used[N], bel[N];

void adde(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for(int u: G[v]) {
        if(!used[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    bel[v] = k;
    for(int u: rG[v])
        if(!used[u])
            rdfs(u, k);
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < n; ++v)
        if(!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = (int) vs.size() - 1; i >= 0; --i)
        if(!used[vs[i]]) rdfs(vs[i], k++);
    return k;
}
