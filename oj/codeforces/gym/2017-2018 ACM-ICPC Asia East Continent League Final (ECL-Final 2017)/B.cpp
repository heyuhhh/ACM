#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
int _;

struct node {
	int id, val, t;
	double d;
	bool operator < (const node& A) const {
		return d < A.d;
	}
};

long double calc(int val, int t) {
	return 1.0 * val / t - 1.0 * val / (t + 1);
}

void run() {
	++_;
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		a[i] *= a[i];
	}
	long double ans = -1.0 * s * s / m;
	priority_queue<node> que;
	for (int i = 0; i < n; i++) {
		que.emplace(node{i, a[i], 1, calc(a[i], 1)});
	}
	int tmp = m - n;
	vector<int> op(n, 1);
	while (tmp--) {
		node cur = que.top(); que.pop();
		++op[cur.id];
		que.emplace(node{cur.id, cur.val, cur.t + 1, calc(cur.val, cur.t + 1)});
	}
	for (int i = 0; i < n; i++) {
		ans += (long double)a[i] / op[i];
	}
	cout << "Case #" << _ << ": ";
	cout << ans / m << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int T; cin >> T; while (T--)
	run();
	return 0;
}

