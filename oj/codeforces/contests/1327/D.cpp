/*
 * Author:  heyuhhh
 * Created Time:  2020/3/24 0:28:41
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
const int N = 2e5 + 5;

int n;
int p[N], pos[N], c[N];
bool chk[N];
vector <int> G[N];
vector <int> v;

void dfs(int u) {
    chk[u] = true;
    v.push_back(c[pos[u]]);
    for(auto to : G[u]) if(!chk[to]) dfs(to);
}

int solve(int k) {
    for(int i = 0; i < k; i++) {
        bool ok = true;
        for(int j = i + k; j < sz(v); j += k) {
            if(v[j - k] != v[j]) ok = false;
        }
        if(ok) return k;
    }
    return n;
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) G[i].clear(), chk[i] = false;
    for(int i = 1; i <= n; i++) {
        cin >> p[i]; pos[p[i]] = i;
        G[i].push_back(p[i]);
    }
    for(int i = 1; i <= n; i++) cin >> c[i];
    int ans = n;
    for(int i = 1; i <= n; i++) if(!chk[i]) {
        v.clear();
        dfs(i);   
        int k = sz(v);
        for(int j = 1; j * j <= k; j++) if(k % j == 0) {
            ans = min(ans, min(solve(j), solve(k / j)));
        }
    }
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
