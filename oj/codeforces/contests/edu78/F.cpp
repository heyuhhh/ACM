/*
 * Author:  heyuhhh
 * Created Time:  2019/12/21 12:40:57
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
const int N = 5005, MOD = 998244353;

int n, m, k;
int fac[N], S[N][N], C[N];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}

void run(){
    S[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= i; j++) {
            S[i][j] = (1ll * S[i - 1][j] * j % MOD + S[i - 1][j - 1]) % MOD;
        }
    }
    C[0] = 1;
    for(int i = 1; i < N; i++) C[i] = 1ll * C[i - 1] * (n - i + 1) % MOD;
    int invm = qpow(m, MOD - 2);
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = (ans + 1ll * C[i] * S[k][i] % MOD * qpow(invm, i) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}
