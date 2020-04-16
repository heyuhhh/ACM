/*
 * Author:  heyuhhh
 * Created Time:  2020/4/10 19:29:43
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5, M = 2e5 + 5;

int n, m;
struct Edge{
    int v, w, next;   
}e[M << 1];
struct EDGE {
    int u, v, w;   
}E[M];
ll dis[N], rdis[N];
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
void run() {
    cin >> n >> m;
    solver.init();
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        solver.adde(u, v, w);
        E[i] = EDGE{u, v, w};
    }
    solver.dij(1);
    for(int i = 1; i <= n; i++) rdis[i] = dis[i];
    solver.init();
    for(int i = 1; i <= m; i++) {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        solver.adde(v, u, w);   
    }
    solver.dij(n);
    for(int i = 1; i <= n; i++) swap(dis[i], rdis[i]);
    int q; cin >> q;
    while(q--) {
        int id; cin >> id;
        int u = E[id].u, v = E[id].v, w = E[id].w;
        ll now = dis[v] + rdis[u] + w;
        if(now < dis[n]) cout << "YES" << '\n';
        else cout << "NO" << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
