/*
 * Author:  heyuhhh
 * Created Time:  2019/12/14 20:12:26
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
const int N = 2e5 + 5, M = 5e5 + 5;

int n, m, a, b;
struct Edge {
    int v, next;
}e[M << 1];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;
}
int cnt;
int col[N];
void init() {
    for(int i = 1; i <= n; i++) head[i] = -1; tot = 0;   
}
void dfs(int u, int fa, int x) {
    col[u] = 1;
    if(u == x) return;   
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!col[v]) dfs(v, u, x);
    }
}

void run(){
    cin >> n >> m >> a >> b;
    init();
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adde(u, v); adde(v, u);
    }
    dfs(a, 0, b);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        cnt1 += 1 - col[i];
        col[i] = 0;   
    }
    dfs(b, 0, a);
    for(int i = 1; i <= n; i++) {
        cnt2 += 1 - col[i];   
        col[i] = 0;
    }
    ll ans = 1ll * cnt1 * cnt2;
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
