// 树链剖分
// 轻边个数为O(logn)，重链个数为O(logn)，top数组记录的为重链顶点 
// 注意bson的初始化，其余可以自动初始化
// 注意每个点实际值为dfn[x]
// 处理一条链的信息，如果两条链就先跳到一条链上去，然后再操作一次就行 
int sz[N], deep[N], bson[N], ff[N];
int top[N], dfn[N], T;
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    sz[u] = 1;
    ff[u] = fa;
    int Max = -1;
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > Max) {
                Max = sz[v];
                bson[u] = v;
            }
        }
    }
}

void dfs(int u, int fa, int topf) {
    dfn[u] = ++T;
    top[u] = topf;
    if (bson[u] != 0) {
        dfs(bson[u], u, topf);
    }
    for (auto v : G[u]) {
        if (v != fa && v != bson[u]) {
            dfs(v, u, v);
        }
    }
} 