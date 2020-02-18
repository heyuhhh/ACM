/*
 * Author:  heyuhhh
 * Created Time:  2020/2/13 10:48:50
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
typedef pair<ll, ll> pll;
//head
const int N = 150000 + 5;

int n;
vector <int> G[N];
int a[N];

ll up[N], sum[N], down[N], deep[N];
ll ans[N];
ll pre[N], suf[N];

void dfs(int u, int fa) {
    ll Max = 0, Max2 = 0, id = 0, id2 = 0;
    vector <pair<int, pll>> nodes;
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        nodes.push_back(v);
        ll Up = up[v] + sum[v] + a[u];
        ll Dwon = (deep[v] + 1) * a[u] + down[v];
        if(Up > Max) {
            Max = Up; id = v;
        }
        if(Down > Max2) {
            Max2 = Down; id2 = v;   
        }
        nodes.push_back(MP(v, MP(Up, Down)));
    }
    up[u] = sum[id] + a[u] + up[id];
    sum[u] = sum[id] + a[u];
    down[u] = (deep[id2] + 1) * a[u] + down[id2];
    deep[u] = deep[id2] + 1;
    for(int i = 0; i < sz(nodes); i++) {
        if(i == 0) pre[i] = nodes[i].se.se;
        else pre[i] = max(pre[i - 1], nodes[i].se.se);
    }
    for(int i = sz(nodes) - 1; i >= 0; i--) {
        if(i == sz(nodes) - 1) suf[i] = nodes[i].se.se;
        else suf[i] = max(suf[i + 1], nodes[i].se.se);   
    }
    for(int i = 0; i < sz(nodes) - 1; i++) {
        int v = nodes[i].fi;
        ans[u] = max(ans[u], up[v] + suf[i + 1] + )
    }
}

void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0);
    ll res = 0;
    for(int i = 1; i <= n; i++) res = max(res, ans[i]);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
