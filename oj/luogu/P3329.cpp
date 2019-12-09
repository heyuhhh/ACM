/*
 * Author:  heyuhhh
 * Created Time:  2019/10/31 21:20:48
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 155, M = 10005;
#define _S heyuhhh
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow, w;
        Edge(){}
        Edge(int v, int next, T flow, T w) : v(v), next(next), flow(flow), w(w) {}
    }e[M << 1];
    int head[N], tot;
    int dep[N];
    bool vis[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;
    }
    void adde(int u, int v, T w, T rw = 0) {
        e[tot] = Edge(v, head[u], w, w);
        head[u] = tot++;
        e[tot] = Edge(u, head[v], rw, rw);
        head[v] = tot++;
    }
    bool BFS(int _S, int _T) {
        memset(dep, 0, sizeof(dep));
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
        for(int i = head[_S]; ~i; i = e[i].next) {
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
    void color(int u) {
        vis[u] = true;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(vis[v] == false && e[i].flow) color(v);
        }
    }
    void pre() {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < tot; i++) e[i].flow = e[i].w;   
    }
};
Dinic <int> solver;
int n, m;
int c[N][N];
int a[N], ans[N][N];
int tmp1[N], tmp2[N];
void solve(int l, int r) {
    if(l >= r) return;
    solver.pre();
    int S = a[l], T = a[r];
    int d = solver.dinic(S, T);
    solver.color(S);
    for(int i = 1; i <= n; i++) if(solver.vis[i]) {
        for(int j = 1; j <= n; j++) if(!solver.vis[j]) {
            ans[i][j] = ans[j][i] = min(ans[i][j], d);
        }
    }
    int t1 = 0, t2 = 0;
    for(int i = l; i <= r; i++) {
        if(solver.vis[a[i]]) tmp1[++t1] = a[i];
        else tmp2[++t2] = a[i];
    }
    for(int i = l; i <= l + t1 - 1; i++) a[i] = tmp1[i - l + 1];
    for(int i = l + t1; i <= r; i++) a[i] = tmp2[i - t1 - l + 1];
    solve(l, l + t1 - 1); solve(l + t1, r);
}
void run(){
    cin >> n >> m;
    solver.init();
    memset(c, 0, sizeof(c));
    memset(ans, INF, sizeof(ans));
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        c[u][v] += w;
        c[v][u] = c[u][v];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j]) solver.adde(i, j, c[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) a[i] = i;
    solve(1, n);
    int q; cin >> q;
    for(int k = 1; k <= q; k++) {
        int x; cin >> x;
        int res = 0;
        for(int i = 1; i <= n; i++) 
            for(int j = i + 1; j <= n; j++)
                if(ans[i][j] <= x) ++res;
        cout << res << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
	return 0;
}
