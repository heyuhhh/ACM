/*
 * Author:  heyuhhh
 * Created Time:  2020/5/31 21:11:22
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
#include <functional>
#include <numeric>
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
int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res;
}

int n, s;
int a[N];
int dp[N][N];

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;   
}

void run() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = qpow(2, n);
    int inv2 = (MOD + 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i]) {
                dp[i][j] = 1ll * dp[i - 1][j - a[i]] * inv2 % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[n][s] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
