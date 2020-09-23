#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int A[1000];
int B[1000];

int main(){
	int n; cin >> n;
	FOR(i,0,n) cin >> A[i];
	FOR(i,0,n) cin >> B[i];

	if (A[0] > B[0]) {
		cout << 0 << endl;
		return 0;
	}

	int i = 0;
	while (i < n && A[i] + (B[0]-A[0]) == B[i]) i++;

	if (i == n) cout << B[0] - A[0]  << endl;
	else if (A[i] + B[0] - A[0] > B[i]) cout << B[0] - A[0] << endl;
	else cout << B[0] - A[0] + 1 << endl;

	return 0;
}
