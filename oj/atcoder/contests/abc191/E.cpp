// Author : heyuhhh
// Created Time : 2021/02/06 20:22:14
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2000 + 5, M = 2000 + 5;
struct Edge{
    int v, w, next;   
}e[M << 1];
ll dis[N];
int d[N][N];
struct Dijkstra{
    struct node{
        ll d, u;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    int head[N], tot;
    bool vis[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;   
    }
    void adde(int u, int v, int w) {
        e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;   
    }
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s] = 0;
        q.push(node{0, s});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            int u = cur.u, d = cur.d;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v;
                if(dis[v] > dis[u] + e[i].w) {
                    dis[v] = dis[u] + e[i].w;
                    q.push(node{dis[v], v});   
                }
            }   
        }
    }
}solver;

int n, m;
int W[N][N];

void run() {
    cin >> n >> m;
    solver.init();
    memset(W, INF, sizeof(W));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.adde(u, v, w);
        W[u][v] = min(W[u][v], w);
    }
    for (int i = 1; i <= n; i++) {
        solver.dij(i);
        for (int j = 1; j <= n; j++) {
            d[i][j] = dis[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 1; j <= n; j++) if (W[j][i] != INF) {
             res = min(res, d[i][j] + W[j][i]);
        }
        if (res == INF) res = -1;
        cout << res << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}