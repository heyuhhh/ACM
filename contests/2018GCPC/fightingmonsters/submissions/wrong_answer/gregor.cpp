#include <bits/stdc++.h>
using namespace std;

pair<int,int> m[100000];

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i].first, m[i].second = i;
	sort(m,m+n);
	int a = 1, b = 1, c = 1;
	while (c < n){
		if (m[c].first == b && m[c-1].first == a) {
			cout << m[c-1].second+1 << " " << m[c].second+1 << endl;
			return 0;
		}
		a += b; swap(a,b);
		while (c < n && m[c].first < b) c++;
	}
	cout << "impossible" << endl;
}
