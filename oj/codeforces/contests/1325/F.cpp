/*
 * Author:  heyuhhh
 * Created Time:  2020/3/15 10:36:27
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
const int N = 1e5 + 5;

int n, m, sq;
vector <int> G[N];

int dep[N];
vector <int> cyc;
void dfs(int u) {
    cyc.push_back(u);
    dep[u] = sz(cyc) - 1;
    for(auto v : G[u]) {
        if(dep[v] != -1) {
            if(dep[u] - dep[v] + 1 >= sq) {
                cout << 2 << '\n';
                cout << dep[u] - dep[v] + 1 << '\n';
                while(1) {
                    int now = cyc.back();
                    cout << now << ' ';
                    if(now == v) break;
                    cyc.pop_back();
                }
                exit(0);
            }         
        } else dfs(v);   
    }
    cyc.pop_back();
}

int cnt[N];

void run() {
    memset(dep, -1, sizeof(dep));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    sq = 1;
    while(1ll * sq * sq < n) ++sq;
    dfs(1);
    for(int i = 1; i <= n; i++) ++cnt[dep[i] % (sq - 1)];
    int Max = *max_element(cnt, cnt + n + 1);
    cout << 1 << '\n';
    vector <int> ans;
    for(int i = 1; i <= n; i++) if(cnt[dep[i] % (sq - 1)] == Max) ans.push_back(i);
    ans.resize(sq);
    for(auto it : ans) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
