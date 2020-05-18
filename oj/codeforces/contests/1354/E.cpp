/*
 * Author:  heyuhhh
 * Created Time:  2020/5/17 19:07:00
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
const int N = 5000 + 5, M = 1e5 + 5;
 
int n, m;
int a[3];
 
struct Edge {
    int v, next;   
}e[M << 1];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;   
}
 
int dfn[N], T;
int deep[N];
vector <int> v;
 
void dfs(int u, int fa) {
    v.push_back(u);
    deep[u] = deep[fa] + 1;
    dfn[u] = ++T;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        if (dfn[v]) {
            if ((dfn[u] - dfn[v] + 1) & 1) {
                cout << "NO" << '\n';
                exit(0);   
            }
        } else {
            dfs(v, u);
        }
    }
}
 
int ans[N];
pii dp[N][N];
 
void run() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adde(u, v), adde(v, u);
    }
    vector <vector<int>> odd, even;
    for (int i = 1; i <= n; i++) if (!dfn[i]) {
        v.clear();
        dfs(i, 0);
        vector <int> v1, v2;
        for (auto it : v) {
            if (deep[it] & 1) v1.push_back(it);
            else v2.push_back(it);
        }
        odd.push_back(v1);
        even.push_back(v2);
    }
    int blocks = sz(odd);
    memset(dp, -1, sizeof(dp));
    dp[0][sz(odd[0])] = MP(0, 0);
    dp[0][sz(even[0])] = MP(0, 1);
    for (int i = 0; i < blocks - 1; i++) {
        for (int j = 0; j <= n; j++) if (dp[i][j].fi >= 0) {
            if (j + sz(odd[i + 1]) <= n) {
                dp[i + 1][j + sz(odd[i + 1])] = MP(j, 0);
            }
            if (j + sz(even[i + 1]) <= n) {
                dp[i + 1][j + sz(even[i + 1])] = MP(j, 1);
            }
        }
    }
    if (dp[blocks - 1][a[1]].fi >= 0) {
        cout << "YES" << '\n';
        pii now = dp[blocks - 1][a[1]];
        int t = blocks - 1;
        while (t >= 0) {
            if (now.se == 0) {
                for (auto it : odd[t]) {
                    ans[it] = 2;
                }
                for (auto it : even[t]) {
                    if (a[0] > 0) {
                        ans[it] = 1;
                        --a[0];
                    } else {
                        ans[it] = 3;
                    }
                }
            } else {
                for (auto it : even[t]) {
                    ans[it] = 2;
                }
                for (auto it : odd[t]) {
                    if (a[0] > 0) {
                        ans[it] = 1;
                        --a[0];
                    } else {
                        ans[it] = 3;
                    }
                }                   
            }
            if (t == 0) break;
            --t;
            now = dp[t][now.fi];
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';   
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
