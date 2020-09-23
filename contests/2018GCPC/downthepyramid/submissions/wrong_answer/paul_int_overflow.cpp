#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int lo = 0, hi = 1e9, sum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sum = x-sum;
		if (i&1) lo = max(lo,-sum);
		else hi = min(hi,sum);
	}
	cout << max(0,hi-lo+1) << endl;
}
