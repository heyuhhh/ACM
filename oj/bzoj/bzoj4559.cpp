/*
 * Author:  heyuhhh
 * Created Time:  2019/11/21 9:12:18
 */
#include <bits/stdc++.h>
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
const int N = 105, MOD = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}

struct Lagrange {
	static const int SIZE = 110;
	ll f[SIZE], fac[SIZE], inv[SIZE], pre[SIZE], suf[SIZE];
	int n;
	inline void add(ll &x, int y) {
		x += y;
		if(x >= MOD) x -= MOD;
	}
	void init(int _n) {
		n = _n;
		fac[0] = 1;
		for (int i = 1; i < SIZE; ++i) fac[i] = fac[i - 1] * i % MOD;
	    inv[SIZE - 1] = qpow(fac[SIZE - 1], MOD - 2);
		for (int i = SIZE - 1; i >= 1; --i) inv[i - 1] = inv[i] * i % MOD;
        f[0] = 0;
	}
	ll calc(ll x, int r, int u) {
        for(int i = 1; i <= n; i++) {
            f[i] = (f[i - 1] + qpow(i, n - r) * qpow(u - i, r - 1) % MOD) % MOD;   
        }
		if (x <= n) return f[x];
		pre[0] = x % MOD;
		for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * ((x - i) % MOD) % MOD;
		suf[n] = (x - n) % MOD;
		for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * ((x - i) % MOD) % MOD;
		ll res = 0;
		for (int i = 0; i <= n; ++i) {
			ll tmp = f[i] * inv[n - i] % MOD * inv[i] % MOD;
			if (i) tmp = tmp * pre[i - 1] % MOD;
			if (i < n) tmp = tmp * suf[i + 1] % MOD;
			if ((n - i) & 1) tmp = MOD - tmp;
			add(res, tmp);
		}
		return res;
	}
}larg;

int n, m, k;
ll dp[N][N];
ll u[N], r[N];
ll C[N][N];

void init() {
    C[0][0] = 1;
    for(int i = 1; i < N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

void run(){
    for(int i = 1; i <= m; i++) cin >> u[i];
    for(int i = 1; i <= m; i++) cin >> r[i];
    dp[0][n - 1] = 1;
    larg.init(n);
    for(int i = 1; i <= m; i++) {
        ll g = larg.calc(u[i], r[i], u[i]);
        for(int j = k; j < n; j++) {
            for(int p = j; p < n; p++) {
                if(p - j > r[i] - 1) break;
                dp[i][j] += dp[i - 1][p] * C[p][p - j] % MOD * C[n - p - 1][r[i] - 1 - p + j] % MOD * g % MOD;
                dp[i][j] %= MOD;
            }
        } 
    }
    cout << dp[m][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    while(cin >> n >> m >> k) run();
	return 0;
}
