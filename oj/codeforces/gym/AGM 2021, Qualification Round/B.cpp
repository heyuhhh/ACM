// Author : heyuhhh
// Created Time : 2021/03/13 14:08:24
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 5e5 + 5, K = 105, M = 505;
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
int col[N], c[N];
ll sum[K], f[K][M], dp1[K][M], dp2[K][M];
ll pre[K][M];

inline int add(int x, int y, int z) {
    return x + y >= z ? x + y - z : x + y;
}
inline int dec(int x, int y, int z) {
    return x - y < 0 ? x - y + z : x - y;
}

void run() {
    ll n, k, d;
    FI(n), FI(k), FI(d);
    for (int i = 0; i < n; ++i) {
        FI(col[i]);
        col[i] %= d;
    }
    for (int i = 0; i < n; ++i) {
        FI(c[i]);
        sum[i % k] += c[i];
    }
    for (int i = 0; i < n; ++i) {
        f[i % k][col[i]] += c[i];
    }
    memset(dp1, INF, sizeof(dp1));
    memset(dp2, INF, sizeof(dp2));
    for (int i = 0; i < d; ++i) {
        dp1[0][i] = sum[0] - f[0][i];
        dp2[k - 1][i] = sum[k - 1] - f[k - 1][i];
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int t = 0; t < d; t++) {
                dp1[i][j] = min(dp1[i][j], dp1[i - 1][t] + sum[i] - f[i][dec(j, t, d)]);
            }
        }
    }
    for (int i = k - 2; i >= 0; --i) {
        for (int j = 0; j < d; ++j) {
            for (int t = 0; t < d; ++t) {
                dp2[i][j] = min(dp2[i][j], dp2[i + 1][t] + sum[i] - f[i][dec(j, t, d)]);
            }
        }
    }
    memset(pre, INF, sizeof(pre));
    for (int i = 1; i < k - 1; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int t = 0; t < d; ++t) {
                pre[i][add(j, t, d)] = min(pre[i][add(j, t, d)], dp1[i - 1][j] + dp2[i + 1][t]);
            }
        }
    }
    int q;
    FI(q);
    while (q--) {
        int p;
        FI(p);
        --p;
        ll ans = 1e18;
        if (p % k == 0) {
            ans = sum[0] - f[0][col[p]] + dp2[1][(d - col[p]) % d];
        } else if (p % k == k - 1) {
            ans = sum[k - 1] - f[k - 1][col[p]] + dp1[k - 2][(d - col[p]) % d];
        } else {
            ans = sum[p % k] - f[p % k][col[p]] + pre[p % k][(d - col[p]) % d];
        }
        FO(ans), FO('\n');
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    run();
    Flush;
    return 0;
}