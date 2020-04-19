/*
 * Author:  heyuhhh
 * Created Time:  2020/4/19 9:23:38
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
const int N = 1e3 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

int dp[N][N], ipow[N];
string str[N];
int a[N];

void run() {
    int n, m; cin >> n >> m;
    ipow[0] = 1, ipow[1] = qpow(26, MOD - 2);
    for(int i = 1; i <= m; i++) ipow[i] = 1ll * ipow[i - 1] * ipow[1] % MOD;
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < N; j++) if(dp[i][j]) {
            add(dp[i + 1][max(j - 1, 0)], dp[i][j]);
            add(dp[i + 1][j + 1], 1ll * dp[i][j] * 26 % MOD);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> str[i] >> a[i];
    for(int i = 1; i <= m; i++) {
        int s = 0;
        for(int j = 1; j <= n; j++) {
            int len = str[j].length();
            if(i >= len) {
                add(s, 1ll * (i - len + 1) * a[j] % MOD * ipow[len] % MOD);
            }
        }
        add(ans, 1ll * s * dp[m][i] % MOD);
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
