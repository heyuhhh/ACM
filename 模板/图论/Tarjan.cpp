/*
	Tarjan算法，复杂度$O(n)$，能够求出有向图的极大强连通分量。
*/
stack <int> s;
int T, num;
int scc[N], dfn[N], low[N], vis[N];
void Tarjan(int u){
    dfn[u] = low[u] = ++T; vis[u] = 1;
    s.push(u);
    for(int i = head[u]; i != -1;i = e[i].next){
        int v = e[i].v;
        if(!vis[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        num++; int now;
        do{
            now = s.top(); s.pop();
            scc[now] = num;
        }while(!s.empty() && now!=u);
    }
}
