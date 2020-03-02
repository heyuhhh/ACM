/*
 * Author:  heyuhhh
 * Created Time:  2020/2/20 15:42:30
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
const int N = 1e5 + 5, MOD = 998244353, inv2 = 499122177;

ll f(ll l, ll r) {
    if(l > r) return 0;
    return 1ll * (l + r) % MOD * ((r - l + 1) % MOD) % MOD * inv2 % MOD;  
}

void run(){
    ll n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    if(m == 1) swap(n, m), swap(x, y);
    ll ans = 0, t = n * m;
    if(m == 1) {
        ans = k % MOD;
    } else if(n == 1) {
        ll d = max(min(y - 1, m - y) - 1, 0ll);
        if(k >= d + m) ans = f(k - m + 1, k);
        else if(k >= m - d) {
            ll l = m - d - 1;
            ans = f((k - l) / 2 + 1, k);
        } else ans = f(1, k);
    } else {
        if(k <= t) ans = f(1, k);
        else ans = f(k - t + 1, k);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
