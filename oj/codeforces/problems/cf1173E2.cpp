/*
 * Author:  heyuhhh
 * Created Time:  2020/3/22 19:30:09
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
const int N = 2e5 + 5, M = 3005, MOD = 998244353;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

int n, m;
int a[N], w[N];
int dp[M][M];

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;   
}

void run() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> w[i];
    int sa = 0, sb = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i]) sa += w[i];
        else sb += w[i];   
    }
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= i; j++) {
            int sum = sa + j + sb - (i - j);
            add(dp[i + 1][j + 1], 1ll * dp[i][j] * (sa + j) % MOD * qpow(sum, MOD - 2) % MOD);
            add(dp[i + 1][j], 1ll * dp[i][j] * (sb - (i - j)) % MOD * qpow(sum, MOD - 2) % MOD);
        }   
    }
    int ea = 0, eb = 0;
    for(int j = 0; j <= m; j++) {
        add(ea, 1ll * dp[m][j] * (sa + j) % MOD);
        add(eb, 1ll * dp[m][j] * (sb - (m - j)) % MOD);
    }
    sa = qpow(sa, MOD - 2), sb = qpow(sb, MOD - 2);
    for(int i = 1; i <= n; i++) {
        int res;
        if(a[i]) res = 1ll * ea * sa % MOD * w[i] % MOD;
        else res = 1ll * eb * sb % MOD * w[i] % MOD;
        cout << res << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
