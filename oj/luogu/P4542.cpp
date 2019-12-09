/*
 * Author:  heyuhhh
 * Created Time:  2019/10/31 10:37:25
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
const int N = 1005, M = 20005;

int n, m, k;

struct E {
    int from, to, cp, v;
    E() {}
    E(int f, int t, int cp, int v) : from(f), to(t), cp(cp), v(v) {}
};

struct MCMF {
    int n, m, s, t;
    vector<E> edges;
    vector<int> G[N];
    bool inq[N];
    int d[N], p[N], a[M];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear(); m = 0;
    }

    void addedge(int from, int to, int cap, int cost) {
        edges.emplace_back(from, to, cap, cost);
        edges.emplace_back(to, from, 0, -cost);
        G[from].push_back(m++);
        G[to].push_back(m++);
    }

    bool BellmanFord(int &flow, int &cost) {
        for(int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof inq);
        d[s] = 0, a[s] = INF, inq[s] = true;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for (int& idx: G[u]) {
                E &e = edges[idx];
                if (e.cp && d[e.to] > d[u] + e.v) {
                    d[e.to] = d[u] + e.v;
                    p[e.to] = idx;
                    a[e.to] = min(a[u], e.cp);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].cp -= a[t];
            edges[p[u] ^ 1].cp += a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int go() {
        int flow = 0, cost = 0;
        while (BellmanFord(flow, cost)); 
        return cost;
    }
} MM;

int g[155][155];

void run(){
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            g[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int S = 2 * n + 2, T = S + 1;
    for(int k = 0; k <= n; k++) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(k <= max(i, j)) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }   
        }
    }
    MM.init(T, S, T);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(g[i][j] != INF) {
                MM.addedge(i + n + 1, j, 1, g[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        MM.addedge(S, i + n + 1, 1, 0);
        MM.addedge(i, T, 1, 0);
    }
    MM.addedge(S, 0 + n + 1, k, 0);
    int ans = MM.go();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
	return 0;
}
