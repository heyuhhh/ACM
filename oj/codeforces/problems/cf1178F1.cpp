/*
 * Author:  heyuhhh
 * Created Time:  2020/3/18 9:35:47
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
const int N = 500 + 5, MOD = 998244353;

int n, m;
int c[N];
int pos[N][N], dp[N][N];

int solve(int l, int r) {
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    int p = pos[l][r];
    int res = 0, t = 0;
    for(int i = l; i <= p; i++) {
        t = (t + 1ll * solve(l, i - 1) * solve(i, p - 1) % MOD) % MOD;
    }
    for(int j = p; j <= r; j++) {
        res = (res + 1ll * t * solve(p + 1, j) % MOD * solve(j + 1, r) % MOD) % MOD;
    }
    return dp[l][r] = res;
}

void run() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) {
        int Min = c[i];
        pos[i][i] = i;
        for(int j = i + 1; j <= n; j++) {
            if(c[j] < Min) {
                Min = c[j];
                pos[i][j] = j;
            } else pos[i][j] = pos[i][j - 1];
        }   
    }
    solve(1, n);
    cout << dp[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
