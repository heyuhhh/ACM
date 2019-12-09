#include <bits/stdc++.h>
using namespace std;

// long double _a, _b, _m;
// long long mul (long long a, long long b, long long m) {
// 	_a = a; _b = b; _m = m;
// 	return (long long)(_a * _b - _m * (long long)(_a * _b / _m));
// }

// long long mul(long long a, long long b, long long p) {
// 	long long res = 0;
// 	a %= p;
// 	while (b) {
// 		if (b & 1)res = (res + a) % p;	a = 2 * a % p; b >>= 1;
// 	}
// 	return res;
// }

__int128 _a, _b, _m;
long long mul (long long a, long long b, long long m) {
	_a = a, _b = b, _m = m;
	return (long long)(_a * _b % _m);
}

long long inv (long long a, long long b, long long m) {
	long long ret = 1;
	while (b) {
		if (b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}

inline bool check (long long n) {
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) return true;
	}
	return false;
}

int main (void) {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		long long p;
		scanf("%lld", &p);
		long long ret = p - 1, q = p - 1;
		while (check(q)) {
			ret = mul(ret, inv(q, p - 2, p), p);
			q --;
		}
		printf("%lld\n", ret);
	}
}