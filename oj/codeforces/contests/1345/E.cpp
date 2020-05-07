/*
 * Author:  heyuhhh
 * Created Time:  2020/5/7 0:31:29
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

int n, m, f;
int ans[N], vis[N], vis2[N];
vector <int> G[N], rG[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto v : G[u]) {
        if (vis[v] == 1) f = 1;
        else if(!vis[v]) dfs(v);
    }
    vis[u] = 2;
}

void dfs2(int u) {
    vis2[u] = 1;
    for (auto v : rG[u]) {
        if (!vis2[v]) dfs2(v);   
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    if (f) {
        cout << -1 << '\n';
        return;
    }
    memset(ans, -1, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !vis2[i]) {
            ans[i] = 1;
            ++res;
        } else {
            ans[i] = 0;
        }
        if (!vis[i]) dfs(i);
        if (!vis2[i]) dfs2(i);   
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << "A";
        else cout << "E";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
