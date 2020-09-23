#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	int n; cin >> n;
	int lo = 0, hi; cin >> hi;

	FOR(i,1,n){
		int v; cin >> v;
		int nlo = max(0,v - hi);
		int nhi = v - lo;
		lo = nlo;
		hi = nhi;
	}

	cout << max(0,hi-lo+1) << endl;
}
