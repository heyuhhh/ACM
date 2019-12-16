/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 10:42:37
 * 展开第二类斯特林数
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
const int N = 5005, MOD = 1e9 + 7;

int n, k;
int fac[N], c[N], two[N];
int s[N][N];
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
    cin >> n >> k;
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    c[0] = 1;
    for(int i = 1; i <= k; i++) c[i] = 1ll * c[i - 1] * (n - i + 1) % MOD * qpow(i, MOD - 2) % MOD;
    two[0] = qpow(2, n);
    int inv2 = qpow(2, MOD - 2);
    for(int i = 1; i <= k; i++) two[i] = 1ll * two[i - 1] * inv2 % MOD;
    s[0][0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i; j++) {
            s[i][j] = (1ll * j * s[i - 1][j] % MOD + s[i - 1][j - 1]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = (ans + 1ll * fac[i] * s[k][i] % MOD * c[i] % MOD * two[i] % MOD) % MOD;   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
