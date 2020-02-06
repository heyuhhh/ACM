/*
 * Author:  heyuhhh
 * Created Time:  2020/1/23 20:32:41
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
const int N = 2e5 + 5;

int n;
vector <int> G[N];

bool chk[N], vis[N];
int from[N], d[N];
int s, Max;

void dfs(int u, int fa, int d) {
    from[u] = fa;
    if(d > Max) {
        Max = d;
        s = u;
    }
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u, d + 1);   
    }
}

void dfs2(int u, int fa) {
    for(auto v : G[u]) if(v != fa && !chk[v]) {
        d[v] = d[u] + 1;
        dfs2(v, u);
    }   
}

void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    vector <int> p;
    Max = 0;
    dfs(1, 0, 1);
    p.push_back(s);
    Max = 0;
    dfs(s, 0, 1);
    p.push_back(s);
    int ans = 0;
    while(s) {
        chk[s] = true;
        s = from[s];
        if(s) ++ans;   
    }
    for(int i = 1; i <= n; i++) if(chk[i]) dfs2(i, 0);
    Max = 0;
    for(int i = 1; i <= n; i++) if(d[i] > Max) {
        Max = d[i]; s = i;   
    }
    if(Max) p.push_back(s);
    else {
        for(int i = 1; i <= n; i++) {
            int f = 0;
            for(int j = 0; j < sz(p); j++) {
                if(i == p[j]) f = 1;
            }
            if(!f) {
                p.push_back(i);
                break;   
            }
        }   
    }
    ans += Max;
    cout << ans << '\n';
    for(auto it : p) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
