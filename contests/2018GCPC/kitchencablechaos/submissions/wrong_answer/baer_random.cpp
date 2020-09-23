#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
double best = -1;
int n, D; 

void doit(ll s) {
	int sum = 0;
	int count = 0;
	for (int y = 0; y < n; y++) {
		if (s & (1ll<<y)) {
			sum += v[y];
			count++;
		}
	}
	
	if (sum >= D - 10 && sum - 5 * (count - 1) <= D) {
		best = max(best, double(sum - D + 10) / (count + 1));
		/*if (best >= 4.9999) {
			cerr << s << endl;
			cerr << "sum is " << sum << " count is " << count << endl;
		}*/
	}
}

int main() {
	cin >> n >> D;

	v = vector<int>(n);
	for (int t = 0; t < n; t++) cin >> v[t];
	
	// check 0 wires
	doit(0);
	// check all wires
	doit((1ll<<n) - 1);
	// check exactly one wire
	for (int y = 0; y < n; y++) doit(1ll<<y);
	// check exactly one missing
	for (int y = 0; y < n; y++) doit(((1ll<<n)-1) ^ (1ll<<y));
	
	for (int x = 0; x < 8000000; x++) {
		ll s = rand() % (1ll<<n);
		doit(s);
	}
	if (best > -1) {
		printf("%.8f\n", best);
	} else {
		printf("impossible\n");
	}
}
