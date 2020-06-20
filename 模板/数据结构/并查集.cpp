/*
	线段树维护可撤销并查集。
	
	因为可撤销，所以不能路径压缩，注意启发式合并。
*/ 
#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
struct node{
    int u, v, l, r;
}a[N];
int b[N], D;
vector <int> c[N << 2];
vector <pair<int, int> > d[100];
ll ans;
void insert(int o, int l, int r, int L, int R, int id) {
    if(L <= l && r <= R) {
        c[o].push_back(id);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) insert(o << 1, l, mid, L, R, id);
    if(R > mid) insert(o << 1|1, mid + 1, r, L, R, id);
}
int f[N], sz[N];
int find(int x) {
    return f[x] == x ? x : find(f[x]);
}
void merge(int x, int y, int dep) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    if(sz[fx] > sz[fy]) swap(fx, fy);
    int tmp = 0;
    f[fx] = fy;
    if(sz[fx] == sz[fy]) tmp++;
    sz[fy] += tmp;
    d[dep].push_back(MP(fx, tmp));
}
void del(int dep) {
    for(auto it : d[dep]) {
        sz[f[it.first]] -= it.second;
        f[it.first] = it.first;
    }
    d[dep].clear();
}
void dfs(int o, int l, int r, int dep) {
    for(auto it : c[o]) {
        merge(a[it].u, a[it].v, dep);
    }
    if(find(1) == find(n)) {
        ans += b[r + 1] - b[l];
    } else if(l < r) {
        int mid = (l + r) >> 1;
        dfs(o << 1, l, mid, dep + 1);
        dfs(o << 1|1, mid + 1, r, dep + 1);
    }
    del(dep);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].l >> a[i].r;
        b[++D] = a[i].l, b[++D] = a[i].r + 1;
    }
    sort(b + 1, b + D + 1);
    D = unique(b + 1, b + D + 1) - b - 1;
    for(int i = 1; i <= m; i++) {
        a[i].l = lower_bound(b + 1, b + D + 1, a[i].l) - b;
        a[i].r = lower_bound(b + 1, b + D + 1, a[i].r + 1) - b - 1;
        insert(1, 1, D, a[i].l, a[i].r, i);
    }
    for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    dfs(1, 1, D, 1);
    cout << ans;
    return 0;
}

//可撤销并查集模板
struct UFS {
    int f[N], h[N], sz[N], top;
    struct node {
        int x, y, fx, h, SZ;
    }sta[N];
    void init(int n) {
        top = 0;
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
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
        sta[++top] = node{x, y, f[x], h[y], sz[y]};
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
        }
    }
    int query(int x) {
        int fx = find(x);
        return sz[fx];
    }
} ufs; 
