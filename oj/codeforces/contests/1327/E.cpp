/*
 * Author:  heyuhhh
 * Created Time:  2020/3/23 23:42:13
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

int n;
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
void run() {
    cin >> n;
    int ans = 0;    
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        if(i < n) {
            add(ans, 1ll * 180 * qpow(10, n - i - 1) % MOD);
            if(i + 2 <= n) add(ans, 1ll * 810 * qpow(10, n - i - 2) * (n - 1 - i) % MOD);
        } else add(ans, 10);
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
