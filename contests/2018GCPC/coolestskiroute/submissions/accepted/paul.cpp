#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> indeg(n);
	vector<vector<pair<int,int>>> adj(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(b,c);
		indeg[b]++;
	}
	
	queue<int> q;
	for (int i = 0; i < n; i++) if (!indeg[i]) q.push(i);

	vector<int> dp(n);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (auto e: adj[a]) {
			int b, c;
			tie(b,c) = e;
			dp[b] = max(dp[b], dp[a] + c);
			if (!--indeg[b]) q.push(b);
		}
	}
	cout << *max_element(begin(dp),end(dp)) << endl;
}
