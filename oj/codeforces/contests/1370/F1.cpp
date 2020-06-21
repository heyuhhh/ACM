/*
 * Author:  heyuhhh
 * Created Time:  2020/6/21 11:36:18
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
const int N = 1e3 + 5;
 
int n;
vector <int> G[N];
 
pii query(vector <int>& nodes) {
    if (sz(nodes) == 0) {
        while(true);
    }
    cout << "?" << ' ' << sz(nodes);
    for (auto it : nodes) {
        cout << ' ' << it;
    }
    cout << endl;
    int x, d; cin >> x >> d;
    return MP(x, d);
};
 
void answer(int s, int f) {
    cout << "!" << ' ' << s << ' ' << f << endl;
    string ss;
    cin >> ss;
    if (ss == "Incorrect") {
        while(true);
    }
}
 
vector <int> dep[N];
int deep[N];
int len;
 
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    dep[deep[u]].push_back(u);
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
    }
}
 
pii get(int x) {
    if (sz(dep[x]) == 0) {
        return MP(-1, -1);
    }
    vector <int> nodes;
    for (auto it : dep[x]) {
        nodes.push_back(it);
    }
    return query(nodes);
}
 
void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	G[i].clear();
	}
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector <int> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }
    pii now = query(nodes);
    int rt = now.fi;
    len = now.se;
    for (int i = 0; i <= n; i++) {
        dep[i].clear();
    }
    deep[0] = -1;
    dfs(rt, 0);
    int l = 0, r = n + 1, mid;
    int s, f;
    while (l < r) {
        mid = (l + r) >> 1;
        pii now = get(mid);
        if (now.se == len) {
            l = mid + 1;
            s = now.fi;
        } else {
            r = mid;
        }
    }
    for (int i = 0; i <= n; i++) {
        dep[i].clear();
    }
    dfs(s, 0);
    now = get(len);
    f = now.fi;
    answer(s, f);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
