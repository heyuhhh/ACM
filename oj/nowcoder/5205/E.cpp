/*
 * Author:  heyuhhh
 * Created Time:  2020/4/26 17:05:11
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
const int N = 5e5 + 5;

int n, m, q;
int nodes[N], num;
struct Edge {
    int v, next, w;   
}e[N << 1];
int head[N << 1], tot;
void adde(int u, int v) {
    e[tot].v = v, e[tot].next = head[u], head[u] = tot++;   
}
vector <int> G[N << 1];
int fa[N << 1], val[N << 1];
int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);   
}
int f[N << 1][20], deep[N << 1], dfn[N << 1], T;
void dfs(int u, int fa) {
    dfn[u] = ++T;
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }   
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;   
        if (v != fa) dfs(v, u);
    }
}
int LCA(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(deep[f[x][i]] >= deep[y]) x = f[x][i];
    }  
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];  
    }
    return f[x][0];
}

void Kruskal (vector <pair<int, pii>> edges) {
    for (int i = 1; i <= n << 1; i++) {
        fa[i] = i;   
    }
    sort(all(edges), [&] (pair<int, pii> A, pair<int, pii> B) {
        return A.fi > B.fi;        
    });
    int cnt = n;
    for (int i = 0; i < sz(edges); i++) {
        int u = edges[i].se.fi, v = edges[i].se.se, w = edges[i].fi;
        int x = find(u), y = find(v);
        if (x != y) {
            val[++cnt] = w;
            fa[x] = fa[y] = cnt;
            adde(cnt, x), adde(cnt, y);
        }
    }
    dfs(cnt, 0);   
}

void run () {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> q;
    vector <pair<int, pii>> e;
    for (int i = 1; i <= m; i++) { 
        int u, v, w; cin >> u >> v >> w;
        e.push_back(MP(w, MP(u, v)));
    }
    Kruskal(e);
    int lastans = 0;
    while (q--) {
        int k; cin >> k;
        num = 0;
        for (int i = 1; i <= k; i++) {
            int x; cin >> x; x ^= lastans;
            nodes[++num] = x;
        }
        sort (nodes + 1, nodes + num + 1, [&](int a, int b) {
            return dfn[a] < dfn[b];
        });
        int ans = 0;
        for (int i = 2; i <= num; i++) {
            ans = max(ans, val[LCA(nodes[i - 1], nodes[i])]);
        }
        cout << ans << '\n';
        lastans = ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
