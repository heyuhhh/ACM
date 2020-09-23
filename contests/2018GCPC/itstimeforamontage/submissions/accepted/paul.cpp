#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	int diff = max(0,b[0]-a[0]);
	for (int &x: a) x += diff;

	cout << diff + (a < b) << endl;
}
