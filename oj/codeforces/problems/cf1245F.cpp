/*
 * Author:  heyuhhh
 * Created Time:  2020/3/8 16:01:12
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
const int N = 31;

ll dp[N][2][2];

ll dfs(int l, int r, int k, int up1, int up2) {
    if(k == -1) return 1;
    if(dp[k][up1][up2] != -1) return dp[k][up1][up2];
    ll res = 0;
    int a = 1, b = 1;
    if(up1) a = (l >> k & 1);
    if(up2) b = (r >> k & 1);
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(!(i & j)) {
                res += dfs(l, r, k - 1, up1 & (i == a), up2 & (j == b));
            }
        }   
    }    
    return dp[k][up1][up2] = res;
}

ll solve(int l, int r) {
    if(l < 0 || r < 0) return 0;
    memset(dp, -1, sizeof(dp));
    ll res = dfs(l, r, 30, 1, 1);
    return res;
}

void run() {
    int l, r; cin >> l >> r;
    ll ans = solve(r, r) - solve(l - 1, r) - solve(r, l - 1) + solve(l - 1, l - 1);
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
