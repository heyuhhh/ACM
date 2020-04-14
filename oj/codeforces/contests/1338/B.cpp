/*
 * Author:  heyuhhh
 * Created Time:  2020/4/13 20:24:55
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
const int N = 1e5 + 5;

int n;
vector <int> G[N];

int d[N];
int cnt[N][2], ans[2];
bool chk[N];

void dfs(int u, int fa) {
    if(chk[u]) return;
    int sons = 0;
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        if(chk[v]) ++sons, ++cnt[u][1];
        else {
            cnt[u][0] += cnt[v][1];
            cnt[u][1] += cnt[v][0];
        }
    }
    if(sons > 1) ans[1] += sons - 1;
    if(cnt[u][0] && cnt[u][1]) ans[0] = 3;
}

void run() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);   
        ++d[u], ++d[v];
    }
    int rt;
    for(int i = 1; i <= n; i++) {
        if(d[i] > 1) rt = i;
        else chk[i] = true;
    }
    dfs(rt, 0);
    ans[1] = n - 1 - ans[1];
    ans[0] = max(ans[0], 1);
    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
