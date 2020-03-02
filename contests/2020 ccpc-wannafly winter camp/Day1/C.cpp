/*
 * Author:  heyuhhh
 * Created Time:  2020/1/12 22:57:43
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
const int N = 1e5 + 5, MOD = 998244353;

int n, l, r;

int C(int n) {
    return 1ll * n * (n - 1) / 2 % MOD;
}

int sum(int a, int b) {
    return 1ll * (a + b) * (b - a + 1) / 2 % MOD;   
}

void run() {
    cin >> n >> l >> r;
    int ans = 1ll * (r - l + 1) * C(n) % MOD, res = 0;
    int rb = min(r, n - 1);
    for(int i = l, j; i <= rb; i = j + 1) {
        j = min(rb, min(n / (n / i), (n - 1) / ((n - 1) / i)));
        res += (1ll * sum(i, j) * C(n / i) % MOD + 1ll * (1ll * n * (j - i + 1) % MOD 
            - 1ll * sum(i, j) * (n / i) % MOD + MOD) * (C((n - 1) / i + 1) - C(n / i) + MOD) % MOD) % MOD;
        if(res >= MOD) res -= MOD;
    }
    ans -= res;
    if(ans < 0) ans += MOD;
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
