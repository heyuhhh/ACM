/*
 * Author:  heyuhhh
 * Created Time:  2020/5/21 16:59:22
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
const int maxN = 1000 + 5, maxM = 105, MAX = 20005;

int T, N, B;
int c[maxN];
int cost[maxN][maxN], w[maxN][maxN];

struct Point {
    int x, y;
}p[maxN];

int distance(int i, int j) {
    return (int)ceil(hypot(p[i].x - p[j].x, p[i].y - p[j].y) - 1e-9);
}

int dis[maxN][maxM];
struct Dijkstra{
    struct node{
        int val, d, u;
        bool operator < (const node &A) const {
            return val > A.val;
        }
    };
    bool vis[maxN][maxM];
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s][0] = 0;
        q.push(node{0, 0, 0});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            int u = cur.u, d = cur.d;
            if(vis[u][d]) continue;
            vis[u][d] = 1;
            for (int v = 0; v <= N + 1; v++) {
                int dist = w[u][v];
                if (d + dist > B) continue;
                if(dis[v][d + dist] > dis[u][d] + cost[u][v]) {
                    dis[v][d + dist] = dis[u][d] + cost[u][v];
                    q.push(node{dis[v][d + dist], d + dist, v});
                }
            }   
        }
    }
}solver;

void run() {
    cin >> p[0].x >> p[0].y;
    int ex, ey; cin >> ex >> ey;
    cin >> B >> c[0] >> T;
    for (int i = 1; i <= T; i++) {
        cin >> c[i];
    }
    cin >> N;
    vector <pair<int, pii>> edges;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].x >> p[i].y;
        int k; cin >> k;
        while (k--) {
            int j, t; cin >> j >> t; ++j;
            edges.push_back(MP(i, MP(j, t)));
        }
    }
    p[N + 1] = Point{ex, ey};
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            w[i][j] = distance(i, j);
        }
    }
    memset(cost, INF, sizeof(cost));
    for (int i = 1; i <= N; i++) {
        cost[0][i] = c[0] * w[0][i];
        cost[i][N + 1] = c[0] * w[i][N + 1];
    }
    cost[0][N + 1] = c[0] * w[0][N + 1];
    for (auto it : edges) {
        int i = it.fi;
        int j = it.se.fi, t = it.se.se;   
        cost[i][j] = cost[j][i] = min(cost[i][j], c[t] * w[i][j]);
    }
    solver.dij(0);
    int ans = INF;
    for (int i = 0; i <= B; i++) {
        ans = min(ans, dis[N + 1][i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
