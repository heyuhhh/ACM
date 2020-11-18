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
int a[N];

struct node {
	int val, d;
	int ch[2];
} t[N];

int f[N];
int find(int x) {
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void init() {
	for (int i = 1; i <= n; i++) {
		t[i].val = a[i];
		t[i].d = 0;
		t[i].ch[0] = t[i].ch[1] = 0;
	}
	for (int i = 0; i <= n; i++) {
		f[i] = i;
	}
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (t[x].val < t[y].val) swap(x, y);
	t[x].ch[1] = merge(t[x].ch[1], y);
	if (t[t[x].ch[1]].d > t[t[x].ch[0]].d) {
		swap(t[x].ch[1], t[x].ch[0]);
	}
	t[x].d = t[t[x].ch[1]].d + 1;
	return x;
}

void weaken(int x) {
	t[x].val >>= 1;
	int rt;
	rt = f[x] = f[t[x].ch[0]] = f[t[x].ch[1]] = merge(t[x].ch[0], t[x].ch[1]);	
	t[x].ch[0] = t[x].ch[1] = 0;
	f[x] = f[rt] = merge(rt, x);
}

void run() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init();
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x = find(x), y = find(y);
		if (x == y) {
			cout << -1 << '\n';
			continue;
		}
		weaken(x), x = find(x);
		weaken(y), y = find(y);
		int rt;
		rt = f[x] = f[y] = merge(x, y);
		cout << t[rt].val << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	while (cin >> n) run();
	return 0;
}

