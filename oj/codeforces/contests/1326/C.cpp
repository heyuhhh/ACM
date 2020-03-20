/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 22:44:51
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
const int N = 2e5 + 5, MOD = 998244353;

int n, k;
pii a[N];
int fac[N], inv[N];

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].fi, a[i].se = i;
    sort(a + 1, a + n + 1);
    ll ans = 0;
    vector <int> pos;
    for(int i = n - k + 1; i <= n; i++) ans += a[i].fi, pos.push_back(a[i].se);
    sort(all(pos));
    //fac[0] = 1;
    //for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    //inv[n] = qpow(fac[n], MOD - 2);
    //for(int i = n - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    int ans2 = 1;
    for(int i = 1; i < sz(pos); i++) {
        ans2 = 1ll * ans2 * (pos[i] - pos[i - 1]) % MOD;
    }
    cout << ans << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
