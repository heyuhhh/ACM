// Author : heyuhhh
// Created Time : 2020/07/23 10:09:48
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
const int N = 2e5 + 5, M = 20;

int n;
vector<int> G[N];
int f[N][M], deep[N];
int in[N], out[N], mp[N], T;
int ans[N];

void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    mp[in[u] = ++T] = u;
    f[u][0] = fa;
    for (int i = 1; i < M; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
    out[u] = T;
}

int find_kth(int u, int k) {
    for (int i = M - 1; i >= 0; i--) {
        if (k >> i & 1) {
            u = f[u][i];
        }
    }
    if (u == 0) u = 1;
    return u;
}

int maxv[N << 2], node[N << 2], cover[N << 2];

void push_up(int o) {
    maxv[o] = node[o] = -1;
    if (!cover[o << 1]) {
        maxv[o] = maxv[o << 1];
        node[o] = node[o << 1];
    }
    if (!cover[o << 1|1] && maxv[o << 1|1] > maxv[o]) {
        maxv[o] = maxv[o << 1|1];
        node[o] = node[o << 1|1];
    }
    cover[o] = (cover[o << 1] & cover[o << 1|1]);
}

void build(int o, int l, int r) {
    if (l == r) {
        maxv[o] = deep[mp[l]];
        node[o] = mp[l];
        cover[o] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        cover[o] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(o << 1, l, mid, L, R, v);
    if (R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void run() {
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    T = 0;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        G[x].push_back(i + 1);
        G[i + 1].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = n - 1;
    }
    dfs(1, 0);
    build(1, 1, T);
    for (int i = n - 1; i >= 0; i--) {
        int cost = 0;
        vector<int> op;
        while (1) {
            ++cost;
            if (maxv[1] - 1 <= i) break;
            int u = node[1];
            int k = find_kth(u, i);
            op.push_back(k);
            update(1, 1, T, in[k], out[k], 1);
        }
        ans[cost] = i;
        for (auto it : op) {
            update(1, 1, T, in[it], out[it], 0);
        }
    }
    for (int i = 2; i <= n; i++) {
        ans[i] = min(ans[i], ans[i - 1]);
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += ans[i];
    }
    cout << sum << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n) run();
    return 0;
}