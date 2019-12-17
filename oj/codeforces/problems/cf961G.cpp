/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 17:06:20
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
const int N = 2e5 + 5, MOD = 1e9 + 7;

int n, k;
int fac[N], inv[N];
ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

void run(){
    init();
    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        int w; cin >> w;
        sum = (sum + w) % MOD;
    }
    if(n == 1) {
        cout << sum << '\n';
        return;   
    }
    for(int i = 0, d = 1; i < k; i++, d = MOD - d) {
        int res = 1ll * d * inv[i] % MOD * inv[k - 1 - i] % MOD * qpow(k - i, n - 2) % MOD * (k - i + n - 1) % MOD;
        ans = (ans + res) % MOD;
    }
    ans = 1ll * ans * sum % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);;
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
