#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, r;
	cin >> n >> r;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int ans = 0;
	int last = 1;
	while (last <= n ) {
		int pos = -1;
		for (int i = n ; i >= max(1, last - r + 1); --i) {
			if (a[i] == 1 && i  <= last+r-1) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			cout << -1 << "\n";
			return 0;
		}
		++ans;
		last = pos + r ;
	}

	cout << ans << "\n";

	return 0;
}
