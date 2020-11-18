#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, m;
int a[N], f[N];

int find(int x) {
	return f[x] == x ? f[x] : f[x] = find(f[x]);	
}

struct node {
	int val, fa, d, T;
	int ch[2];	
} t[N];

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (t[x].val > t[y].val || (t[x].val == t[y].val && t[x].T > t[y].T)) {
		swap(x, y);
	}
	t[x].ch[1] = merge(t[x].ch[1], y);
	if (t[t[x].ch[0]].d < t[t[x].ch[1]].d) {
		swap(t[x].ch[0], t[x].ch[1]);
	}
	t[x].d = t[t[x].ch[1]].d + 1;
	return x;
}

void build() {
	for (int i = 1; i <= n; i++) {
		t[i].val = a[i];
		t[i].T = i;
	}
}

bool del[N];

void run() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	build();
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, y;
			cin >> x >> y;
			if (del[x] || del[y]) continue;
			x = find(x), y = find(y);
			if (x == y) continue;
			f[x] = f[y] = merge(x, y);
		} else {
			int x;
			cin >> x;
			if (del[x]) {
				cout << -1 << '\n';
				continue;
			}
			x = find(x);
			cout << t[x].val << '\n';
			del[t[x].T] = true;
			f[x] = f[t[x].ch[0]] = f[t[x].ch[1]] = merge(t[x].ch[0], t[x].ch[1]);
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

