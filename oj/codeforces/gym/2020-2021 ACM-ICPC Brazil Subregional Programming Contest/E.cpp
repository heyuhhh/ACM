// Author : heyuhhh
// Created Time : 2020/12/10 16:16:55
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
const int N = 1e5 + 5;

int n, m;
vector<int> G[N];
int a[N], b[N];
int f[N][20];
int O[N], L[N], R[N];

void dfs1(int u) {
    for (int j = 1; j < 20; j++) {
        f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (auto v : G[u]) dfs1(v);
}

int up(int x, int l, int r) {
    for (int j = 19; j >= 0; j--) {
        if (f[x][j] && a[f[x][j]] <= r) {
            x = f[x][j];
        }
    }
    return x;
}

struct BIT {
    int c[N];
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
} bit;

vector<pii> q[N];
int ans[N];

void dfs2(int u) {
    for (auto it : q[u]) {
        int l = it.first, r = it.second;
        bit.add(l, 1), bit.add(r + 1, -1);
    }
    ans[u] = bit.query(a[u]);
    for (auto v : G[u]) {
        dfs2(v);
    }
    for (auto it : q[u]) {
        int l = it.first, r = it.second;
        bit.add(l, -1), bit.add(r + 1, 1);
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (b[i] != i) {
            G[b[i]].emplace_back(i);
            f[i][0] = b[i];
        }
    }
    dfs1(1);
    for (int i = 1; i <= m; i++) {
        cin >> O[i] >> L[i] >> R[i];
        O[i] = up(O[i], L[i], R[i]);
        q[O[i]].emplace_back(L[i], R[i]);
    }
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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