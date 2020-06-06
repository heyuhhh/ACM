/*
 * Author:  heyuhhh
 * Created Time:  2020/6/2 13:42:40
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

int n, m;
int in[N], out[N];
bool chk[N];
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
    for (int i = 1; i <= n; i++) {
        in[i] = out[i] = 0;
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        chk[i] = false;
    }
    vector <pii> edges;
    edges.push_back(MP(0, 0));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edges.push_back(MP(u, v));
    }
    int has = 2 * n;
    for (int i = 1; i <= m; i++) {
        int u = edges[i].fi, v = edges[i].se;
        if (merge(u, v)) {
            chk[i] = true;
            --has;
            ++out[u], ++in[v];
        }   
    }
    for (int i = 1; i <= m && has; i++) {
        int u = edges[i].fi, v = edges[i].se;
        if (out[u] == 0 || in[v] == 0) {
            chk[i] = true;
            --has;   
            ++out[u], ++in[v];
        }
    }
    for (int i = 1; i <= m && has; i++) {
        int u = edges[i].fi, v = edges[i].se;
        if (!chk[i]) {
            chk[i] = true;
            --has;   
        }
    }   
    for (int i = 1; i <= m; i++) {
        if (!chk[i]) {
            cout << edges[i].fi << ' ' << edges[i].se << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
