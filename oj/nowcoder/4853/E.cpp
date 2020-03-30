/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 20:47:34
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
const int N = 1e5 + 5;
int n, k;
int a[N];
struct Edge{
    int v, next;
}e[N << 1];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;
}
int Son[N], sz[N], deep[N];
void dfs(int u, int fa) {
    int mx = 0, son = 0;
    sz[u] = 1;
    deep[u] = deep[fa] + 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > mx) mx = sz[v], son = v;
    }
    Son[u] = son;
}
ll ans[N];
map <int, pair<ll, int>> mp;
void add(int u, int fa, int p, int op) {
    if(op == 2) {
        int now = deep[u] - deep[p];
        if(k > now) {
            int delta = k - now;
            if(mp.find(deep[p] + delta) != mp.end()) {
                pair <ll, int> tmp = mp[deep[p] + delta];
                ans[p] += tmp.fi + 1ll * tmp.se * a[u];                     
            }
        }
    } else {
        mp[deep[u]].fi += op * a[u], mp[deep[u]].se += op;
    }
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        add(v, u, p, op);
    }
}
void dfs2(int u, int fa, int op) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa || v == Son[u]) continue;
        dfs2(v, u, 0);
    }
    if(Son[u]) dfs2(Son[u], u, 1);
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa || v == Son[u]) continue;
        add(v, u, u, 2);
        add(v, u, u, 1);
    }
    mp[deep[u]].fi += a[u], mp[deep[u]].se++;
    if(!op) add(u, fa, u, -1);
}
void run() {
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;   
        adde(u, v), adde(v, u);
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
