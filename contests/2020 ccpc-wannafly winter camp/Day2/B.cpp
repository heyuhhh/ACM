/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 9:23:17
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
const int N = 50 + 5, MOD = 1e9 + 7;

int n, K;
int a[N], f[N][N];

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

int solve(int k) {
    if(k < 0) return 1;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    int t = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] >> k & 1) {
            ++t;
            for(int j = 0; j <= t; j++) {
                if(j) f[t][j] = 1ll * f[t - 1][j - 1] * ((a[i] & ((1 << k) - 1)) + 1) % MOD;
                f[t][j] = (f[t][j] + 1ll * f[t - 1][j] * (1 << k) % MOD) % MOD;
            }
        } else {
            for(int j = 0; j <= t; j++) {
                f[t][j] = 1ll * f[t][j] * ((a[i] & ((1 << k) - 1)) + 1) % MOD;
            }
        }
    }
    int i, inv = qpow(1 << k, MOD - 2);
    for(i = (K >> k) & 1; i < t; i += 2) {
        ans += 1ll * inv * f[t][i] % MOD;
        if(ans >= MOD) ans %= MOD;
    }
    if(i == t) ans = (ans + solve(k - 1)) % MOD;
    return ans;
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(30) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> K) run();
    return 0;
}
