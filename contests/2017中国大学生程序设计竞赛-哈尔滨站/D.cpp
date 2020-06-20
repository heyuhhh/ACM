/*
 * Author:  heyuhhh
 * Created Time:  2020/6/16 15:45:05
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
const int N = 1e3 + 5;

int n, m;
vector <int> G[N];
int a[N];

int Max, rt;
void dfs(int u, int fa, int d) {
    if (a[u]) {
        if (d > Max) {
            Max = d;
            rt = u;
        }
    }
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u, d + 1);
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
        G[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Max = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            dfs(i, 0, 0);
            Max = 0;
            dfs(rt, 0, 0);
            break;
        }
    }
    cout << (double)(Max / 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
