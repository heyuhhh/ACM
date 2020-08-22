// Author : heyuhhh
// Created Time : 2020/08/04 09:12:36
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
const int N = 4e5 + 5;

int n, m, q;
int num, cnt, blosz;
int d[N];

struct UFS {
    int f[N], h[N], sz[N], top;
    struct node {
        int x, y, fx, h, SZ, X, Y;
    }sta[N];
    void init() {
        top = 0;
        for (int i = 1; i <= n + m; i++) {
            sz[i] = (i > m ? 1 : 0);
            f[i] = i;
            h[i] = 0;
        }
    }
    int find(int x) {
        return f[x] == x ? f[x] : find(f[x]);
    }
    bool merge(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (h[x] > h[y]) swap(x, y);
        
        if (++d[u] == 1) --cnt;
        if (++d[v] == 1) --num;
        if (sz[x] && sz[y]) --blosz;

        sta[++top] = node{x, y, f[x], h[y], sz[y], u, v};
        if (h[x] == h[y]) ++h[y];
        sz[y] += sz[x];
        f[x] = y;
        return true;
    }
    void undo(int k) {
        while (k--) {
            node it = sta[top--];
            f[it.x] = it.fx;
            h[it.y] = it.h;
            sz[it.y] = it.SZ;
            int u = it.X, v = it.Y;
            if (--d[u] == 0) ++cnt;
            if (--d[v] == 0) ++num;
            if (sz[it.y] && sz[it.x]) ++blosz;
        }
    }
    int query(int x) {
        int fx = find(x);
        return sz[fx];
    }
} ufs; 

vector<pii> nodes[N << 2];
int ans[N];

void add(int o, int l, int r, int L, int R, pii v) {
    if (L <= l && r <= R) {
        nodes[o].push_back(v);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) {
        add(o << 1, l, mid, L, R, v);
    }
    if (R > mid) {
        add(o << 1|1, mid + 1, r, L, R, v);
    }
}

void dfs(int o, int l, int r) {
    int cc = 0;
    for (auto& it : nodes[o]) {
        int fans = it.fi, player = it.se;
        if (ufs.merge(fans, player + m)) ++cc;
    }
    if (l == r) {
        dbg(l, num, blosz);
        if (cnt > 0) ans[l] = -1;
        else ans[l] = blosz - num;
        ufs.undo(cc);
        return;
    }
    int mid = (l + r) >> 1;
    dfs(o << 1, l, mid);
    dfs(o << 1|1, mid + 1, r);
    ufs.undo(cc);
}

void run() {
    cin >> n >> m >> q;
    ufs.init();
    map<pii, int> S;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            S[MP(x, i)] = 0;
        }
    }
    for (int _ = 1; _ <= q; _++) {
        int x, y;
        cin >> x >> y;
        if (S.count(MP(x, y))) {
            add(1, 0, q, S[MP(x, y)], _ - 1, MP(x, y));
            S.erase(MP(x, y));
        } else {
            S[MP(x, y)] = _;
        }
    }
    for (auto& it : S) {
        add(1, 0, q, it.se, q, it.fi);
    }
    num = n;
    cnt = m;
    blosz = n;
    dfs(1, 0, q);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}