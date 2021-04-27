#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 55, M = 1005;
void chkmax(int& x, int y) {
	if (x == INF) x = y;
	else if (x < y) x = y;
}
void chkmin(int& x, int y) {
	if (x == INF) x = y;
	else if (x > y) x = y;
}

int n, S, m;
int p[N];
int ps, pu;
int pa[2][N];

int dp[N][N][M];

int dfs(int p1, int p2, int s) {
	if (p1 + p2 == m) {
		return 0;
	}
	if (dp[p1][p2][s] != INF) {
		return dp[p1][p2][s];
	}
	
	int& res = dp[p1][p2][s];
	int now = p[p1 + p2 + 1];
	
	if (p1 < 2 * n * S) {
		int val = dfs(p1 + 1, p2, s);	
		if (val != INF) {
			if (now > n) {
				chkmin(res, val - pa[0][p1 + 1]);
			} else {
				chkmax(res, val + pa[0][p1 + 1]);
			}	
		}
	}
	
	if (p2 < 2 * n) {
		if ((s >> (now - 1) & 1) == 0) {
			int val = dfs(p1, p2 + 1, s ^ (1 << (now - 1)));
			if (val != INF) {
				if (now > n) {
					chkmin(res, val - pa[1][p2 + 1]);
				} else {
					chkmax(res, val + pa[1][p2 + 1]);
				}				
			}
		}			
	}
	
	return res;
}

void run() {
	cin >> n >> S;
	m = 2 * n * (S + 1);
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}
	cin >> ps;
	for (int i = 1; i <= ps; i++) {
		cin >> pa[0][i];
	}
	sort(pa[0] + 1, pa[0] + ps + 1, greater<int>());
	cin >> pu;
	for (int i = 1; i <= pu; i++) {
		cin >> pa[1][i];
	}
	sort(pa[1] + 1, pa[1] + pu + 1, greater<int>());
	memset(dp, INF, sizeof(dp));
	int ans = dfs(0, 0, 0);
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	run();
	return 0;
}

