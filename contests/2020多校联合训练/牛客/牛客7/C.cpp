// Author : heyuhhh
// Created Time : 2020/08/02 18:04:12
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;

vector<int> G[N];
int n, m;
// 注意bson的初始化，其余可以自动初始化
// 注意每个点实际值为dfn[x]
int sz[N], deep[N], bson[N], ff[N];
int top[N], dfn[N], T;
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    sz[u] = 1;
    ff[u] = fa;
    int Max = -1;
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > Max) {
                Max = sz[v];
                bson[u] = v;
            }
        }
    }
}

void dfs(int u, int fa, int topf) {
    dfn[u] = ++T;
    top[u] = topf;
    if (bson[u] != 0) {
        dfs(bson[u], u, topf);
    }
    for (auto v : G[u]) {
        if (v != fa && v != bson[u]) {
            dfs(v, u, v);
        }
    }
}

ll sumv[N << 2], lz[N << 2];

//区间加
void tag(int o, int l, int r, ll v) {
    sumv[o] += 1ll * (r - l + 1) * v;
    lz[o] += v;
}

void push_up(int o) {
    sumv[o] = sumv[o << 1] + sumv[o << 1|1];
}

void push_down(int o, int l, int r) {
    if(lz[o] != 0) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;   
    }
}

void build(int o, int l, int r) {
    lz[o] = 0;
    if(l == r) {
        sumv[o] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
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

ll query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sumv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(L <= mid) res += query(o << 1, l, mid, L, R);
    if(R > mid) res += query(o << 1|1, mid + 1, r, L, R);
    return res;
}

ll add[N];
ll cnt, sumx;

ll query(int x) {
    ll res = 0;
    int t = x;
    while (x != 0) {
        res += query(1, 1, n, dfn[top[x]], dfn[x]);
        x = ff[top[x]];
    }
    return res + add[t] - 1ll * cnt * deep[t] + sumx;
}

void modify(int x) {
    while (x != 0) {
        update(1, 1, n, dfn[top[x]], dfn[x], 2);
        x = ff[top[x]];
    }
}



void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        bson[i] = 0;
        add[i] = 0;
    }
    T = sumx = cnt = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    dfs(1, 0, 1);
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int w, x;
            cin >> x >> w;
            ++cnt;
            sumx += w - deep[x];
            modify(x);
        } else if (op == 2) {
            int x;
            cin >> x;
            ll res = query(x);
            if (res > 0) {
                add[x] -= res;
            }
        } else {
            int x;
            cin >> x;
            ll res = query(x);
            cout << res << '\n';
        }
    }
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}