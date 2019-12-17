/*
 * Author:  heyuhhh
 * Created Time:  2019/12/14 11:00:17
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
const int N = 55, MOD = 1e9 + 7;

ll n;
int m;
int s[N][N], fac[N], c[N];
ll a[N];

ll qpow(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void init() {
    s[0][0] = 1;
    for(int i = 1; i < N; i++) 
        for(int j = 1; j <= i; j++) 
            s[i][j] = (1ll * s[i - 1][j] * j % MOD + s[i - 1][j - 1]) % MOD;
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    c[0] = 1;
}

int calc(ll n, int k) {
    int res = 0;
    for(int i = 1; i <= k + 1; i++) c[i] = 1ll * c[i - 1] * ((n + 2 - i) % MOD) % MOD * qpow(i, MOD - 2) % MOD;
    for(int i = 1; i <= k; i++) {
        res = (res + 1ll * fac[i] * s[k][i] % MOD * c[i + 1] % MOD) % MOD;
    }   
    return res;
}

void run(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    int ans = 0;
    for(int k = 0; k <= m; k++) {
        int res = calc(n - a[k], m + 1), tmp = 0;
        for(int i = k + 1; i <= m; i++) {
            tmp = (tmp + qpow(a[i] - a[k], m + 1)) % MOD;   
        }
        res = (res + MOD - tmp) % MOD;
        ans = (ans + res) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
