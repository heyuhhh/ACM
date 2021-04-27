#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;	
}
int n;
ll a[N];
ll p[63];

int pow2[N];
int fac[N], inv[N];
void init() {
	pow2[0] = 1;
	for (int i = 1; i < N; i++) {
		pow2[i] = 1ll * pow2[i - 1] * 2 % MOD;
	}
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
	}
	inv[N - 1] = qpow(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) {
		inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
	}
}

int C(int n, int m) {
	return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void ins(ll x) {
	for (int i = 61; i >= 0; i--) {
		if (x >> i & 1) {
			if (!p[i]) {
				p[i] = x;
				return;
			}
			x ^= p[i];
		}
	}
}

bool ok(ll x) {
	for (int i = 61; i >= 0; i--) {
		if (x >> i & 1) {
			if (p[i]) x ^= p[i];
			else return false;
		}
	}
	return true;
}

int count() {
	int res = 0;
	for (int i = 0; i < 62; i++) {
		res += (p[i] > 0);
	}
	return res;
}

ll pre[N], suf[N];

void add(int& x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void dec(int& x, int y) {
	x -= y;
	if (x < 0) x += MOD;
}

void run() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	if (n == 1) {
//		cout << 0 << '\n';
//		return;
//	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = (pre[i - 1] ^ a[i]);
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = (suf[i + 1] ^ a[i]);
	}
	int ans = 0;
	for (int i = n, j; i > 0; i = j) {
		j = i;
		while (j > 0 && a[i] == a[j]) --j;
		int num = i - j;
		for (int k = 1; k <= num; k++) {
			ll tmp = (pre[j] ^ (k & 1 ? a[i] : a[i] - 1) ^ ((num - k) & 1 ? a[i] : 0) ^ suf[i + 1]);
//			cout << tmp << endl;
			if (tmp == 0) {
				add(ans, C(num, k));
			}
			tmp = (pre[j] ^ (k & 1 ? a[i] - 1 : a[i]) ^ ((num - k) & 1 ? a[i] : 0));
			if (ok(tmp)) {
				add(ans, 1ll * C(num, k) * pow2[n - i - count()] % MOD);
				if (suf[i + 1] == tmp) {
					dec(ans, C(num, k));
				}
			}
//			cout << num << ' ' << k << ' ' << ans << endl;
		}
		ins(a[i]);
	}
	if (suf[1] == 0) add(ans, 1);
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	init();
	run();
	return 0;
}

