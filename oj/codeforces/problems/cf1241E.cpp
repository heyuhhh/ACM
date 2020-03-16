/*
 * Author:  heyuhhh
 * Created Time:  2020/3/12 11:28:02
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
const int N = 5e5 + 5;

int n, k;
struct Edge {
    int v, w, next;  
}e[N << 1];
int head[N], tot;
void adde(int u, int v, int w) {
    e[tot].v = v, e[tot].w = w, e[tot].next = head[u], head[u] = tot++;   
}

ll dp[N][2];

void dfs(int u, int fa, int W) {
    ll cur = 0;
    vector <int> sons;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w;
        if(v != fa) {
            dfs(v, u, w);
            sons.push_back(v);
        }   
    }
    sort(all(sons), [&](int a, int b) {
        return dp[a][1] - dp[a][0] > dp[b][1] - dp[b][0];
    });
    for(int i = 0; i < min(k, sz(sons)); i++) {
        cur += dp[sons[i]][1];
    }
    for(int i = min(k, sz(sons)); i < sz(sons); i++) {
        cur += dp[sons[i]][0];   
    }
    dp[u][1] = dp[u][0] = cur;
    dp[u][1] += W;
    if(k - 1 < sz(sons)) dp[u][1] += dp[sons[k - 1]][0] - dp[sons[k - 1]][1];
}

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) head[i] = -1; tot = 0;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adde(u, v, w), adde(v, u, w);   
    }
    dfs(1, 0, 0);
    ll ans = dp[1][0];
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
