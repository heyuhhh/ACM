/*
 * Author:  heyuhhh
 * Created Time:  2020/4/19 17:26:40
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A>
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;
 
int in[N], out[N], T;
int f[N][20], deep[N];
vector <int> G[N];
void dfs(int u, int fa) {
    in[u] = ++T;
    deep[u] = deep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }   
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
    }
    out[u] = T;
}
int LCA(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(deep[f[x][i]] >= deep[y]) x = f[x][i];
    }  
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];  
    }
    return f[x][0];
}
int dis(int x, int y) {
    int z = LCA(x, y);
    return deep[x] + deep[y] - 2 * deep[z];  
}
 
int V[N << 1], tot;
vector <int> vt[N];
void clear() {
    for(int i = 1; i <= tot; i++) vt[V[i]].clear();  
}
int buildVT(vector<int>& nodes) {
    static int st[N], top;
    auto cmp = [&](int x, int y) {
        return in[x] < in[y];
    };
    auto chk = [&](int x, int y) {
        return in[y] >= in[x] && in[y] <= out[x];
    };
     
    tot = 0;
    for(auto it : nodes) V[++tot] = it;
    sort(V + 1, V + 1 + tot, cmp);
    for(int i = 1, tmp = tot; i < tmp; i++) V[++tot] = LCA(V[i], V[i + 1]);
    sort(V + 1, V + 1 + tot, cmp);
    tot = unique(V + 1, V + 1 + tot) - V - 1;
 
    st[top = 1] = V[1];
    for(int i = 2; i <= tot; i++) {
        while(top > 1 && !chk(st[top], V[i])) --top;
        vt[st[top]].push_back(V[i]);  
        st[++top] = V[i];
    }
    return V[1];
}
 
int n, s;
int a[N];
vector <int> D[N];
ll dp[N];
void DP(int u) {
    if(!sz(vt[u])) dp[u] = a[u];
    else dp[u] = 0;
    for(auto v : vt[u]) {
        DP(v);
        if(dp[v]) dp[u] += max(1ll, dp[v] - (deep[v] - deep[u]));
    }  
}
 
void run() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(s, 0);
    for(int i = 1; i <= n; i++) {
        D[deep[i]].push_back(i);  
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) if(sz(D[i])) {
        int rt = buildVT(D[i]);
        DP(rt);
        if(dp[rt]) ans += max(1ll, dp[rt] - (deep[rt] - deep[s]) - 1);
        clear();
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
