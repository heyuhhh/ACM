
/*
 * Author:  heyuhhh
 * Created Time:  2020/1/17 13:13:29
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
const int N = 55 + 5, MOD = 998244353;

int fac[N], inv[N];
int f[N][N];

int qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;   
}

ll C(int n, int m) {
    if(n < m) return 0;
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;   
}

void run(){
    int n; ll K; cin >> n >> K;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = 0; k < j; k++) {
                if(K % (i - k) == 0) {
                    f[i][j] = (f[i][j] + 1ll * f[k][j - 1] * C(i, i - k) % MOD * fac[i - k - 1] % MOD) % MOD;
                    if(i == n) dbg(k, i, j, f[k][j - 1]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + f[n][i]) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    int T; cin >> T;
    while(T--) run();
    return 0;
}
