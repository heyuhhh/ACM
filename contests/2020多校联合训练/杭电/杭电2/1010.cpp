// Author : heyuhhh
// Created Time : 2020/07/23 12:57:36
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
const int N = 50 + 5;

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

int n, k;
int a[N], b[N], c[N], d[N];
int type[N][N];
int num[N];
int sa, sb, sc, sd;

ll ans;

void dfs(int cur) {
    if (cur == 0) {
        ans = max(ans, 1ll * sa * sb * sc * sd);
        return;
    }
    int prea, preb, prec, pred;
    prea = preb = prec = pred = -1;
    if (num[cur]) for (register int i = 1; i <= num[cur]; ++i) {
        int id = type[cur][i];
        sa += a[id], sb += b[id], sc += c[id], sd += d[id];
        if (prea == -1) {
            prea = sa;
            preb = sb;
            prec = sc;
            pred = sd;
            dfs(cur - 1);
        } else {
            if (sa <= prea && sb <= preb && sc <= prec && sd <= pred) {
            } else {
                dfs(cur - 1);
            }
            prea = min(prea, sa);
            preb = min(preb, sb);
            prec = min(prec, sc);
            pred = min(pred, sd);
        }
        sa -= a[id], sb -= b[id], sc -= c[id], sd -= d[id];
    } else {
        dfs(cur - 1);
    }
}

void run() {
    FI(n), FI(k);
    for (register int i = 1; i <= k; ++i) {
        num[i] = 0;
    }
    ans = 0;
    for (register int i = 1; i <= n; ++i) {
        int t; FI(t);
        FI(a[i]), FI(b[i]), FI(c[i]), FI(d[i]);
        type[t][++num[t]] = i;
    }
    sa = sb = sc = sd = 100;
    dfs(k);
    FO(ans), FO('\n');
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    int T; FI(T); while(T--)
    run();
    Flush;
    return 0;
}