/*
 * Author:  heyuhhh
 * Created Time:  2019/11/15 11:03:07
 */
#include <bits/stdc++.h>
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
const int N = 500005;

int n;
vector <int> g[N];
int f[N], in[N], out[N], dfn;

void dfs(int u, int fa) {
    f[u] = fa;
    in[u] = ++dfn;
    for(auto v : g[u]) if(v != fa) {
        dfs(v, u);
    }
    out[u] = dfn;
}

int minv[N << 2], lz[N << 2];

void push_down(int o, int l, int r) {
    if(lz[o] != -1) {
        lz[o << 1] = lz[o << 1|1] = lz[o];
        minv[o << 1] = minv[o << 1|1] = lz[o];
        lz[o] = -1;
    }  
}

void build(int o, int l, int r) {
    minv[o] = 0; lz[o] = -1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(o << 1, l, mid); 
    build(o << 1|1, mid + 1, r);
}

void upd(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        minv[o] = lz[o] = v;
        return;   
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(o << 1, l, mid, L, R, v);
    if(R > mid) upd(o << 1|1, mid + 1, r, L, R, v);
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
}

int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) return minv[o];
    push_down(o, l, r);
    int res = 2;
    int mid = (l + r) >> 1;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = min(res, query(o << 1|1, mid + 1, r, L, R));
    return res;   
}

void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    build(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int op, v; cin >> op >> v;
        if(op == 1) {
            int Min = query(1, 1, n, in[v], out[v]);
            if(Min == 0 && v > 1) {
                upd(1, 1, n, in[f[v]], in[f[v]], 0);
            }
            upd(1, 1, n, in[v], out[v], 1);
        } else if(op == 2) {
            upd(1, 1, n, in[v], in[v], 0);
        } else {
            int Min = query(1, 1, n, in[v], out[v]);
            if(Min == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        }  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
	return 0;
}
