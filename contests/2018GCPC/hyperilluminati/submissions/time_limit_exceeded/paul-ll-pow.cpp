#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x; cin >> x;

	for (int dim = 3; dim <= 60; dim++) {
		long long vol = 0;
		for (int n = 1; vol < x; n++) {
			vol += pow(n,dim-1);
			if (vol == x) {
				cout << dim << " " << n << endl;
				return 0;
			}
		}
	}
	cout << "impossible" << endl;
}
