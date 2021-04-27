#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e8 + 7;

void add(int& x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void run() {
	int m, n;
	cin >> m >> n;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1)));
	auto get = [&] (int a, int b) {
		int res = 0;
		for (int i = m - 1; i >= 0; i--) {
			if ((a >> i & 1) == (b >> i & 1)) ++res;
			else break;
		}
		return res;
	};
	// dp[i][j][k]: 考虑了前i个区间，lcp(A_i, l_{i+1})=j,lcp(A_i, r_i)=k时的答案为多少 
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int p = l[i]; p <= r[i]; p++) {
			int LL = get(p, l[i]), RR = (i == 0 ? 0 : get(p, r[i - 1]));
//			cout << i << ' ' << p << ' ' << LL << ' ' << RR << endl;
			for (int j = 0; j <= LL; j++) {
				for (int k = RR; k <= m; k++) if (dp[i][j][k] != 0) {
//					cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << ' ' << p << endl;
//					cout << "trans to:\n";
//					cout << i + 1 << ' ' << (i < n - 1 ? get(p, l[i + 1]) : 0) << ' ' << get(p, r[i]) << endl;
					add(dp[i + 1][i < n - 1 ? get(p, l[i + 1]) : 0][get(p, r[i])], 1ll * dp[i][j][k] * p % MOD);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		add(ans, dp[n][0][i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(20) << fixed;
	int T; cin >> T; while (T--)
	run();
	return 0;
}
