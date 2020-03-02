/*
 * Author:  heyuhhh
 * Created Time:  2020/2/5 21:44:45
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
const int N = 3e5 + 5;

int n, m;

int f[N][20], deep[N];

struct Edge {
    int v, next;   
}e[N << 1];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;   
}

void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa) dfs(v, u);
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

ll ans[N], a[N], b[N];

void dfs2(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa) {
            dfs2(v, u);
            a[u] += a[v], b[u] += b[v];
        }
    }
}

void dfs3(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa) {
            ans[v] = ans[u] + a[v] * (ll)deep[v] + b[v];
            dfs3(v, u);           
        }
    } 
}

void run(){
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adde(u, v); adde(v, u);
    }
    dfs(1, 0);
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }   
    }
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        int lca = LCA(u, v);   
        int l = deep[u] + deep[v] - 2 * deep[lca], x = deep[u] - deep[lca];
        a[u] -= 2, a[v] -= 2, a[lca] += 4;
        b[u] += 2 * deep[u] - l + 1;
        b[v] += 2 * deep[v] - l + 1;
        b[lca] -= 2 * deep[u] + 2 * deep[v] - 2 * l + 2;
        ans[1] += 1ll * x * (l - x);
    }
    dfs2(1, 0);
    dfs3(1, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
