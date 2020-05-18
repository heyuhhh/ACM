/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 15:12:19
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
const int N = 2000 + 5;

int n;
pii a[N];
ll dp[N][N];

ll solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) {
        return 1ll * abs(a[n].se - l) * a[n].fi;   
    }
    ll& res = dp[l][r];
    int x = a[n - r + l].fi, p = a[n - r + l].se;
    res = max(solve(l + 1, r) + 1ll * abs(p - l) * x, solve(l, r - 1) + 1ll * abs(p - r) * x);
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = MP(x, i);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));
    ll ans = solve(1, n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
