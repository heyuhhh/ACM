#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5, MOD = 65536;

int n, q;

int minv[N << 2], maxv[N << 2], sumv[N << 2], lazy[N << 2];
int a[N], b[N];

inline int add(int x, int y) {
	return x + y >= MOD ? x + y - MOD : x + y;
}

void pushup(int o) {
	minv[o] = min(minv[o << 1], minv[o << 1|1]);
	maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
	sumv[o] = (sumv[o << 1] + sumv[o << 1|1]) % MOD;
}

void tag(int o, int l, int r, int v) {
	lazy[o] = add(lazy[o], v);
	minv[o] = add(minv[o], v);
	maxv[o] = add(maxv[o], v);	
	sumv[o] = add(sumv[o], 1ll * (r - l + 1) * v % MOD);
}

void pushdown(int o, int l, int r) {
	if (lazy[o] != 0) {
		int mid = (l + r) >> 1;
		tag(o << 1, l, mid, lazy[o]);
		tag(o << 1|1, mid + 1, r, lazy[o]);
		lazy[o] = 0;
	}
}

void build(int o, int l, int r) {
	if (l == r) {
		minv[o] = maxv[o] = sumv[o] = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1|1, mid + 1, r);
	pushup(o);
}

void update(int o, int l, int r, int p, int v) {
	if (l == r) {
		if (v < 0) v += MOD;
		tag(o, l, r, v);
		return;
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	if (p <= mid) update(o << 1, l, mid, p, v);
	else update(o << 1|1, mid + 1, r, p, v);
	pushup(o);
}

int queryS(int o, int l, int r, int L, int R) {
	if (l >= L && r <= R) {
		return sumv[o];
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	int res = 0;
	if (L <= mid) res = add(res, queryS(o << 1, l, mid, L, R));
	if (R > mid) res = add(res, queryS(o << 1|1, mid + 1, r, L, R));
	return res;
}

inline pii get(pii A, pii B) {
	pii res;
	res.first = min(A.first, B.first);
	res.second = min(A.second, B.second);
	return res;
}
pii query(int o, int l, int r, int L, int R) {
	if (l >= L && r <= R) {
		return make_pair(minv[o], maxv[o]);
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	pii res(INF, -INF);
	if (L <= mid) res = query(o << 1, l, mid, L, R);
	if (R > mid) res = get(res, query(o << 1|1, mid + 1, r, L, R));
	return res;
}

void run() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = (a[i] - a[i - 1] + MOD) % MOD;
	}
	build(1, 1, n);
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			update(1, 1, n, l, 1);
			update(1, 1, n, min(n, r + 1), -1);
		} else {
			int x, y, L;
			cin >> x >> y >> L;
			if (x == y) {
				cout << "yes" << '\n';
				continue;
			}
			if (queryS(1, 1, n, 1, x) == queryS(1, 1, n, 1, y)) {
				int val = queryS(1, 1, n, x + 1, x + 1);
				pii now = query(1, 1, n, y + 1, y + L - 1);
				if (now.first != val || now.second != val) {
					cout << "no" << '\n';
				} else {
					cout << "yes" << '\n';
				}
			} else {
				cout << "no" << '\n';
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	run();
	return 0;
}

