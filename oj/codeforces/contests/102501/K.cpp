/*
 * Author:  heyuhhh
 * Created Time:  2020/5/21 18:10:44
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
const int N = 1e5 + 5;

int n, m, t;
vector <int> G[N];
int c1[N], c2[N];

void dfs(int u, int c) {
    if (u == t) return;
    if (c1[u] == -1) {
        c1[u] = c;
    } else if(c2[u] == -1) {
        if (c1[u] == c) return;
        c2[u] = c;
    } else return;
    for (auto v : G[u]) dfs(v, c);
}

void run() {
    cin >> n >> m >> t;
    memset(c1, -1, sizeof(c1));
    memset(c2, -1, sizeof(c2));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[v].push_back(u);
    }
    for (auto it : G[t]) {
        dfs(it, it);
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) if (c1[i] == i && c2[i] == -1) {
        ans.push_back(i);
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
