#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, m;
pii a[N], b[N];
ll dp[N];

void run() {
	for (int i = 1; i <= n; i++) {
		cin >> b[i].fi >> b[i].se;
	}
	m = 0;
	for (int i = 1; i <= n; i++) {
		while (m > 0 && a[m].se <= b[i].se) --m;
		a[++m] = b[i];
	}
	deque<pair<ll, int>> que;
	int Min = 2 * a[1].second;
	for (int i = 1; i <= m; i++) dp[i] = 1e18;
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		while (!que.empty() && que.front().first < (ll)a[i].first) {
			Min = min(Min, que.front().second);
			que.pop_front();
		}
		dp[i] = (ll)a[i].first + Min;
		if (!que.empty()) {
			dp[i] = min(dp[i], (ll)que.front().first + que.front().second);
		}
		if (i < m) {
			while (!que.empty() && dp[i] + 2 * a[i + 1].second < (ll)que.back().first + que.back().second) {
				que.pop_back();
			}
			que.emplace_back(dp[i], 2 * a[i + 1].second);
		}
	}
	cout << dp[m] << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	while (cin >> n) run();
	return 0;
}

