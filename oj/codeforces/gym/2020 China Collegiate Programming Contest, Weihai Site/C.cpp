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

int n;
vector<pii> G[N];
vector<vector<int>> v(3);

__int128 fz, fm;
int siz[N][3];

int r(int t, int i) {
	return sz(v[i]) - siz[t][i];
}

void calc(int w, int t) {
//	cout << w << ' ' << t << endl;
	__int128 res = 1ll * siz[t][0] * r(t, 1) * r(t, 2);
	res += 1ll * siz[t][1] * r(t, 0) * r(t, 2);
	res += 1ll * siz[t][2] * r(t, 0) * r(t, 1);
	res += 1ll * siz[t][0] * siz[t][1] * r(t, 2);
	res += 1ll * siz[t][1] * siz[t][2] * r(t, 0);
	res += 1ll * siz[t][2] * siz[t][0] * r(t, 1);
	fz += res * w;
//	cout << res << endl;
}

void dfs(int u, int fa) {
	for (auto it : G[u]) {
		int v = it.fi, w = it.se;
		if (v == fa) continue;
		dfs(v, u);
		for (int i = 0; i < 3; i++) {
			siz[u][i] += siz[v][i];
		}
		calc(w, v);
	}
}

void prn(__int128 x) {
	if(x==0) cout << '0';
	else {
		vector<int> t;
		while(x>0) {
			t.push_back(x%10);
			x/=10;
		}
		while(!t.empty()) {
			cout << t.back();
			t.pop_back();
		}
	}
	
}

void run() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	fm = 1;
	for (int i = 0; i < 3; i++) {
		int m;
		cin >> m;
		fm *= m;
		v[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			++siz[v[i][j]][i];
		}
	}
	dfs(1, 0);
	prn( fz / fm);
	cout << '.';
	fz = fz % fm;
	for(int i = 1; i < 13; i++) {
		fz *= 10;
		prn( fz / fm);
		fz = fz % fm;
	}
	
//	long double ans = ((long double)fz) / fm;
//	long long nfz, nfm=(long long)(1e7);
//	long long l=,r=(long long)(8e18);
//	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	run();
	return 0;
}

