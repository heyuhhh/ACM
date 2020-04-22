/*
 * Author:  heyuhhh
 * Created Time:  2020/4/21 23:23:10
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
const int N = 2e5 + 5, M = 2e5 + 5;

int n, m, a, b, c;
int p[N];
struct Edge{
    int v, w, next;   
}e[M << 1];
int dis[N], dis2[N], dis3[N];
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
ll sum[N];
void run() {
    cin >> n >> m >> a >> b >> c;
    for(int i = 1; i <= m; i++) {
        cin >> p[i];   
    }
    sort(p + 1, p + m + 1);
    for(int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    solver.init();
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        solver.adde(u, v, 1);
        solver.adde(v, u, 1);
    }
    solver.dij(c);
    for(int i = 1; i <= n; i++) dis3[i] = dis[i];
    solver.dij(b);
    for(int i = 1; i <= n; i++) dis2[i] = dis[i];
    solver.dij(a);
    ll ans = 1e18;
    for(int i = 1; i <= n; i++) {
        int len = dis[i] + dis2[i] + dis3[i];
        if(len <= m) ans = min(ans, sum[len] + sum[dis2[i]]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
