#include <bits/stdc++.h>
using namespace std;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int num[4][4];

const int maxs = 1 << 20;

int first[maxs], second[maxs], third[40320];
int q[maxs], qh, qt;

int incr[] = {-1, +1, 0, 0};
int incc[] = {0, 0, -1, +1};
int revd[] = {DOWN, UP, RIGHT, LEFT};
char dchar[] = "UDLR";

int getid(int *a) {
	int rnt = 0;
	for (int i = 0; i < 5; i++)
		rnt = rnt * 16 + a[i];
	return rnt;
}

void initF() {
	memset (first, -1, sizeof first);
	int inits = (((0 * 16 + 1) * 16 + 2) * 16 + 3);
	qh = qt = 0;
	for (int i = 4; i < 16; i++) {
		first[inits * 16 + i] = -2;
		q[qt++] = inits * 16 + i;
	}
	while (qh < qt) {
		int u = q[qh++];
		if (u != 0)
			u = u;
		int a[5];
		int tu = u;
		for (int i = 4; i >= 0; i--)
			a[i] = tu % 16, tu /= 16;
		for (int d = 0; d < 4; d++) {
			int cr, cc;
			cr = a[4] / 4 + incr[d], cc = a[4] % 4 + incc[d];
			if (cr >= 0 && cr < 4 && cc >= 0 && cc < 4) {
				int find = 0;
				for (int t = 0; t < 4; t++) {
					if (cr * 4 + cc == a[t]) {
						swap(a[t], a[4]);
						int id = getid(a);
						if (first[id] == -1) {
							first[id] = d * maxs + u;
							q[qt++] = id;
						}
						swap(a[t], a[4]);
						find = 1;
						break;
					}
				}
				if (!find) {
					int t = cr * 4 + cc;
					swap(a[4], t);
					int id = getid(a);
					if (first[id] == -1) {
						first[id] = d * maxs + u;
						q[qt++] = id;
					}					
					swap(a[4], t);
				}
			}
		}
	}
}

void initS() {
	memset (second, -1, sizeof second);
	int inits = (((4 * 16 + 5) * 16 + 6) * 16 + 7);
	qh = qt = 0;
	for (int i = 8; i < 16; i++) {
		second[inits * 16 + i] = -2;
		q[qt++] = inits * 16 + i;
	}
	while (qh < qt) {
		int u = q[qh++];
		int a[5];
		int tu = u;
		for (int i = 4; i >= 0; i--)
			a[i] = tu % 16, tu /= 16;
		for (int d = 0; d < 4; d++) {
			int cr, cc;
			cr = a[4] / 4 + incr[d], cc = a[4] % 4 + incc[d];
			if (cr >= 1 && cr < 4 && cc >= 0 && cc < 4) {
				int find = 0;
				for (int t = 0; t < 4; t++) {
					if (cr * 4 + cc == a[t]) {
						swap(a[t], a[4]);
						int id = getid(a);
						if (second[id] == -1) {
							second[id] = d * maxs + u;
							q[qt++] = id;
						}
						swap(a[t], a[4]);
						find = 1;
						break;
					}
				}
				if (!find) {
					int t = cr * 4 + cc;
					swap(a[4], t);
					int id = getid(a);
					if (second[id] == -1) {
						second[id] = d * maxs + u;
						q[qt++] = id;
					}					
					swap(a[4], t);
				}
			}
		}
	}
}

int getfid(int *p) {
	int f = 1, rnt = 0;
	for (int i = 0; i < 8; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) if (p[j] > p[i]) ++ cnt;
		rnt += cnt * f;
		f *= (i + 1);
	}
	return rnt;
}

void decode(int u, int *p) {
	int f = 5040;
	int vis[8] = {0};
	for (int i = 7; i >= 0; i--) {
		p[i] = u / f;
		u %= f;
		if (i) f /= i;
		int j, ct = 0;
		for (j = 7; j >= 0; j--) if (!vis[j]) {
			if (ct == p[i]) break;
			ct += !vis[j];
		}
		vis[j] = 1;
		p[i] = j;
	}
}

void initT() {
	memset (third, -1, sizeof third);
	int inits[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int id = getfid(inits);
	third[id] = -2;
	qh = qt = 0; q[qt++] = id;
	while (qh < qt) {
		int u = q[qh++];
		int t[8]; decode(u, t);
		for (int d = 0; d < 4; d++) {
			int cr, cc;
			cr = t[7] / 4 + incr[d], cc = t[7] % 4 + incc[d];
			if (cr >= 0 && cr < 2 && cc >= 0 && cc < 4) {
				int curv = cr * 4 + cc, index;
				for (int i = 0; i < 8; i++) if (t[i] == curv) {
					index = i; break;
				}
				swap(t[index], t[7]);
				int id = getfid(t);
				if (third[id] == -1) {
					third[id] = d * maxs + u;
					q[qt++] = id;
				}
				swap(t[7], t[index]);
			}
		}
	}
}

void init() {
	initF();
	initS();
	initT();
}

int getpos(int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num[i][j] == n) {
				return i * 4 + j;
			}
		}
	}
	return -1;
}

inline void perform(int& pr, int& pc, int d) {
	int p = pr * 4 + pc;
	pr -= incr[d];
	pc -= incc[d];
	num[p / 4][p % 4] = num[pr][pc];
	num[pr][pc] = 0;

}

char ans[130];

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
		int n = read(str), bf;
		 
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
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
	bool read(unsigned long long& x) {
		int n = read(str);
		if (!n) return 0;
		int i = 0;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
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
	}
	void write(char* str) {
		int n = strlen(str);
		memcpy(obuf + opt, str, n);
		opt += n;
	}
	void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt = 0;}
};

inline int conv(char *s) {
	int n = 0;
	for (int i = 0; s[i]; i++) n = n * 10 + s[i] - '0';
	return n;	
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	init();
	int ntcs; FI(ntcs);
	while (ntcs--) {
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) 
				FI(num[i][j]);
		int x, d, pr, pc, stk = 0;
		x = 0;
		for (int i = 1; i <= 4; i++) x = x * 16 + getpos(i);
		x = x * 16 + getpos(0);
		pr = getpos(0) / 4, pc = getpos(0) % 4;
		while (first[x] != -2) {
			d = first[x] / maxs;
			x = first[x] % maxs;
			perform(pr, pc, d);
			ans[stk++] = dchar[d];
		}
		x = 0;
		for (int i = 5; i <= 8; i++) x = x * 16 + getpos(i);
		x = x * 16 + getpos(0);
		while (second[x] != -2) {
			d = second[x] / maxs;
			x = second[x] % maxs;
			perform(pr, pc, d);
			ans[stk++] = dchar[d];
		}
		int t[8];
		for (int i = 9; i <= 16; i++) 
			t[i - 9] = getpos(i % 16);
		x = getfid(t);
		int iscan = 1;
		if (third[x] == -1) 
			iscan = 0;
		else {
			while (third[x] != -2) {
				d = third[x] / maxs;
				x = third[x] % maxs;
				ans[stk++] = dchar[d];
			}
		}
		if (iscan == 0) FO(-1), FO('\n');
		else {
			ans[stk] = 0;
			FO(stk);
			if (stk > 0) FO(' ');
			FO(ans);
			FO('\n');
		}
	}
	Flush;
	return 0;
}
