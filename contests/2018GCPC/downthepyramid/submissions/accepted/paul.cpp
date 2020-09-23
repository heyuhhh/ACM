#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long lo = 0, hi = 1e9, sum = 0;
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		sum = x-sum;
		if (i&1) lo = max(lo,-sum);
		else hi = min(hi,sum);
	}
	cout << max(0LL,hi-lo+1) << endl;
}
