/*
 * Author:  heyuhhh
 * Created Time:  2020/6/20 12:57:42
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
//#define Local
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

struct UFS {
    int f[N], h[N], sz[N], top;
    struct node {
        int x, y, fx, h, SZ;
    }sta[N];
    void init(int n) {
        top = 0;
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            f[i] = i;
            h[i] = 0;
        }
    }
    int find(int x) {
        return f[x] == x ? f[x] : find(f[x]);
    }
    bool merge(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (h[x] > h[y]) swap(x, y);
        sta[++top] = node{x, y, f[x], h[y], sz[y]};
        if (h[x] == h[y]) ++h[y];
        sz[y] += sz[x];
        f[x] = y;
        return true;
    }
    void undo(int k) {
        while (k--) {
            node it = sta[top--];
            f[it.x] = it.fx;
            h[it.y] = it.h;
            sz[it.y] = it.SZ;
        }
    }
    int query(int x) {
        int fx = find(x);
        return sz[fx];
    }
} ufs;

int n, m;
int d[N], a[N];
vector <int> G[N];
bool check[N];

void run() {
    cin >> n >> m;
    ufs.init(n);
    for (int i = 1; i <= n; i++) {
        d[i] = check[i] = 0;
        G[i].clear();
        a[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ++d[u], ++d[v];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sort(a + 1, a + n + 1, [&](int i, int j) {
        if (d[i] == d[j]) return i < j;
        return d[i] < d[j];
    });
    vector <vector <int>> op(n + 1);
    for (int i = 1; i <= n; i++) {
        int u = a[i];
        for (auto v : G[u]) {
            if (d[v] <= d[u] && check[v]) {
                if (ufs.merge(u, v)) {
                    op[u].push_back(v);
                }
            }
        }
        check[u] = true;
    }
    vector <pair<int, vector<int>>> ans;
    for (int i = n; i >= 1; i--) {
        int u = a[i];
        int SZ = ufs.query(u);
        if (d[u] != SZ - 1) {
            cout << "No" << '\n';
            return;
        }
        ans.push_back(MP(u, op[u]));
        ufs.undo(sz(op[u]));
        for (auto v : G[u]) {
            --d[v];
        }
    }
    cout << "Yes" << '\n';
    reverse(all(ans));
    for (auto it : ans) {
        cout << it.fi << ' ' << sz(it.se);
        for (auto it2 : it.se) {
            cout << ' ' << it2;
        }
        cout << '\n';
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
