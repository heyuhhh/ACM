/*
 * Author:  heyuhhh
 * Created Time:  2020/6/24 8:45:45
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
#include <numeric>
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

void run() {
    int n, m; cin >> n >> m;
    vector <int> d(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector <vector <pii>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, -- v;
        G[u].push_back(MP(v, i));
        G[v].push_back(MP(u, i));
        ++d[u], ++d[v];
    }
    queue <int> q;
    for (int i = 0; i < n; i++) {
        if (w[i] >= d[i]) {
            q.push(i);
        }
    }
    vector <int> ans;
    vector <bool> check(m);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto it : G[u]) {
            int v = it.fi, id = it.se;
            if (check[id]) continue;
            check[id] = true;
            ans.push_back(id);
            if (--d[v] == w[v]) {
                q.push(v);
            }
        }
    }
    if (sz(ans) < m) {
        cout << "DEAD" << '\n';
    } else {
        cout << "ALIVE" << '\n';
        reverse(all(ans));
        for (auto it : ans) {
            cout << it + 1 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
