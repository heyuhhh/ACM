#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<pair<int,int>> adj[N];
int dp[N];

int dfs(int i) {
	int &res = dp[i];
	if (res != -1) return res;
	res = 0;
	for (auto e: adj[i]) {
		res = max(res, e.second + dfs(e.first));
	}
	return res;
}

int main() {
	int n, m; cin >> n >> m;
	
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);
	}

	memset(dp,-1,sizeof dp);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dfs(i));
	}
	cout << res << endl;
}
