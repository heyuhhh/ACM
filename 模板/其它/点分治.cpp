/*
	优雅的暴力，对于一颗无根树每次以树的重心为根容斥计算答案，本质相当于枚举每一个结点作为路径上面的必经点然后来考虑。
	复杂度一般为$O(nlogn)$。
	
	寻找两点之间路径为$3$的倍数的代码：
*/
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 20005;
int n;
vector <pii> g[N];
int sz[N], mx[N], tsz;
int d[N];
int rt, ans, cnt;
bool vis[N];
void getrt(int u, int fa) {
    sz[u] = 1; mx[u] = 0;
    for(auto it : g[u]) {
        int v = it.fi;
        if(v == fa || vis[v]) continue;
        getrt(v, u);
        sz[u] += sz[v];
        if(sz[v] > mx[u]) mx[u] = sz[v];
    }
    mx[u] = max(mx[u], tsz - sz[u]);
    if(mx[u] < mx[rt]) rt = u;
}
void dfs2(int u, int D, int fa) {
    d[++cnt] = D;
    for(auto it : g[u]) {
        int v = it.fi, w = it.se;
        if(vis[v] || v == fa) continue;
        dfs2(v, D + w, u);
    }
}
int calc() {
    for(int i = 1; i <= cnt; i++) d[i] %= 3;
    int tmp[3] = {0, 0, 0};
    for(int i = 1; i <= cnt; i++) ++tmp[d[i]];
    int ans = tmp[0] * (tmp[0] - 1) + 2 * (tmp[1] * tmp[2]);
    return ans;
}
void dfs(int u) {
    vis[u] = 1;
    cnt = 0; dfs2(u, 0, 0);
    int tmp = calc();
    ans += tmp;
    for(auto it : g[u]) {
        int v = it.fi, w = it.se;
        if(vis[v]) continue;
        cnt = 0, dfs2(v, w, 0);
        ans -= calc();
        tsz = sz[v], rt = 0, getrt(v, u);
        dfs(rt);
    }
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(MP(v, w)); g[v].push_back(MP(u, w));
    }
    tsz = n, mx[0] = INF, getrt(1, 0);
    dfs(rt);
    ans += n;
    int tot = n * n;
    int g = gcd(tot, ans);
    ans /= g, tot /= g;
    cout << ans << '/' << tot;
    return 0;
}
