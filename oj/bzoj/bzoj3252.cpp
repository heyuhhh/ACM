/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 9:49:25
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
const int N = 2e5 + 5;

int n, k;
vector <int> G[N];
int a[N];
ll len[N];
int bson[N];

void dfs(int u, int fa) {
    ll Max = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        if (len[v] > Max) {
            Max = len[v];
            bson[u] = v;
        }
    }
    len[u] = len[bson[u]] + a[u];
}

int topf[N];

void dfs2(int u, int top, int fa) {
    topf[u] = top;
    if (bson[u]) {
        dfs2(bson[u], top, u);
    }
    for (auto v : G[u]) {
        if (v == fa || v == bson[u]) {
            continue;
        }
        dfs2(v, v, u);
    }
}

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 1, 0);
    priority_queue <ll> q;
    for (int i = 1; i <= n; i++) {
        if (topf[i] == i) {
            q.push(len[i]);
        }
    }
    ll ans = 0;
    while (k--) {
        ans += q.top(); q.pop();
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
