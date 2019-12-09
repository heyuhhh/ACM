/*
 * Author:  heyuhhh
 * Created Time:  2019/11/18 22:19:29
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
const int N = 505;

int A, n, MOD;
int g[N][N << 1];

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
	static const int SIZE = N << 1;
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
		//设置f初值，可以根据需要修改
		for (int i = 0; i < n / 2; ++i) f[i] = 0;			
    }
	ll calc(ll x) {
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
}lagrange;

void run(){
    lagrange.init(2 * n);
    int fac = 1;
    for(int i = 1; i <= n; i++) fac = 1ll * fac * i % MOD;
    for(int up = n; up <= 2 * n; up++) {
        for(int i = n; i >= 1; i--) {
            for(int j = i; j + n - i <= up; j++) {
                if(i == n) g[i][j] = j % MOD;
                else g[i][j] = 1ll * g[i + 1][j + 1] * j % MOD;
            }
            for(int j = up - n + i; j >= i; j--) g[i][j] = (g[i][j] + g[i][j + 1]) % MOD;
        }
        lagrange.f[up] = 1ll * g[1][1] * fac % MOD;
    }
    int ans = lagrange.calc(A);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> A >> n >> MOD) run();
	return 0;
}
