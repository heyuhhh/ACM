// Author : heyuhhh
// Created Time : 2020/07/14 20:52:56
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
const int N = 500 + 5, M = 252000 + 5;

int n, m;
int grid[N][N];
int T, s, t;

struct Edge{
    int v, w, next;   
}e[M << 1];
ll dis[M];
struct Dijkstra{
    struct node{
        ll d, u;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    int head[M], tot;
    bool vis[M];
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

void run() {
    solver.init();
    cin >> n >> m;
    s = ++T, t = ++T;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            grid[i][j] = ++T;
        }
    }
    for (int i = 2; i <= n; i++) {
        grid[0][i] = s;
    }
    for (int i = 1; i < n; i++) {
        grid[i][n + 1] = t;
    }
    while (m--) {
        int l, r, c;
        string dir;
        cin >> l >> r >> dir >> c;
        if (dir == "L") {
            solver.adde(grid[l][r], grid[l][r + 1], c);
            solver.adde(grid[l][r + 1], grid[l][r], c);
        } else {
            solver.adde(grid[l - 1][r], grid[l][r], c);
            solver.adde(grid[l][r], grid[l - 1][r], c);
        }
    }
    solver.dij(s);
    ll ans = dis[t];
    if (ans >= 10000000000) {
        ans = -1;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}