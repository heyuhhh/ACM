/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 22:34:43
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
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
const int N = 2e5 + 5;

int n;
int a[N], ans[N];

struct Edge{
    int v, w, next;   
}e[N * 4];
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

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    solver.init();
    for(int i = 1; i <= n; i++) {
        if(i - a[i] >= 1) solver.adde(i - a[i], i, 1);
        if(i + a[i] <= n) solver.adde(i + a[i], i, 1);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] & 1) solver.adde(0, i, 0);
    }
    solver.dij(0);
    for(int i = 1; i <= n; i++) {
        if((a[i] & 1) == 0) {
            ans[i] = (dis[i] == INF ? -1 : dis[i]);
        }
    }
    solver.init();
    for(int i = 1; i <= n; i++) {
        if(i - a[i] >= 1) solver.adde(i - a[i], i, 1);   
        if(i + a[i] <= n) solver.adde(i + a[i], i, 1);
    }
    for(int i = 1; i <= n; i++) {
        if((a[i] & 1) == 0) solver.adde(0, i, 0);
    }
    solver.dij(0);
    for(int i = 1; i <= n; i++) {
        if(a[i] & 1) {
            ans[i] = (dis[i] == INF ? -1 : dis[i]);
        }   
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
