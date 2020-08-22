// Author : heyuhhh
// Created Time : 2020/08/06 12:24:17
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

int pow2[N];

void init() {
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = 1ll * pow2[i - 1] * 2 % MOD;
    }
}

int n, m;
vector<pii> G[N];
int f[N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
        return true;
    }
    return false;
}

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void del(int& x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

int sz[N];
int a[N], tot;
int sum;

void dfs(int u, int fa) {
    sz[u] = 1 - a[u];
    for (auto it : G[u]) {
        int v = it.fi, w = it.se;
        if (v != fa) {
            dfs(v, u);
            add(sum, 1ll * w * sz[v] % MOD);
            sz[u] += sz[v];
        }
    }
}

int ans;

void dfs2(int u, int fa) {
    if (a[u] == 1) {
        add(ans, sum);
    }
    for (auto it : G[u]) {
        int v = it.fi, w = it.se;
        if (v != fa) {
            add(sum, 1ll * w * (tot - sz[v]) % MOD);
            del(sum, 1ll * w * sz[v] % MOD);

            dfs2(v, u);

            del(sum, 1ll * w * (tot - sz[v]) % MOD);
            add(sum, 1ll * w * sz[v] % MOD);
        }
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        G[i].clear();
    }
    ans = sum = tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += 1 - a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (merge(u, v)) {
            G[u].push_back(MP(v, pow2[i]));
            G[v].push_back(MP(u, pow2[i]));
        }
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}