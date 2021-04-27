#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n, m, s, flag;
const int kN = 1e6 + 10, INF = 1e9 + 7;
int vis[kN];
vector<int> g[kN];
vector<int> gg[2];

int match[kN], dist[kN];

bool bfs() {
	queue<int> q;
	for(auto i : gg[flag]) if(i >= n) break; else {
		if (!match[i + 1]) dist[i + 1] = 0, q.push(i + 1);
		else dist[i + 1] = INF;
	}
	dist[0] = INF;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == 0) continue;
		for (auto v : g[u]) {
			if (dist[match[v]] == INF) {
				dist[match[v]] = dist[u] + 1;
				q.push(match[v]);
			}
		}
	}
	return dist[0] != INF;
}
bool dfs(int u) {
	if(!u) return true;
	for (auto v : g[u]) {
		if(dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[u] = v, match[v] = u;
			return true;
		}
	}
	dist[u] = INF;
	return false;
}
int hopcroftKarp() {
	int ret = 0;
	while(bfs()) for(auto i : gg[flag]) if(i >= n) break; else if(!match[i + 1] and dfs(i + 1)) ++ret;
	return ret;
}

int pd(int i) {
	int ans = 0;
	while(i) {
		ans += i % 10;
		i /= 10;
	}
	return ans & 1;
}

void run() {
	cin >> m >> n >> s;
	for(int i = 0; i <= pow(10, m); i++) vis[i] = match[i] = 0, g[i].clear();
	int tmp, tmp2;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		vis[tmp] = 1;
	}
	n = pow(10, m);
	flag = pd(s);
	for(auto i : gg[flag]) if(i >= n) break; else if(!vis[i]) {
		for(int j = 1; j < n; j *= 10) {
			tmp = i;
			int tmp2 = tmp / j % 10;
			tmp -= tmp2 * j;
			if(!vis[tmp + (tmp2 + 1) % 10 * j]) g[i + 1].push_back(tmp + (tmp2 + 1) % 10 * j + 1);
			if(!vis[tmp + (tmp2 + 9) % 10 * j]) g[i + 1].push_back(tmp + (tmp2 + 9) % 10 * j + 1);
		}
	}
	tmp = hopcroftKarp();
	if(!match[s + 1]) {
		cout << "Bob\n";
		return;
	}
	g[s + 1].clear();
	for(int i = 0; i <= pow(10, m); i++) vis[i] = match[i] = 0;
	tmp2 = hopcroftKarp();
	if(tmp == tmp2) cout << "Bob\n";
	else cout << "Alice\n";
	
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	for(int i = 0; i <= 100000; i++) {
		gg[pd(i)].push_back(i);
	}
	int T; cin >> T; while (T--)
	run();
	return 0;
}

