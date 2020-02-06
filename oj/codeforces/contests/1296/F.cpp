/*
 * Author:  heyuhhh
 * Created Time:  2020/2/5 0:09:26
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
const int N = 5000 + 5;

int n, m;
vector <int> G[N];
int deep[N], fa[N];
int f[N], e[N][N], id[N][N];
int a[N], b[N], c[N];

void dfs(int u, int p) {
    deep[u] = deep[p] + 1;
    fa[u] = p;
    for(auto v : G[u]) {
        if(v != p) dfs(v, u);
    }
}
void dfs2(int u, int p) {
    for(auto v : G[u]) {
        if(v != p) {
            dfs2(v, u);
            f[id[u][v]] = e[u][v];   
        }
    }   
}
void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        id[u][v] = id[v][u] = i;
    }
    dfs(1, 0);
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i <= m; i++) {
        if(deep[a[i]] < deep[b[i]]) swap(a[i], b[i]);
        int k1 = a[i], k2 = b[i], g = c[i];
        while(deep[k1] != deep[k2]) {
            int to = fa[k1];
            if(e[to][k1] <= g) e[to][k1] = e[k1][to] = g;
            k1 = to;
        }   
        while(k1 != k2) {
            int to1 = fa[k1], to2 = fa[k2];
            if(e[to1][k1] <= g) e[to1][k1] = e[k1][to1] = g;
            if(e[to2][k2] <= g) e[to2][k2] = e[k2][to2] = g;   
            k1 = to1, k2 = to2;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(deep[a[i]] < deep[b[i]]) swap(a[i], b[i]);
        int k1 = a[i], k2 = b[i], g = c[i];
        int Min = INF;
        while(deep[k1] != deep[k2]) {
            int to = fa[k1];
            Min = min(Min, e[to][k1]);
            k1 = to;
        }   
        while(k1 != k2) {
            int to1 = fa[k1], to2 = fa[k2];
            Min = min(Min, min(e[to1][k1], e[to2][k2]));
            k1 = to1, k2 = to2;
        }       
        if(Min != g) {
            cout << -1 << '\n';
            return;   
        }
    }
    dfs2(1, 0);
    for(int i = 1; i < n; i++) if(!f[i]) f[i] = 1000000;
    for(int i = 1; i < n; i++) cout << f[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
