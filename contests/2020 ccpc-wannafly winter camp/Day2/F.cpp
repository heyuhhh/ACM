/*
 * Author:  heyuhhh
 * Created Time:  2020/2/8 8:47:20
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
const int N = 1e6 + 5;

int n, q;
struct Edge {
    int v, w, next;   
}e[N << 1];
int head[N], tot;
void adde(int u, int v, int w) {
    e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;   
}

int dfn, T;
int l[N], r[N], fa[N], w[N];
int bson[N], sz[N], top[N];

void dfs(int u, int f, int v) {
    int Max = 0;
    sz[u] = 1;
    l[u] = ++dfn;
    fa[u] = f, w[u] = v;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == f) continue;
        dfs(v, u, e[i].w);   
        if(sz[v] > Max) {
            bson[u] = v;
            Max = sz[v];   
        }
        sz[u] += sz[v];
    }
    r[u] = dfn;
}

ll c[N];
int lowbit(int x) {return x & (-x);}
void add(int x, int v) {
    for(; x <= n; x += lowbit(x)) c[x] += v;
}
ll query(int x) {
    ll res = 0;
    for(; x > 0; x -= lowbit(x)) res += c[x];
    return res;
}
ll query(int L, int R) {
    return query(R) - query(L - 1);   
}

void dfs2(int u, int f, int topf) {
    top[u] = topf;
    if(bson[u] != 0) {
        dfs2(bson[u], u, topf);   
    }
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != bson[u] && v != f) dfs2(v, u, v);   
    }
}

ll ans[N];

void run(){
    memset(head, -1, sizeof(head)), tot = 0;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adde(u, v, w); adde(v, u, w);
    }
    dfs(1, 0, 0);
    dfs2(1, 0, 1);
    cin >> q;
    ll t = 0;
    int s = 1;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int v, x; cin >> v >> x;
            t += x;
            add(l[v], x);
            while(top[v] != 1) {
                ans[fa[top[v]]] += 1ll * w[top[v]] * x;
                v = fa[top[v]];
            }
        } else {
            int v; cin >> v;
            s = v;
        }
        ll res = ans[s];
        res += 1ll * w[bson[s]] * query(l[bson[s]], r[bson[s]]);
        res += 1ll * w[s] * (t - query(l[s], r[s]));
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
