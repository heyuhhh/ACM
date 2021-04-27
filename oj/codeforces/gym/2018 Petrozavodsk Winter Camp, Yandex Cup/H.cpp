#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

void run() {
	int k, n, m;
	cin >> k >> n >> m;
	vector<int> t(k);
	for (int i = 0; i < k; i++) {
		cin >> t[i];
	}
	if (n < k) {
		cout << -1 << '\n';
		return;
	}
	vector<int> a(n);
	int down = 1;
	bool flag = true;
	int j = 0;
	for (int i = 0; i < k; i++) {
		if (t[i] != -1 && t[i] < down) {
			flag = false;
			break;
		}
		down = max(down, t[i]);
		int up = m;
		while (k - i < n - j && up > down) {
			a[j++] = up--;
		}
		a[j++] = down;
	}
	if (j != n) flag = false;
	if (!flag) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
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

