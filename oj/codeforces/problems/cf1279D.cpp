/*
 * Author:  heyuhhh
 * Created Time:  2019/12/28 10:24:17
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
const int N = 1e6 + 5, MOD = 998244353;

int n;
int a[N], b[N];

int qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}

void run(){
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        int inv = qpow(x, MOD - 2);
        for(int j = 1; j <= x; j++) {
            int y; cin >> y;
            ++a[y]; b[y] = (b[y] + inv) % MOD;
        }   
    }
    int ans = 0;
    int invn = qpow(n, MOD - 2);
    for(int i = 1; i < N; i++) if(a[i]) {
        ans = (ans + 1ll * b[i] * a[i] % MOD * invn) % MOD;
    }
    ans = 1ll * ans * invn % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
