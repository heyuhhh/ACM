/*
 * Author:  heyuhhh
 * Created Time:  2020/6/12 19:03:55
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
const ll MAX = 1e12;

int n, m, k;
ll mod;

map <ll, int> mp;

ll fmul(ll a,ll b,ll mod){
    if (a >= mod) a %= mod;
    if (b >= mod) b %= mod;
    if (min(a, b) == 0) return 0;
	ll ans = 0;
	while (b) {
		if (b & 1) {
			ans = ans + a;
            if (ans >= mod) ans %= mod;
		}
        b >>= 1;
        a = a + a;
        if (a >= mod) a %= mod;
	}
	return ans;
}

ll qpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) res = fmul(res, a, mod);
        a = fmul(a, a, mod);
        b >>= 1;
        if (min(res, a) == 0) return 0;
    }
    return res;
}

void run() {
    cin >> n >> m >> k >> mod;
    if (k == 1) {
        cout << (1 % mod) << '\n';
        return;
    }
    ll t = 1;
    for (int x = 0; t <= MAX; t *= k, ++x) {
        mp[t] = x;
    }
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            ll x; cin >> x;
            cnt += mp[x];
        }
        Max = max(Max, cnt);
    }
    ll ans = qpow(k, Max);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
