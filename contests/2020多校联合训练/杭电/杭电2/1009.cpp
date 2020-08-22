// Author : heyuhhh
// Created Time : 2020/07/24 19:03:09
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
const int N = 400 + 5;

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

int n, m, q;
int w[N][N];
int tag[N][N];
int cnt[N * N];
char s[4000000 + 5];

void run() {
    FI(n), FI(m), FI(q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            FI(w[i][j]);
            cnt[w[i][j]] = -1;
        }
    }
    while (q--) {
        int sx, sy;
        FI(sx), FI(sy);
        FI(s);
        int len = strlen(s);
        int L = m + 1, R = 0, D = n + 1, U = 0;
        int x = sx, y = sy;
        for (int i = 0; i < len; i++) {
            L = min(L, x);
            R = max(R, x);
            D = min(D, y);
            U = max(U, y);
            if (s[i] == 'L') --x;
            if (s[i] == 'R') ++x;
            if (s[i] == 'D') --y;
            if (s[i] == 'U') ++y;
        }
        ++L, ++D;
        assert(D <= U && L <= R);
        for (int i = L; i <= R; i++) {
            for (int j = D; j <= U; j++) {
                tag[i][j] = 0;
            }
        }
        x = sx, y = sy;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'R') {
                ++x;
                tag[x][y + 1] = 1;
            }
            if (s[i] == 'L') {
                tag[x][y + 1] = 1;
                --x;
            }
            if (s[i] == 'D') {
                --y;
            }
            if (s[i] == 'U') {
                ++y;
            }
        }
        int ans = 0;
        for (int i = L; i <= R; i++) {
            int op = 0;
            for (int j = D; j <= U; j++) {
                op ^= tag[i][j];
                if (op) {
                    if (cnt[w[i][j]] != q) {
                        cnt[w[i][j]] = q;
                        ++ans;
                    }
                }
            }
        }

        FO(ans), FO('\n');
    }
}
int main() {
    int T; cin >> T; while(T--)
    run();
    Flush;
    return 0;
}