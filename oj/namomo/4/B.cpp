// Author : heyuhhh
// Created Time : 2020/08/15 19:14:03
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
const int N = 1e6 + 5, M = 2e6 + 5;

struct Edge{
    int v, w, next;   
}e[M << 1];
int dis[N];
struct Dijkstra{
    struct node{
        int d, u;
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

int n, m, p;
int d1[N], d2[N];

void run() {
    cin >> n >> m >> p;
    solver.init();
    for (int i = 0; i < p; i++) {
        solver.adde(i, 2 * i % p, 1);
        solver.adde(i, (i + 1) % p, 1);
    }
    solver.dij(n);
    for (int i = 0; i < p; i++) {
        d1[i] = dis[i];
    }
    solver.dij(m);
    for (int i = 0; i < p; i++) {
        d2[i] = dis[i];
    }
    int ans = INF;
    for (int i = 0; i < p; i++) {
        ans = min(ans, d1[i] + d2[i]);
    }
    cout << ans << '\n';
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