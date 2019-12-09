/*
 * Author:  heyuhhh
 * Created Time:  2019/11/27 14:23:05
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstdio>
#include <cstring>
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
const int N = 1005, M = 3005, P = 11;

int n, m, p;
int c[P], d[P];

struct Edge {
    int v, w, next;   
}e[M << 1];
int head[N], tot;
void adde(int u, int v, int w) {
    e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;   
}
int dp[N][1 << P];
queue <int> q;
bool in[N], chk[N];
void spfa(int s) {
    while(!q.empty()) {
        int u = q.front(); q.pop(); in[u] = 0;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(dp[v][s] > dp[u][s] + e[i].w) {
                dp[v][s] = dp[u][s] + e[i].w;
                if(!in[v]) q.push(v), in[v] = 1;   
            }
        }
    }
}
int g[1 << P], sum[P], tmp[P];
bool ok(int s) {
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i <= p; i++) if((s >> (i - 1)) & 1) ++tmp[d[i]];
    for(int i = 1; i <= p; i++) if(tmp[d[i]] && tmp[d[i]] != sum[d[i]]) return false;
    return true;
}
void run(){
    memset(head, -1, sizeof(head)); tot = 0;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adde(u, v, w); adde(v, u, w);
    }
    memset(dp, INF, sizeof(dp));
    memset(g, INF, sizeof(g));
    for(int i = 1; i <= p; i++) {
        cin >> d[i] >> c[i];
        dp[c[i]][1 << (i - 1)] = 0;
        ++sum[d[i]];
    }
    int lim = (1 << p);
    for(int S = 1; S < lim; S++) {
        for(int i = 1; i <= n; i++) {
            for(int s = (S - 1) & S; s; s = (s - 1) & S) {
                dp[i][S] = min(dp[i][S], dp[i][s] + dp[i][S - s]);
            }
            if(dp[i][S] < INF) q.push(i), in[i] = 1;
        }
        spfa(S);
        for(int i = 1; i <= n; i++) g[S] = min(g[S], dp[i][S]);
    }
    for(int i = 1; i < lim; i++) if(ok(i)) {
        for(int j = i; j; j = (j - 1) & i) if(ok(j)){
            g[i] = min(g[i], g[j] + g[i ^ j]);
        }
    }
    cout << g[lim - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> p) run();
    return 0;
}
