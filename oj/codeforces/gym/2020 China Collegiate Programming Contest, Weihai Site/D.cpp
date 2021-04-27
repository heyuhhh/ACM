#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;


namespace Factor {
	const int N = 1010000;
	ll C, fac[10010], n, mut, a[1001000];
	int T, cnt, i, l, prime[N], p[N], psize, _cnt;
	ll _e[100], _pr[100];
	vector<ll> d;
	inline ll mul(ll a, ll b, ll p) {
		if (p <= 1000000000) return a * b % p;
		else if (p <= 1000000000000ll) return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
		else {
			ll d = (ll) floor(a * (long double)b / p + 0.5);
			ll ret = (a * b - d * p) % p;
			if (ret < 0) ret += p;
			return ret;
		}
	}
	void prime_table() {
		int i, j, tot, t1;
		for (i = 1; i <= psize; i++) p[i] = i;
		for (i = 2, tot = 0; i <= psize; i++) {
			if (p[i] == i) prime[++tot] = i;
			for (j = 1; j <= tot && (t1 = prime[j] * i) <= psize; j++) {
				p[t1] = prime[j];
				if (i % prime[j] == 0) break;
			}
		}
	}
	void init(int ps) {
		psize = ps;
		prime_table();	
	}
	ll powl(ll a, ll n, ll p) {
		ll res = 1;
		while (n) {
			if (n & 1) res = mul(res, a, p);
			a = mul(a, a, p);
			n >>= 1;
		}
		return res;
	}
	bool witness(ll a, ll n) {
		int t = 0;
		ll u = n - 1;
		for (; ~u & 1; u >>= 1) ++t;
		ll x = powl(a, u, n), _x = 0;
		for (; t; t--) {
			_x = mul(x, x, n);
			if (_x == 1 && x != 1 && x != n - 1) return 1;
			x = _x;
		}
		return _x != 1;
	}
	bool miller(ll n) {
		if (n < 2) return 0;
		if (n <= psize) return p[n] == n;
		if (~n & 1) return 0;
		for (int j = 0; j <= 7; j++) {
			if (witness(rand() % (n - 1) + 1, n)) return 0;
		}
		return 1;
	}
	ll gcd(ll a, ll b) {
		return __gcd(a, b);	
	}
	ll rho(ll n) {
		for (;;) {
			ll X = rand() % n, Y, Z, T = 1, *lY = a, *lX = lY;
			int tmp = 20;
			C = rand() % 10 + 3;
			X = mul(X, X, n) + C; *(lY++) = X; lX++;
			Y = mul(X, X, n) + C; *(lY++) = Y;
			for (; X != Y;) {
				ll t = X - Y + n;
				Z = mul(T, t, n);
				if (Z == 0) return gcd(T, n);
				tmp--;
				if (tmp == 0) {
					tmp = 20;
					Z = gcd(Z, n);
					if (Z != 1 && Z != n) return Z;
				}
				T = Z;
				Y = *(lY++) = mul(Y, Y, n) + C;
				Y = *(lY++) = mul(Y, Y, n) + C;
				X = *(lX++);
			}
		}
	}
	void _factor(ll n) {
//		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			if (n % fac[i] == 0) n /= fac[i], fac[cnt++] = fac[i];
		}
//		cout << n << ' ' << p[n] << endl;
		if (n <= psize) {
			for (; n != 1; n /= p[n]) fac[cnt++] = p[n];
			return;
		}
//		cout << cnt << endl;
		if (miller(n)) fac[cnt++] = n;
		else {
			ll x = rho(n);
			_factor(x); _factor(n / x);
		}
	}
	void norm() {
		sort(fac, fac + cnt);
		_cnt = 0;
		for (int i = 0; i < cnt; i++) {
			if (i == 0 || fac[i] != fac[i - 1]) _pr[_cnt] = fac[i], _e[_cnt++] = 1;
			else _e[_cnt - 1]++;
		}
	}
	vector<pair<ll, ll>> factorG(ll n) {
		cnt = 0;
		_factor(n);
//		cout << 11 << endl;
		norm();
		vector<pair<ll, ll>> d;
		for (int i = 0; i < _cnt; i++) {
			d.emplace_back(make_pair(_pr[i], _e[i]));
		}
		return d;
	}
}

void run() {
	ll c;
	cin >> c;
	auto d = Factor::factorG(c);
	bool f = false;
	for (auto& it : d) {
		if (it.second > 1) f = true;
	}
	if (!f) {
		cout << "no" << '\n';
		return;
	}
	cout << "yes" << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	Factor::init(1000000);
	int T; cin >> T; while (T--)
	run();
	return 0;
}

