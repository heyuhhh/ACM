/*
 * Author:  heyuhhh
 * Created Time:  2020/4/16 9:06:01
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
const int N = 3000 + 5, MOD = 998244353;

int n, m;
char s[N], t[N];
int dp[N][N];

int solve(int l, int r) {
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    int k = r - l + 1;
    int res = 0;
    if(l > m || s[k] == t[l]) res += solve(l + 1, r);
    if(r > m || s[k] == t[r]) res = (res + solve(l, r - 1)) % MOD;
    return dp[l][r] = res;
}

void run() {
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = m; i <= n; i++) {
        ans = (ans + solve(1, i)) % MOD;   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
