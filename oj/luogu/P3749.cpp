/*
 * Author:  heyuhhh
 * Created Time:  2019/10/30 12:45:44
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
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
const int N = 2e4 + 5;

#define _S heyuhhh
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[N * 10];
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
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, INF);
        return max_flow;
    }
};
Dinic <int> solver;

int n, m;
int a[105], Id[105][105], F[105][105];

void run(){
    solver.init();
    int Max = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];   
        Max = max(a[i], Max);
    }
    int cnt = 2;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            cin >> F[i][j];
            Id[i][j] = ++cnt;
        }
    }
    int S = 1, T = 2;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int cost = F[i][j];
            if(i == j) {
                if(m) solver.adde(Id[i][j], cnt + a[i], INF);
                cost -= a[i];
            } else {
                solver.adde(Id[i][j], Id[i][j - 1], INF);
                solver.adde(Id[i][j], Id[i + 1][j], INF);
            }
            if(cost > 0) solver.adde(S, Id[i][j], cost), ans += cost;
            else solver.adde(Id[i][j], T, -cost);
        }
    }
    for(int i = 1; i <= Max; i++) {
        solver.adde(++cnt, T, m * i * i);
    }
    dbg(1);
    ans -= solver.dinic(S, T);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
	return 0;
}
