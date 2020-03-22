/*
 * Author:  heyuhhh
 * Created Time:  2020/3/22 9:18:57
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
const int N = 50 + 5, MOD = 998244353;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int fac[N], inv[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int n, m;
int dp[N][N][N];
int a[N], w[N];

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

int solve(int t) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int sum = 0, sa = 0, sb = 0;
    for(int i = 1; i <= n; i++) {
        sum += w[i];
        if(a[i] > 0) sa += w[i]; else sb += w[i];
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= j; k++) {
                int tsum = sum + a[t] * (j - (i - j));
                int now = w[t] + a[t] * k;
                int others = (a[t] > 0 ? sa + j - now : sb - j - now);
                add(dp[i + 1][j][k], 1ll * dp[i][j][k] * (tsum - others - now) % MOD * qpow(tsum, MOD - 2) % MOD);
                add(dp[i + 1][j + 1][k + 1], 1ll * dp[i][j][k] * now % MOD * qpow(tsum, MOD - 2) % MOD);
                add(dp[i + 1][j + 1][k], 1ll * dp[i][j][k] * others % MOD * qpow(tsum, MOD - 2) % MOD);
            }
        }   
    }
    int res = 0;
    for(int j = 0; j <= m; j++) {
        for(int k = 0; k <= j; k++) {
            int tt = w[t] + a[t] * k;
            res = (res + 1ll * tt * dp[m][j][k] % MOD) % MOD;
        }   
    }
    cout << res << '\n';
}

void run() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
    }
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) solve(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
