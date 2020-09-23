#include <bits/stdc++.h>
using namespace std;

bool dp[100][10000];

int main() {
	int n, D; cin >> n >> D;
	int L = D + (n+1)*5;

	dp[0][10] = 1;
	for (int t = 0; t < n; t++) {
		int d; cin >> d;
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j+d <= L; j++) {
				if (dp[i][j]) dp[i+1][j+d] = 1;
			}
		}
	}
	
	double res = -1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= L; j++) {
			if (!dp[i][j]) continue;
			if (j < D || j > D+(i+1)*5) continue;
			res = max(res,double(j-D)/(i+1));
		}
	}
	if (res >= 0) cout << fixed << setprecision(10) << res << endl;
	else cout << "impossible" << endl;
}
