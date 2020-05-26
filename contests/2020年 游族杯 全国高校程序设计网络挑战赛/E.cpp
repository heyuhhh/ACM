/*
 * Author:  heyuhhh
 * Created Time:  2020/5/24 10:38:47
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
#include <functional>
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
const int N = 5e5 + 5;

int n, m;

struct Edge {
    int u, v;   
} e[N];

vector <pii> G[N];
bool vis[N], del[N];

void run() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(MP(v, i));
        G[v].push_back(MP(u, i));
        e[i] = Edge {u, v};
    }
    vector <int> path;
    function <void(int)> dfs = [&] (int u) -> void {
        vis[u] = true;
        while (sz(G[u])) {
            pii s = G[u][sz(G[u]) - 1]; G[u].pop_back();
            int v = s.fi, id = s.se;
            if (del[id]) continue;
            del[id] = true;
            dfs(v);
            path.push_back(id);
        }
    };
    auto get = [&] (int u, int id) {
        return u ^ e[id].u ^ e[id].v;
    };
    vector <int> ans;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        path.clear();
        dfs(i);
        reverse(all(path));
        if (sz(path) == 0) continue;
        int st = i, ed = get(st, path[0]);
        ans.push_back(path[0]);
        for (int j = 1; j < sz(path) - 1; j++) {
            if (get(ed, path[j]) == st) {
                ed = get(st, path[j + 1]);
                ans.push_back(path[j + 1]);
                ans.push_back(path[j++]);
            } else {
                ans.push_back(path[j]);
                ed = get(ed, path[j]);
            }
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
