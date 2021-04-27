#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;

void run() {
	int n, w, c, h, m;
	cin >> n >> w >> c >> h >> m;
	vector<bool> human(n + 1);
	for (int i = 0; i < h; i++) {
		int x;
		cin >> x;
		human[x] = true;
	}
	vector<int> ending(m);
	for (int i = 0; i < m; i++) {
		cin >> ending[i];
	}
	vector<vector<vector<int>>> G(c + 1, vector<vector<int>>(n + 1));
	for (int i = 0; i < w; i++) {
		int s, c, t;
		cin >> s >> c >> t;
		G[c][t].emplace_back(s);
	}
	queue<pair<int, int>> que;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			que.emplace(ending[i], ending[j]);
		}
	}
	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
	while (!que.empty()) {
		pair<int, int> cur = que.front(); que.pop();
		int x = cur.first, y = cur.second;
		if (vis[x][y]) continue;
		vis[x][y] = vis[y][x] = true;
		if (human[x] != human[y]) {
			cout << "YES" << '\n';
			return;
		}
		for (int C = 1; C <= c; C++) {
			for (auto to1 : G[C][x]) {
				for (auto to2 : G[C][y]) {
					if (vis[to1][to2]) {
						continue;
					}
					if (human[to1] != human[to2]) {
						cout << "YES" << '\n';
						return;
					}
					que.emplace(to1, to2);
				}
			}
		}
	}
	cout << "NO" << '\n';	
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	run();
	return 0;
}
