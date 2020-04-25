auto cmp = [&](int x, int y) {
    return deg[x] != deg[y] ? deg[x] > deg[y] : x < y;   
}
for (int i = 1; i <= m; i++) {
    if(cmp(u[i], v[i])) G[u[i]].push_back(v[i]);   
    else G[v[i]].push_back(u[i]);
}
int ans = 0;
for (int i = 1; i <= nl i++) {
    for (auto u : G[i]) {
        vis[u] = i;
    }
    for (auto u : G[i]) {
        for (auto v : G[u]) {
            if (vis[v] == i) {
                ++ans;
            }   
        }
    }   
}
