// Author : heyuhhh
// Created Time : 2020/08/17 18:42:28
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
const int N = 6e5 + 5;
const int MAXH = 22;

int n;
int a[N];
vector<int> G[N];
int rt[N], tot;
int w[N * 25], sum[N * 25], ch[N * 25][2];

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
void add(int o) {
    swap(ls, rs);
    if (ls) add(ls);
    pushup(o);
}

int merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    w[x] += w[y];
    sum[x] ^= sum[y];
    ch[x][0] = merge(ch[x][0], ch[y][0]);
    ch[x][1] = merge(ch[x][1], ch[y][1]);
    return x;
}

ll ans;

void dfs(int u) {
    int sons = 0;
    for (auto v : G[u]) {
        dfs(v);
        add(rt[v]);
        if (++sons > 1) {
            rt[u] = merge(rt[u], rt[v]);
        } else {
            rt[u] = rt[v];
        }
    }
    insert(rt[u], a[u], 0, 1);
    ans += sum[rt[u]];
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int f; 
        cin >> f;
        G[f].push_back(i);
    }
    dfs(1);
    cout << ans << '\n';
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