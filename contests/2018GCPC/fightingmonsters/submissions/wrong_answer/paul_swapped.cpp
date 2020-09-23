#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int> v(n);
	for (int &x: v) cin >> x;

	for (int a = 1, b = 1; b < 1e7; a += b, swap(a,b)) {
		for (int i = 0; i < n; i++) if (v[i] == b) {
			for (int j = 0; j < n; j++) if (j != i && v[j] == a) {
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
			break;
		}
	}
	cout << "impossible" << endl;
}
