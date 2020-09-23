#include <bits/stdc++.h>
using namespace std;

int main() {
	float x; cin >> x;

	for (int dim = 3; dim <= 60; dim++) {
		float vol = 0;
		for (int n = 1; vol < x; n++) {
			float y = 1;
			for (int i = 1; i < dim; i++) y *= n;
			vol += y;
			if (vol == x) {
				cout << dim << " " << n << endl;
				return 0;
			}
		}
	}
	cout << "impossible" << endl;
}
