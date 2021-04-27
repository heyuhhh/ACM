#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

void run() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<int> c(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c[2 * i] = a[i];
		c[2 * i + 1] = b[i];
	}
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	int D = sz(c);
	vector<vector<int>> G(D);
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all(c), a[i]) - c.begin();	
		b[i] = lower_bound(all(c), b[i]) - c.begin();
		G[a[i]].emplace_back(b[i]);
		G[b[i]].emplace_back(a[i]);
	}
	vector<bool> vis(D);
	int ans = 1, cnt;
	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		++cnt;
		for (auto v : G[u]) if (!vis[v]) {
			dfs(v);
		}
	};
	for (int i = 0; i < D; i++) if (!vis[i]) {
		cnt = 0;
		dfs(i);
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int T; cin >> T; while (T--)
	run();
	return 0;
}

