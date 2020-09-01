// Author : heyuhhh
// Created Time : 2020/08/17 15:53:22
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
//head
const int N = 5e5 + 5, M = 5e5 + 5;
const int MAXH = 21;

int n, m;
int a[N], f[N];
vector<int> G[N];
int rt[N];

void dfs(int u, int fa) {
    for (auto v : G[u]) if (v != fa) {
        f[v] = u;
        dfs(v, u);
    }
}

int tot;
int ch[N * 25][2];
int w[N * 25], sum[N * 25];

#define ls ch[o][0]
#define rs ch[o][1]

void pushup(int o) {
    w[o] = w[ls] + w[rs];
    sum[o] = 0;
    if (ls) sum[o] = (sum[ls] << 1);
    if (rs) sum[o] ^= ((sum[rs] << 1) | (w[rs] & 1));
}

void insert(int& o, int v, int d, int op) {
    if (!o) o = ++tot;
    if (d == MAXH) {
        w[o] += op;
        return;
    }
    insert(ch[o][v & 1], v >> 1, d + 1, op);
    pushup(o);
}

int flag[N];

int getf(int x) {
    return a[x] + flag[f[x]];
}

void modify(int x, int v1, int v2) {
    if (f[x]) {
        v1 += flag[f[x]], v2 += flag[f[x]];
        insert(rt[f[x]], v1, 0, -1);
        insert(rt[f[x]], v2, 0, 1);
        v1 -= flag[f[x]], v2 -= flag[f[x]];
    }
    if (x) a[x] = v2;
}

void add(int o) {
    swap(ls, rs);
    if (ls) add(ls);
    pushup(o);
}

void run() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (f[i] > 0) {
            insert(rt[f[i]], a[i], 0, 1);
        }
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            if (f[x] != 0) {
                modify(f[x], a[f[x]], a[f[x]] + 1);
            }
            add(rt[x]);
            ++flag[x];
        } else if (op == 2) {
            int x, v;
            cin >> x >> v;
            modify(x, a[x], a[x] - v);
        } else {
            int x;
            cin >> x;
            int ans = (sum[rt[x]] ^ getf(f[x]));
            cout << ans << '\n';
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
    run();
    return 0;
}