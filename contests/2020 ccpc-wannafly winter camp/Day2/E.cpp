/*
 * Author:  heyuhhh
 * Created Time:  2020/1/13 14:48:19
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;

map <int, int> s[N];

int n;
int sz[N];
vector <int> g[N];
ll ans[N];

void dfs(int u) {
    for(auto v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }   
}

//merge y to x
void merge(int x, int y) { 
    for(auto it : s[y]) {
        if(it.fi < 0 || it.fi == INF) continue;
        auto p = s[x].lower_bound(it.fi);
        auto p2 = p; --p2;
        if(p2 -> fi <= 0) {
            ans[x] += 1ll * (p -> fi - it.fi) * (p -> fi - it.fi);
        } else if(p -> fi >= INF) {
            ans[x] += 1ll * (p2 -> fi - it.fi) * (p2 -> fi - it.fi);
        } else {
            ans[x] -= 1ll * (p -> fi - p2 -> fi) * (p -> fi - p2 -> fi);
            ans[x] += 1ll * (p -> fi - it.fi) * (p -> fi - it.fi) + 1ll * (p2 -> fi - it.fi) * (p2 -> fi - it.fi);
        }
        s[x][it.fi] = 1;
    }   
}

void dfs2(int u) {
    int bson = -1, Max = 0;
    for(auto v : g[u]) {
        if(sz[v] > Max) {
            Max = sz[v];
            bson = v;   
        }
        dfs2(v);
    }
    if(bson != -1) {
        ll t = ans[bson];
        merge(bson, u);
        s[u].swap(s[bson]);
        swap(ans[u], ans[bson]);
        ans[bson] = t;
    }
    //dbg(u, ans[u]);
    //for(auto it = s[u].begin(); it != s[u].end(); ++it) {
        //dbg(it -> fi);   
    //}
    for(auto v : g[u]) if(v != bson) {
        merge(u, v);   
    }
}

void run(){
    for(int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);   
    }
    for(int i = 1; i <= n; i++) {
        s[i][i] = 1;
        s[i][-INF] = 1;
        s[i][INF] = 1;
        sz[i] = 1;
    }
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
