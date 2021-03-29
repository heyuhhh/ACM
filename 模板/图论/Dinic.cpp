#define INF 0x3f3f3f3f
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[M << 1];
    int head[N], cur[N], tot;
    int dep[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;
    }
    void adde(int u, int v, T w, T rw = 0) {
        e[tot] = Edge(v, head[u], w);
        head[u] = tot++;
        e[tot] = Edge(u, head[v], rw);
        head[v] = tot++;
    }
    bool BFS(int _S, int _T) {
        memset(dep, 0, sizeof(dep));
        memcpy(cur, head, sizeof(head));
        queue <int> q; q.push(_S); dep[_S] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].v;
                if(!dep[v] && e[i].flow > 0) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[_T] != 0;
    }
    T dfs(int _S, int _T, T a) {
        T flow = 0, f;
        if(_S == _T || a == 0) return a;
        for(int i = cur[_S]; ~i; i = e[i].next) {
            cur[_S] = i;
            int v = e[i].v;
            if(dep[v] != dep[_S] + 1) continue;
            f = dfs(v, _T, min(a, e[i].flow));
            if(f) {
                e[i].flow -= f;
                e[i ^ 1].flow += f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        if(!flow) dep[_S] = -1;
        return flow;
    }
    T dinic(int _S, int _T) {
        T max_flow = 0;
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, INF);
        return max_flow;
    }
};
