#include <bits/stdc++.h>
using namespace std;

vector <int> a[110000];

int main() {
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int tcase; cin >> tcase;
	assert(tcase <= 100);
	long long sum = 0;
	while (tcase--) {
		int n, k; cin >> n >> k;
		sum += n;
		assert(n <= 100000);
		assert(n % k == 0);
		if (1LL * (1 + n) * n / 2 % k) {
			cout << "no" << endl;
			continue;
		}
		cout << "yes" << endl;
		if ((n / k) & 1) {
			if (k == 1) {
				for (int i = 1; i <= n; i++) a[0].push_back(i);
			} else {
				for (int i = 0; i < k; i++) a[i].push_back(i + 1);
				for (int i = 0; i < k; i++) if (i & 1) a[i].push_back(2 * k - i / 2);
											else a[i].push_back(k + 1 + k / 2 - i / 2);
				for (int i = 0; i < k; i++) a[i].push_back(1LL * 3 * (1 + 3 * k) / 2 - a[i][0] - a[i][1]);
				for (int i = 3 * k + 1; i <= n; i++) a[(i - 1) % k].push_back(i);
				for (int i = 3; i < n / k; i+=2) for (int j = 0; j * 2 < k; j++) swap(a[j][i], a[k - 1 - j][i]);
			}
		} else {
			for (int i = 1; i <= n; i++) a[(i - 1) % k].push_back(i);
			for (int i = 0; i < n / k; i+=2) for (int j = 0; j * 2 < k; j++) swap(a[j][i], a[k - 1 - j][i]);
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < a[i].size(); j++) cout << a[i][j] << (j < a[i].size() - 1 ? ' ' : '\n');
		}
		for (int i = 0; i < k; i++) a[i].clear();
	}
	assert(sum <= 500000);
	return 0;
}

