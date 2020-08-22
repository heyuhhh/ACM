// Author : heyuhhh
// Created Time : 2020/08/06 13:38:39
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
const int N = 100 + 5, M = 10000 + 5, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n, m;

ll b[N][N];
int g[N][N];
ll Det(int n){
    int i,j,k;
    ll ret = 1;
    for(i=2;i<=n;i++){
        for(j = i+1;j <= n;j++){
            while(b[j][i]){
                ll tmp=b[i][i]/b[j][i];//不存在除不尽的情况
                for(k = i;k <= n;k++){
                    b[i][k] = (b[i][k] - tmp*b[j][k])%MOD;
                    if(b[i][k]<0) b[i][k]+=MOD;
                }
                swap(b[i],b[j]);
                ret = -ret;
            }
        }
        if(!b[i][i]) return -1;
        ret = ret * b[i][i]%MOD;
    }
    if(ret < 0) ret += MOD;
    return ret;
}

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

void run() {
    cin >> n >> m;
    vector<pair<pii, int>> edges;
    memset(b, 0, sizeof(b));
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(MP(MP(u, v), w));
        ++g[u][v], ++g[v][u];
        ++b[u][u], ++b[v][v];
        --b[u][v], --b[v][u];
    }
    int ans = 0;
    ll tot = Det(n);
    int fm = qpow(tot, MOD - 2);
    for (int k = 30; k >= 0; k--) {
        memset(b, 0, sizeof(b));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
        int cnt = 0;
        for (auto& it : edges) {
            int u = it.fi.fi, v = it.fi.se, w = it.se;
            if (w >> k & 1) {
                ++g[u][v], ++g[v][u];
                ++b[u][u], ++b[v][v];
                --b[u][v], --b[v][u];
                if (merge(u, v)) ++cnt;
            }
        }
        if (cnt < n - 1) continue;
        ll q = Det(n);
        if (q == -1) continue;
        int res = 1ll * (1 << k) * q % MOD * fm % MOD;
        ans = (ans + res) % MOD;
    }
    cout << ans << '\n';
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