#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int inv[N];
void init() {
	inv[0] = inv[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
}
int _;
void run() {
	++_;
	int n, k;
	cin >> n >> k;
	cout << "Case #" << _ << ": ";
	if (n < k) {
		cout << 0 << '\n';
		return;
	}
	int ans = qpow(2, n);
	int t = 1;
	for (int i = 0; i < k; i++) {
		ans -= t;
		if (ans < 0) ans += MOD;
		t = 1ll * t * (n - i) % MOD * inv[i + 1] % MOD;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int T; cin >> T; while (T--)
	run();
	return 0;
}
