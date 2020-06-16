/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 17:03:22
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
 
int n;
int fa[N];
bool vis[N];
int ans, tot;
vector <int> G[N];
vector <pair<vector<int>, int>> a;
vector <int> t;
 
void dfs(int u) {
    t.push_back(u);
    for (auto v : G[u]) {
        dfs(v);
        if (!vis[u] && !vis[v]) {
            vis[u] = vis[v] = true;
            ++ans;
        }
    }
}
 
void gao(int u) {
    t.clear();
    dfs(u);
    vector <int> tmp = t;
    t.clear();
    for (auto it : tmp) {
        if (!vis[it]) {
            t.push_back(it);
        }
    }
    int f = 0;
    for (int i = 0; i < sz(t); i++) {
        if (fa[t[i]] == 0 && t[i] != 1) {
            swap(t[sz(t) - 1], t[i]);
            f = 1;
            break;
        }
    }
    a.push_back(MP(t, f));
}
 
 
void run() {
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && fa[i] == 0) {
            gao(i);
        }
    }
    vector <vector <int>> v0, v1;
    for (auto& it : a) if (sz(it.fi)) {
        if (it.se) v1.push_back(it.fi);
        else v0.push_back(it.fi);
    }
    sort(all(v1), [&] (vector <int>& A, vector <int>& B) {
        return sz(A) > sz(B);
    });
    for (auto& v : v1) {
        if (sz(v0)) {
            vector <int>& it = v0.back();
            ++ans;
            fa[v[sz(v) - 1]] = it.back();
            it.pop_back();
            v.pop_back();
            if (sz(it) == 0) {
                v0.pop_back();
            }
        }
        if (sz(v)) {
            v0.push_back(v);
        }
    }
    cout << ans << '\n';
    for (int i = 2; i <= n; i++) {
        if (fa[i] == 0) fa[i] = 1;
        cout << fa[i] << " \n"[i == n];
    }
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
