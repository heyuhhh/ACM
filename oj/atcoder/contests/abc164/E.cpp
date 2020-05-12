/*
 * Author:  heyuhhh
 * Created Time:  2020/5/6 21:58:12
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
const int N = 55, MAX = 5000;

int n, m, S;
int C[N], D[N];
struct Edge{
    int v, A, B, next;   
}e[N << 2];
ll dis[N][MAX];
struct Dijkstra{
    struct node{
        ll d;
        pii f;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    int head[N], tot;
    bool vis[N][MAX];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;   
    }
    void adde(int u, int v, int A, int B) {
        e[tot] = Edge {v, A, B, head[u]};
        head[u] = tot++;   
    }
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s][S] = 0;
        q.push(node{0, MP(s, S)});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            int u = cur.f.fi, sta = cur.f.se;
            ll d = cur.d;
            if(vis[u][sta]) continue;
            vis[u][sta] = 1;
            int to = min(MAX - 1, sta + C[u]);
            if (dis[u][to] > dis[u][sta] + D[u]) {
                dis[u][to] = dis[u][sta] + D[u];  
                q.push(node{dis[u][to], MP(u, to)});
            }
            for(int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v, A = e[i].A, B = e[i].B;
                if(sta >= A && dis[v][sta - A] > dis[u][sta] + B) {
                    dis[v][sta - A] = dis[u][sta] + B;
                    q.push(node{dis[v][sta - A], MP(v, sta - A)});   
                }
            }   
        }
    }
}solver;

void run() {
    cin >> n >> m >> S;
    S = min(S, MAX - 1); 
    solver.init();
    for (int i = 1; i <= m; i++) {
        int u, v, A, B; cin >> u >> v >> A >> B;
        solver.adde(u, v, A, B); 
        solver.adde(v, u, A, B);   
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    solver.dij(1);
    for (int i = 2; i <= n; i++) {
        ll ans = 1e18;
        for (int j = 0; j < MAX; j++) {
            ans = min(ans, dis[i][j]);
        }   
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
