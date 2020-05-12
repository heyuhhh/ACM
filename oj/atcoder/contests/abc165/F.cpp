/*
 * Author:  heyuhhh
 * Created Time:  2020/5/6 12:34:01
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

int n;
int a[N], ans[N];
vector <int> G[N];


void dfs(int u, int fa, vector <int>& v) {
    auto it = lower_bound(all(v), a[u]) - v.begin();
    int op, val;
    if (it == sz(v)) {
        v.push_back(a[u]);
        op = 0;
    } else {
        val = v[it];
        v[it] = a[u];
        op = 1;
    }
    ans[u] = sz(v);
    for (auto son : G[u]) if (son != fa) {
        dfs(son, u, v);
    }
    if (op == 0) {
        v.pop_back();   
    } else {
        v[it] = val;
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector <int> v;
    dfs(1, 0, v);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    run();
    return 0;
}
