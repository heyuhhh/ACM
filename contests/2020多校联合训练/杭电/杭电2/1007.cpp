// Author : heyuhhh
// Created Time : 2020/07/24 10:09:05
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
const int N = 20000 + 5, M = 25;

int n, k;
struct Edge {
    int v, next, a, b;
}e[N << 1];
int head[N], tot;
void adde(int u, int v, int a, int b) {
    e[tot] = Edge{v, head[u], a, b};
    head[u] = tot++;
}

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

ll dp[N][M], t[M];
int sz[N];
bool flag;

void dfs(int u, int fa, ll x) {
    if (flag) return;
    sz[u] = 1;
    dp[u][0] = 0;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, a = e[i].a, b = e[i].b;
        if (v == fa) continue;
        dfs(v, u, x);
        if (flag) return;
        int up = min(sz[u] + sz[v] - 1, k);
        for (int j = 0; j <= up; j++) {
            t[j] = x + 1;
        }
        for (int j = 0; j < sz[u]; j++) {
            for (int p = 0; p < sz[v] && p + j <= up; p++) {
                if (dp[u][j] + dp[v][p] + b <= x) {
                    t[j + p] = min(t[j + p], max(dp[u][j], dp[v][p] + b));
                }
                if (dp[u][j] + dp[v][p] + a <= x) {
                    t[j + p + 1] = min(t[j + p + 1], max(dp[u][j], dp[v][p] + a));
                }
            }
        }
        sz[u] += sz[v];
        bool ok = false;
        for (int j = 0; j <= up; j++) {
            dp[u][j] = t[j];
            if (t[j] <= x) ok = true;
        }
        if (ok = false) {
            dp[1][k] = x + 1;
            flag = true;
            return;
        }
    }
}

void run() {
    FI(n), FI(k);
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    tot = 0;
    ll l = 1, r = 2, mid;
    for (int i = 1; i < n; i++) {
        int u, v, a, b;
        FI(u), FI(v), FI(a), FI(b);
        r += max(a, b);
        adde(u, v, a, b);
        adde(v, u, a, b);
    }
    while (l < r) {
        mid = (l + r) >> 1;
        flag = false;
        dfs(1, 0, mid);
        if (dp[1][k] <= mid) r = mid;
        else l = mid + 1;
    }
    FO(l), FO('\n');
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