#include<bits/stdc++.h>
using namespace std;

#define FORN(i,n) for (int i = 0; i < (n); i++)

const int N = 1010;
int a[N][N];

int main() {
	int m, n; cin >> m >> n;
	FORN(i,m+2) FORN(j,n+2) cin >> a[i][j];

	bool ok = true;
	vector<string> res(m,string(n,'.'));
	FORN(i,m) FORN(j,n) {
		if (!a[i][j]) continue;
		res[i][j] = 'X';
		FORN(di,3) FORN(dj,3) a[i+di][j+dj]--;		
	}

	FORN(i,m+2) FORN(j,n+2) if (a[i][j]) ok = false;

	if (ok) FORN(i,m) cout << res[i] << endl;
	else cout << "impossible" << endl;
}

