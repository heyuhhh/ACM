/*
 * Author:  heyuhhh
 * Created Time:  2020/3/3 23:44:14
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
const int N = 1000 + 5;

int n;
vector <int> G[N], sons[N];
bool chk[N];
int now;

void dfs(int u, int fa) {
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        sons[u].push_back(v);
    }   
}

int query(int u, int v) {
    cout << '?' << ' ' << u << ' ' << v << endl;
    int z; cin >> z;
    return z;   
}

int get(int u) {
    chk[u] = true;
    int SZ = sz(sons[u]);
    for(auto it : sons[u]) if(chk[it]) --SZ;
    if(SZ == 0) return u;
    for(auto it : sons[u]) if(!chk[it]) {
        return get(it);   
    }
}

void gao(int u) {
	now = u;
    int SZ = sz(sons[u]);
    for(auto it : sons[u]) if(chk[it]) --SZ;
    if(SZ == 0) {
        return;
    } else if(SZ == 1) {
        for(auto it : sons[u]) if(!chk[it]) {
            int to = get(it);
            int z = query(u, to);
            now = z; 
            if(z == to || z == u) return;   
            gao(now);
            return;   
        }
    } else {
        vector <int> v;
        for(auto it : sons[u]) if(!chk[it]) v.push_back(it);
        for(int i = 0; i < sz(v); i += 2) {
            if(i + 1 < sz(v)) {
                int z = query(v[i], v[i + 1]);
                if(z == v[i] || z == v[i + 1]) {
                    now = z;
                    gao(now);
                    return;
                }
            } else {
                int to = get(v[i]);
                int z = query(u, to);
                now = z;
                if(z == to || z == u) return;
                gao(now);
                return;
            }
        }
    }
}

void run() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    gao(1);
    cout << "!" << ' ' << now << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

/*
13
1 10
1 2
2 4
2 5
1 3
1 6
6 7
6 8
6 9
7 11
11 13
11 12
*/
