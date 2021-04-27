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
const int MO = 1e9 + 9, base = 9121;

int a[N], d[N];
int n, T;
int E;
int hs[N];

int npow[N], pre[N];

void init() {
	npow[0] = 1;
	pre[0] = 1;
	for (int i = 1; i < N; i++) {
		npow[i] = 1ll * npow[i - 1] * base % MO;
		pre[i] = (pre[i - 1] + npow[i]) % MO;
	}
}

void rebuild() {
	for (int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
		a[i] += d[i];
		if (a[i] >= MOD) a[i] -= MOD;
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		hs[i] = (1ll * hs[i - 1] * base % MO + a[i]) % MO;
	}
}

struct cz {
	int l, r;
} q[N];
int tot, last;

int calc(int x) {
	int res = hs[x];
	for (int i = last + 1; i <= tot; i++) {
		int l = q[i].l, r = q[i].r; ++r;
		if (l <= x) {
			res = (res + pre[x - l]) % MO;
		}
		if (r <= x) {
			res = (res - pre[x - r] + MO) % MO;	
		}
	}
	return res;
}

int calc(int l, int r) {
	return (calc(r) - 1ll * calc(l - 1) * npow[r - l + 1] % MO + MO) % MO;
}

void run() {
	cin >> n >> T;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	E = sqrt(T + 0.5);
	rebuild();
	int cnt = 0;
	while (T--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			q[++tot] = cz{l, r};
			++d[l], --d[r + 1];
			if (++cnt == E) {
				cnt = 0;
				rebuild();
				last = tot;
			}
		} else {
			int x, y, L;
			cin >> x >> y >> L;
			if (calc(x, x + L - 1) == calc(y, y + L - 1)) {
				cout << "yes" << '\n';
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
	init();
	run();
	return 0;
}

