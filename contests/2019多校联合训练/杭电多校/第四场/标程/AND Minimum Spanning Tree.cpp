#include <bits/stdc++.h>
using namespace std;

int f[220000];

int main() {
	ios_base::sync_with_stdio(false);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		memset(f, 0, sizeof(int) * (n + 1));
		int ans = 0;
		for (int r = 1; r <= n; r *= 2) {
			for (int i = r - 1; i <= n; i += 2 * r) if (i > 1 && !f[i]) f[i] = r;
		}
		if (!f[n]) f[n] = 1, ans++;
		cout << ans << endl;
		for (int i = 2; i <= n; i++) cout << f[i] << " \n"[i == n];
	}
	return 0;
}

