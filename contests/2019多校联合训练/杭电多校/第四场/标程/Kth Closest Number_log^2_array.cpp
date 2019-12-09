#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const int M = 2000000;

struct Node {
	int l, r, p;
} a[M];

int nodes;
int root[N];

int b[N], id[N];

inline int add_node(int u) {
	a[++nodes] = a[u];
	a[nodes].p = a[u].p + 1;
	return nodes;
}

inline int modify(int u, int l, int r, int p, int x) {
	int ret = add_node(x);
	if (l == r) return ret;
	int mid = l + r >> 1;
	if (p <= mid) a[ret].l = modify(u + u, l, mid, p, a[ret].l);
	else a[ret].r = modify(u + u + 1, mid + 1, r, p, a[ret].r);
	return ret;
}

int tot, K;

void query(int u, int l, int r, int ll, int rr, int x, int y) {
	if (tot >= K) return;
	if (ll <= l && r <= rr) {
		tot += a[y].p - a[x].p;
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) query(u + u, l, mid, ll, rr, a[x].l, a[y].l);
	if (mid < rr) query(u + u + 1, mid + 1, r, ll, rr, a[x].r, a[y].r);
}

#define FI(n) FastIO::read(n)
#define FO(n) FastIO::writeln(n)

namespace FastIO {
	const int MX = 4096;
	char buf[MX], t[50];
	int bi = MX, bn = MX;
	
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, MX, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, MX, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	
	bool read(int& x) {
		if (!read(t)) return 0;
		x = atoi(t);
		return 1;
	}
	
	void writeln(int x) {
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		int k = 0;
		do {
			t[k++] = x % 10 + '0';
			x /= 10;
		}
		while (x);
		reverse(t, t + k);
		t[k] = 0;
		puts(t);
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int ncase; FI(ncase);
	while (ncase--) {
		int prv = 0;
		int n, m; FI(n), FI(m);
		for (int i = 1; i <= n; i++) FI(b[i]), id[i] = i;
		sort(id + 1, id + n + 1, [](int i, int j) { return b[i] < b[j]; });
		sort(b + 1, b + n + 1);
		nodes = 0;
		for (int i = 1; i <= n; i++) root[i] = modify(1, 1, n, id[i], root[i - 1]);
		for (int i = 1; i <= m; i++) {
			int L, R, p; FI(L), FI(R), FI(p), FI(K);
			L ^= prv, R ^= prv, p ^= prv, K ^= prv;
			int st = -1, en = 1e8;
			while (en - st > 1) {
				int mid = st + en >> 1;
				int l = lower_bound(b + 1, b + n + 1, p - mid) - b;
				int r = upper_bound(b + 1, b + n + 1, p + mid) - b - 1;
				tot = 0;
				query(1, 1, n, L, R, root[l - 1], root[r]);
				if (tot >= K) en = mid;
				else st = mid;
			}
			prv = en;
			FO(en);
		}
	}
	return 0;
}
