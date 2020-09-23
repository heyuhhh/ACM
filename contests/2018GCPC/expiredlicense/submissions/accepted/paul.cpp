#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
bool pr[N];

int main() {
	fill_n(pr,N,true);
	pr[0] = pr[1] = false;
	for (int i = 2; i*i < N; i++) if (pr[i]) {
		for (int j = i*i; j < N; j += i) pr[j] = false;
	}

	int tc; cin >> tc;
	while (tc--) {
		double a, b; cin >> a >> b;
		int x = round(a*1e5), y = round(b*1e5);
		int g = __gcd(x,y);
		x /= g, y /= g;

		if (x == 1 && y == 1) x = y = 2;
		if (pr[x] && pr[y]) cout << x << " " << y << endl;
		else cout << "impossible" << endl;
	}
}
