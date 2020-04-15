/*
 * Author:  heyuhhh
 * Created Time:  2020/4/15 18:59:20
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
const int N = 1e5 + 5, MOD = 998244353;

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
    ll D; cin >> D;
    vector <ll> primes;
    for(ll i = 2; i * i <= D; i++) if(D % i == 0) {
        primes.push_back(i);
        while(D % i == 0) D /= i;
    }
    if(D > 1) primes.push_back(D);
    vector <ll> fac(100), inv(100);
    fac[0] = 1;
    for(int i = 1; i < 100; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[99] = qpow(fac[99], MOD - 2);
    for(int i = 98; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    auto calc = [&](ll x, ll y) {
        vector <ll> v;
        for(auto it : primes) if(x % it == 0) {
            int cnt = 0;
            while(x % it == 0) {
                if(y % it == 0) {
                    x /= it, y /= it;
                } else {
                    x /= it;
                    ++cnt;   
                }
            }
            v.push_back(cnt);
        }          
        ll res = fac[accumulate(all(v), 0)];
        for(auto it : v) res = res * inv[it] % MOD;
        return res;
    };
    int q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        ll g = __gcd(a, b);
        ll ans = calc(a, g) * calc(b, g) % MOD;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
