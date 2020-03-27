/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 9:20:22
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
  void err() { std::cout << '\n'; }
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
const int N = 2e5 + 5;

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
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }    
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
 
int dis(int x, int y) {
    int z = LCA(x, y);
    return deep[x] + deep[y] - 2 * deep[z];   
} 

void run() {
    int n, m; cin >> n >> m;
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adde(u, v), adde(v, u);
    }
    dfs(1, 0);
    while(m--) {
        int k; cin >> k;
        vector <int> v(k);
        for(int i = 0; i < k; i++) cin >> v[i];
        sort(all(v), [&](int a, int b) {
            return deep[a] > deep[b];
        });   
        int p = v[0];
        bool ok = true;
        for(int i = 1; i < k; i++) {
            int lca = LCA(p, v[i]);
            //dbg(lca, deep[v[i]], deep[lca]);
            if(deep[v[i]] - deep[lca] > 1) ok = false;
        }
        if(ok) cout << "YES" << '\n';
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
