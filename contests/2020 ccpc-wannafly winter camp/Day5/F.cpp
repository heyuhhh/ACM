/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 17:03:35
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
const int N = 205, M = 40000 + 5, MOD = 1e9 + 7;

int n, k;
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

int val[M];
int dp[N][M], f[N], g[M];

//传入前2*k项 
#define rep(i,a,n) for (int i=a;i<n;i++)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)

typedef vector<int> VI;
typedef long long ll;

ll powMOD(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a%MOD)if (b & 1)ans = ans * a%MOD;
    return ans;
}
namespace linear_seq {
    const int N = 10010;
    ll res[N], base[N], _c[N], _md[N];

    vector<int> Md;
    void mul(ll *a, ll *b, int k) {
        rep(i, 0, k + k) _c[i] = 0;
        rep(i, 0, k) if (a[i]) rep(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % MOD;
        for (int i = k + k - 1; i >= k; i--) if (_c[i])
            rep(j, 0, SZ(Md)) _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % MOD;
        rep(i, 0, k) a[i] = _c[i];
    }
    int solve(ll n, VI a, VI b) { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
        ll ans = 0, pnt = 0;
        int k = SZ(a);
        assert(SZ(a) == SZ(b));
        rep(i, 0, k) _md[k - 1 - i] = -a[i]; _md[k] = 1;
        Md.clear();
        rep(i, 0, k) if (_md[i] != 0) Md.push_back(i);
        rep(i, 0, k) res[i] = base[i] = 0;
        res[0] = 1;
        while ((1ll << pnt) <= n) pnt++;
        for (int p = pnt; p >= 0; p--) {
            mul(res, res, k);
            if ((n >> p) & 1) {
                for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i]; res[0] = 0;
                rep(j, 0, SZ(Md)) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % MOD;
            }
        }
        rep(i, 0, k) ans = (ans + res[i] * b[i]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
    VI BM(VI s) {
        VI C(1, 1), B(1, 1);
        int L = 0, m = 1, b = 1;
        rep(n, 0, SZ(s)) {
            ll d = 0;
            rep(i, 0, L + 1) d = (d + (ll)C[i] * s[n - i]) % MOD;
            if (d == 0) ++m;
            else if (2 * L <= n) {
                VI T = C;
                ll c = MOD - d * powMOD(b, MOD - 2) % MOD;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % MOD;
                L = n + 1 - L; B = T; b = d; m = 1;
            }
            else {
                ll c = MOD - d * powMOD(b, MOD - 2) % MOD;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % MOD;
                ++m;
            }
        }
        return C;
    }
    int gao(VI a, ll n) {
        VI c = BM(a);
        c.erase(c.begin());
        rep(i, 0, SZ(c)) c[i] = (MOD - c[i]) % MOD;
        return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
    }
};

void run(){
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    for(int i = 0; i < M; i++) val[i] = qpow(i, k);
    g[0] = dp[0][0] = 1;
    for(int i = 1; i <= 2 * k; i++) {
        for(int j = 0; j <= (i - 1) * i / 2; j++) {
            if(j - i >= 0) dp[i][j] = (g[j] - g[j - i] + MOD) % MOD;
            else dp[i][j] = g[j];
        }
        g[0] = dp[i][0];
        for(int j = 1; j < M; j++) {
            g[j] = (g[j - 1] + dp[i][j]) % MOD;
        }
    }
    for(int i = 1; i <= 2 * k; i++) {
        for(int j = 0; j <= i * (i - 1) / 2; j++) {
            f[i] = (f[i] + 1ll * dp[i][j] * val[j] % MOD) % MOD;
        }
    }
    if(n <= 2 * k) {
        cout << f[n];
        return;   
    }
    vector <int> v;
    for(int i = 1; i <= 2 * k; i++) {
        f[i] = 1ll * f[i] * inv[i] % MOD;
        v.push_back(f[i]);
    }
    int res = linear_seq :: gao(v, n);
    for(int i = 2; i <= n; i++) res = 1ll * res * i % MOD;
    cout << res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
