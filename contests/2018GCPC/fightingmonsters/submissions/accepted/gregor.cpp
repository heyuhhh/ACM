#include <bits/stdc++.h>
using namespace std;

pair<int,int> m[100000];

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i].first, m[i].second = i;
	sort(m,m+n);
	int a = 1, b = 1, c = 1, d = 0;
	while (c < n){
		if (m[c].first == b && m[d].first == a) {
			cout << m[d].second+1 << " " << m[c].second+1 << endl;
			return 0;
		}
		a += b; swap(a,b);
		while (c < n && m[c].first < b) c++;
		while (d < n && m[d].first < a) d++;
	}
	cout << "impossible" << endl;
}
