#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int M = N * 31;

int n, q;
pii a[N];
int b[N];

int rt[N];
int ls[M], rs[M], siz[M];
ll sum[M];
int tot;

void build(int& o, int l, int r) {
	o = ++tot;
	sum[o] = siz[o] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls[o], l, mid);
	build(rs[o], mid + 1, r);
}

void insert(int& o, int last, int l, int r, int p, int val) {
	o = ++tot;
	ls[o] = ls[last], rs[o] = rs[last];
	sum[o] = sum[last] + val;
	siz[o] = siz[last] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) insert(ls[o], ls[last], l, mid, p, val);
	else insert(rs[o], rs[last], mid + 1, r, p, val);
}

ll query(int o, int last, int l, int r, int k) {
//	cout << last << ' ' << o << endl;
//	cout << l << ' ' << r << ' ' << k << ' ' << siz[o] - siz[last] << endl;
	if (siz[o] - siz[last] == k) {
		return sum[o] - sum[last];
	}
	int mid = (l + r) >> 1;
	
	int tmp = siz[rs[o]] - siz[rs[last]];
	if (tmp >= k) {
		return query(rs[o], rs[last], mid + 1, r, k);
	}
	return sum[rs[o]] - sum[rs[last]] + query(ls[o], ls[last], l, mid, k - tmp);
}

ll pre[N];
void init() {
	for (int i = 1; i < N; i++) {
		pre[i] = pre[i - 1] + 1ll * i * i;
	}
}

void run() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[a[i].se] = i;
	}
	for (int i = 0; i <= n; i++) {
		rt[i] = 0;
	}
	tot = 0;
	build(rt[0], 1, n);
	
	for (int i = 1; i <= n; i++) {
		insert(rt[i], rt[i - 1], 1, n, b[i], a[b[i]].fi);	
	}
	cin >> q;
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		ll ans = pre[r - l + 1] + query(rt[r], rt[l - 1], 1, n, k);
		cout << ans << '\n';
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
	int T; cin >> T; while (T--)
	run();
	return 0;
}

