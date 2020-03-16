/*
 * Author:  heyuhhh
 * Created Time:  2020/3/16 20:44:37
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
const int N = 2e5 + 5, M = 800 + 5;

int n, m, k;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &A) const {
        return w < A.w; 
    }  
}e[N];
ll dis[M][M];
int mp[N], tot;

void run() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = Edge {u, v, w};
    }
    sort(e + 1, e + m + 1);
    memset(dis, INF, sizeof(dis));
    for(int i = 1; i <= min(m, k); i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(!mp[u]) mp[u] = ++tot;
        if(!mp[v]) mp[v] = ++tot;
        dis[mp[u]][mp[v]] = dis[mp[v]][mp[u]] = w;
    }
    for(int t = 1; t <= tot; t++) {
        for(int i = 1; i <= tot; i++) {
            for(int j = 1; j <= tot; j++) {
                dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);   
            }
        }   
    }
    vector <ll> v;
    for(int i = 1; i <= tot; i++) {
        for(int j = i + 1; j <= tot; j++) {
            v.push_back(dis[i][j]);
        }   
    }
    sort(all(v));
    cout << v[k - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
