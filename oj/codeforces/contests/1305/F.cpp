/*
 * Author:  heyuhhh
 * Created Time:  2020/3/4 10:56:42
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
#include <random>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f3f3f3f3f
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
const int N = 2e5 + 5, MAX = 2e6 + 5;

int n;
ll a[N];

mt19937 rnd(time(NULL));

int primes[MAX], tot;
bool chk[MAX];

void init() {
    for(int i = 2; i < MAX; i++) {
        if(!chk[i]) primes[++tot] = i;
        for(ll j = 1ll * i * i; j < MAX; j += i) chk[j] = true;
    }   
}

ll gao(ll x) {
    if(x == 1) return INF;
    auto solve = [&] (ll pri) {
        ll res = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] < pri) res += pri - a[i];
            else res += min(a[i] % pri, pri - a[i] % pri);
        }   
        return res;       
    };
    ll ans = INF;
    for(int i = 1; i <= tot; i++) {
        if(primes[i] > x) break;
        if(x % primes[i] == 0) {
            ans = min(ans, solve(primes[i]));
            while(x % primes[i] == 0) x /= primes[i];        
        }
    }
    if(x > 1) ans = min(ans, solve(x));
    return ans;
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = n;
    for(int i = 1; i <= 20; i++) {
        int id = rnd() % n + 1;
        for(int j = -1; j <= 1; j++) ans = min(ans, gao(a[id] + j));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
