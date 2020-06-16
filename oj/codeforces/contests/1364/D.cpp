/*
 * Author:  heyuhhh
 * Created Time:  2020/6/14 0:25:26
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

vector <int> G[N];
int n, m, k;
int deep[N], father[N];
vector <int> d[N];

int t;
vector <int> cyc;

void find(int u, int v) {
    while (u != v) {
        cyc.push_back(u);
        u = father[u];
    }
    cyc.push_back(v);
}

void dfs(int u, int fa) {
    father[u] = fa;
    deep[u] = deep[fa] + 1;
    d[deep[u]].push_back(u);
    for (auto v : G[u]) if (v != fa) {
        if (deep[v] == -1) {
            dfs(v, u);
        } else if (deep[u] > deep[v]) {
            if (deep[u] - deep[v] + 1 <= k) {
                if (t == 2) continue;
                t = 2;
                find(u, v);
            }
        }
    }
}

void run() {
    memset(deep, -1, sizeof(deep));
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    if (t == 2) {
        cout << 2 << '\n';
        cout << sz(cyc) << '\n';
        for (auto it : cyc) {
            cout << it << ' ';
        }
        cout << '\n';
        return;
    }
    vector <int> ans;
    int need = (k + 1) / 2;
    for (int i = 0; i <= n && need; i += 2) {
        for (auto it : d[i]) {
            ans.push_back(it);
            if (--need == 0) {
                break;
            }
        }
    }
    if (need) {
        need = (k + 1) / 2;
        ans.clear();
        for (int i = 1; i <= n && need; i += 2) {
            for (auto it : d[i]) {
                ans.push_back(it);
                if (--need == 0) {
                    break;
                }           
            }
        }
    }
    cout << 1 << '\n';
    for (auto it : ans) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
