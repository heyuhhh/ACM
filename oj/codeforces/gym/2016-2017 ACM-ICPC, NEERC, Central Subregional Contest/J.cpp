/*
 * Author:  heyuhhh
 * Created Time:  2020/6/23 14:00:37
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
const int N = 100 + 5;

struct MaxMatch {
    int n, m;
    vector<int> G[N];
    int vis[N], Match[N], clk;
    
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        for (int i = 1; i <= n; i++) G[i].clear();
        fill(vis + 1, vis + m + 1, -1);
        fill(Match + 1, Match + m + 1, -1);
    }
    
    void adde(int u, int v) {
        G[u].push_back(v);
    }
    
    bool dfs(int u) {
        for (int v: G[u])
            if (vis[v] != clk) {
                vis[v] = clk;
                if (Match[v] == -1 || dfs(Match[v])) {
                    Match[v] = u;
                    return true;
                }
            }
        return false;
    }
    
    int solve() {
        int res = 0;
        for (int i = 1; i <= n; i++, ++clk) {
            res += dfs(i);
        }
        return res;
    }
} MM;

int n, m;
int a[N], b[N];

void run() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    MM.init(n, m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    auto sum = [&] (int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    auto ok = [&] (int x, int y) {
        if (sum(x / 1000) == sum(y % 1000)) return 1;
        if (sum(y / 1000) == sum(x % 1000)) return 2;
        return 0;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ok(a[i], b[j])) {
                MM.adde(i, j);
            }
        }
    }
    int k = MM.solve();
    cout << k << '\n';
    for (int y = 1; y <= m; y++) {
        if (MM.Match[y] != -1) {
            int x = MM.Match[y];
            int op = ok(a[x], b[y]);
            if (op == 1) {
                cout << "AT";
                cout << ' ' << a[x] << ' ' << b[y] << '\n';
            } else {
                cout << "TA";
                cout << ' ' << b[y] << ' ' << a[x] << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
