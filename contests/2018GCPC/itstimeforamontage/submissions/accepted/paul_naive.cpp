#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	int res = 0;
	while (a < b) {
		for (int &x: a) x++;
		res++;
	}
	cout << res << endl;
}
