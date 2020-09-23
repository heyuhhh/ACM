#include <bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int n) {
	vector<int> res;
	for (int p = 2; p*p <= n; p++) if (n%p == 0) {
		res.push_back(p);
		while (n%p == 0) n /= p;
	}
	if (n > 1) res.push_back(n);
	return res;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		double a, b; cin >> a >> b;
		int x = round(a*1e5), y = round(b*1e5);
		
		if (x == y) {
			cout << "2 2" << endl;
			continue;
		}

		vector<int> ps = prime_factors(x), qs = prime_factors(y);
		bool ok = false;
		for (int p: ps) for (int q: qs) if (x/p == y/q) {
			cout << p << " " << q << endl;
			ok = true;
		}
		if (!ok) cout << "impossible" << endl;
	}
}
