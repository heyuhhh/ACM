/*
 * Author:  heyuhhh
 * Created Time:  2019/10/31 14:47:58
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
const int N = 705, M = 100005;
const double eps = 1e-4;
int n, m;

#define _S heyuhhh
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[M << 1];
    int head[N], tot;
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
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, 1e18);
        return max_flow;
    }
};
Dinic <double> solver;

struct Edge{
    int v, next, t;
    double w;  
}e[M << 1];
int head[N], tot;
void adde(int u, int v, int t, double w) {
    e[tot].v = v; e[tot].t = t; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;
}
int n1, m1;
double v[N];
bool vis[N];
double d[N];
double spfa(int T, double x) {
    for(int i = 1; i <= n; i++) d[i] = 1e18, vis[i] = false ;
    d[n] = 0; vis[n] = true;
    queue <int> q; q.push(n);
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = false;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            double w = e[i].t - 1.0 * x * e[i].w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if(!vis[v]) {
                    vis[v] = true; q.push(v);
                }
            }
            if(v == T && d[v] < eps) return -1;
        }
    }
    return d[T];
}


void run(){
    memset(head, -1, sizeof(head)); tot = 0;
    for(int i = 1; i <= m; i++) {
        int a, b, t, s;
        cin >> a >> b >> t >> s;
        adde(a, b, t, s);
    }
    cin >> m1 >> n1;
    for(int i = 1; i <= n1; i++) {
        double l = 0, r = 1e9;
        while(r - l > eps) {
            double mid = (l + r) / 2;
            if(spfa(i, mid) <= eps) r = mid;
            else l = mid;
        }
        v[i] = r;
    }
    //for(int i = 1; i <= n1; i++) cout << v[i] << ' ';
    //cout << '\n';
    int S = 0, T = n1 + 1;
    solver.init();
    for(int i = 1; i <= n1; i++) {
        if(i & 1) solver.adde(S, i, v[i]);
        else solver.adde(i, T, v[i]);
    }
    for(int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;
        solver.adde(u, v, 1e9);
    }
    double ans = solver.dinic(S, T);
    if(ans >= 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);
    while(cin >> n >> m) run();
	return 0;
}
