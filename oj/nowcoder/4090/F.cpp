/*
 * Author:  heyuhhh
 * Created Time:  2020/2/28 21:18:29
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

int n, q;
int a[N], b[N];
vector <int> G[N];

int deep[N];
int f[N][21];
int l[N], r[N], dfn;

void dfs(int u, int fa, int sum) {
    l[u] = ++dfn;
    b[u] = sum;
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u, sum ^ a[v]);
    }
    r[u] = dfn;
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

int sumv[N << 2], lz[N << 2];

void tag(int o, int l, int r, int v) {
    int t = (((r - l + 1) & 1) ? 1 : 0) * v;
    sumv[o] ^= t;
    lz[o] ^= v;
}

void push_down(int o, int l, int r) {
    if(lz[o]) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;
    }   
}

void push_up(int o) {
    sumv[o] = sumv[o << 1] ^ sumv[o << 1|1];
}

void build(int o, int l, int r) {
    if(l == r) {
        sumv[o] = b[l];
        return;   
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

int query(int o, int l, int r, int k) {
    if(l == r) {
        return sumv[o];   
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(k <= mid) return query(o << 1, l, mid, k);
    return query(o << 1|1, mid + 1, r, k);
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0, a[1]);
    build(1, 1, n);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int u, x; cin >> u >> x;
            a[u] = x;
            update(1, 1, n, l[u], r[u], x);
        } else {
            int u, v; cin >> u >> v;
            int t1 = query(1, 1, n, u), t2 = query(1, 1, n, v);
            int lca = LCA(u, v);
            int ans = t1 ^ t2 ^ a[lca];
            cout << ans << '\n';
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> q) run();
    return 0;
}
