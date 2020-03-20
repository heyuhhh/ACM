/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 20:57:08
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
#include <random>
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
const int N = 1e6 + 5;

int n, m;

struct Edge {
    int u, v;
} edges[N];

vector <pii> G[N];
vector <int> res;
bool chk[N], out[N];
int d[N], f[N];

void dfs(int u, int fa) {
    chk[u] = true;
    for(auto it : G[u]) if(it.fi != fa) {
        int v = it.fi, i = it.se;
        if(out[i]) continue;
        if(chk[v]) {
            if(f[u] - 1 >= (d[u] + 1) / 2 && f[v] - 1 >= (d[v] + 1) / 2) {
                out[i] = true;
                --f[u], --f[v];
            }
            continue;
        }
        dfs(v, u);
    }   
}

mt19937 rnd(time(NULL));

void run() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(MP(v, i));
        G[v].push_back(MP(u, i));
        edges[i] = Edge {u, v};
        ++d[u], ++d[v];
    }
    for(int i = 1; i <= n; i++) f[i] = d[i];
    if(m <= n) {
        cout << m << '\n';
        for(int i = 1; i <= m; i++) {
            cout << edges[i].u << ' ' << edges[i].v << '\n';   
        }
    } else {
        for(int i = 1; i <= 20; i++) {
            memset(chk, false, sizeof(chk));
            int rt = rnd() % n + 1;
            dfs(rt, 0);   
        }
        for(int i = 1; i <= m; i++) if(!out[i]) res.push_back(i);
        cout << sz(res) << '\n';
        for(auto it : res) {
            cout << edges[it].u << ' ' << edges[it].v << '\n';   
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
