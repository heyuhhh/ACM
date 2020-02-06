/*
 * Author:  heyuhhh
 * Created Time:  2020/1/25 12:09:26
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
const int N = 3000 + 5;

vector <int> G[N];

int n;
ll dp[N][N];
int cnt[N][N], fa[N][N];

void dfs(int u, int f, int rt) {
    cnt[rt][u] = 1;
    fa[rt][u] = f;
    for(auto v : G[u]) if(v != f) {
        dfs(v, u, rt);
        cnt[rt][u] += cnt[rt][v];
    }   
}

ll solve(int x, int y) {
    if(x == y) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = cnt[y][x] * cnt[x][y] + max(solve(x, fa[x][y]), solve(y, fa[y][x]));
    return dp[x][y];   
}

void run(){
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        dfs(i, 0, i);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
