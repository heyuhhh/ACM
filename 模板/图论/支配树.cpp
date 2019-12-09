/*
	在DAG中，可以直接利用性质来构造，一个点的支配点就为所有能到达它的点在支配树上的LCA，比较好理解。
	
	下面给出一般图构造支配树的算法
*/
namespace LT{
    vector <int> G[N], rG[N];
    vector <int> dt[N];     //dominant tree
    int fa[N], best[N], T, n;
    int semi[N], idom[N], dfn[N], idx[N], f[N];
    void init() {
        T = 0;
        for(int i = 1; i <= n; i++) semi[i] = f[i] = best[i] = i;
        for(int i = 1; i <= n; i++) dt[i].clear();
    }
    void dfs(int u) {
        dfn[u] = ++T; idx[T] = u;;
        for(auto v : G[u]) {
            if(!dfn[v]) {
                fa[v] = u; dfs(v);
            }
        }
    }
    int find(int x) {
        if(f[x] == x) return x;
        int fx = find(f[x]);
        if(dfn[semi[best[f[x]]]] < dfn[semi[best[x]]]) best[x] = best[f[x]];
        return f[x] = fx;
    }
    void Tarjan(int rt) {
        dfs(rt);
        for(int i = T; i >= 2; i--) {
            int x = idx[i];
            for(int &u : rG[x]) {
                if(!dfn[u]) continue; //可能原图不能到达
                find(u);
                if(dfn[semi[x]] > dfn[semi[best[u]]]) semi[x] = semi[best[u]];
            }
            f[x] = fa[x];
            dt[semi[x]].push_back(x);
            x = fa[x];
            for(int &u : dt[x]) {
                find(u);
                if(semi[best[u]] != x) idom[u] = best[u];
                else idom[u] = x;
            }
            dt[x].clear();
        }
        for(int i = 2; i <= T; i++) {
            int x = idx[i];
            if(idom[x] != semi[x]) idom[x] = idom[idom[x]];
            dt[idom[x]].push_back(x);
        }
    }
} 
