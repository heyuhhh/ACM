#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5, M = 21, MOD = 1e9 + 7;

#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Flush FastIO::Fflush()
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	double D[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001};
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf = 0;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = 1, i++; else if (str[i] == '+') i++;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf) x = -x;
		return 1;
	}
	bool read(long long& x) {
		int n = read(str), bf;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
	void write(int x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			if (x < 0) obuf[opt++] = '-', x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			if (x < 0) obuf[opt++] = '-', x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(unsigned long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(char x) {
		obuf[opt++] = x;
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt = 0;}
};
int n, m;
int a[N];
vector<pii> Q[N];
int dp1[N][M], dp2[N][M];
int ans[N];

void solve(int l, int r) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	dp1[0][0] = dp2[0][0] = 1;
	for (int i = 1; i <= mid - l + 1; i++) {
		for (int j = 0; j < m; j++) {
			dp1[i][j] = (dp1[i - 1][j] + dp1[i - 1][(j - a[mid - i + 1] + m) % m]) % MOD;
		}
	}
	for (int i = 1; i <= r - mid; i++) {
		for (int j = 0; j < m; j++) {
			dp2[i][j] = (dp2[i - 1][j] + dp2[i - 1][(j - a[mid + i] + m) % m]) % MOD;
		}
	}
	for (int i = l; i <= mid; i++) {
		while (sz(Q[i]) && Q[i].back().first >= mid) {
			pii now = Q[i].back(); Q[i].pop_back();
			int r = now.first, id = now.second;
			int L = mid - i + 1, R = r - mid;
			for (int j = 0; j < m; j++) {
				ans[id]	= (ans[id] + 1ll * dp1[L][j] * dp2[R][(m - j) % m] % MOD) % MOD;
			}
		}
	}
	solve(l, mid - 1);
	solve(mid + 1, r);
}

void run() {
	FI(n), FI(m);
	for (int i = 1; i <= n; i++) {
		FI(a[i]);
		a[i] %= m; 
	}
	int q;
	FI(q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		FI(l), FI(r);
		Q[l].emplace_back(r, i);
	}
	for (int i = 1; i <= n; i++) {
		sort(all(Q[i]));
	}
	solve(1, n);
	for (int i = 1; i <= q; i++) {
		FO(ans[i]), FO('\n');
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	run();
	Flush; 
	return 0;
}

