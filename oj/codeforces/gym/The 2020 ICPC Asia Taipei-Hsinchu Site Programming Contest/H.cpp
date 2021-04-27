#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n, m;
struct edge{
	int x, y, w;
	bool operator<(edge & f) const {
		return w < f.w;
	}
}e[1000010];
int fa[20010];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int vis[20010], size[20010];
long long ans;
void run() {
	cin >> n >> m;
	assert(m >= n - 1);
	for (int i = 1; i <= m; i++) cin >> e[i].x >> e[i].y >> e[i].w;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int id, sz;
	for (id = m, sz = 0; sz < n - 1; id--) {
		int x = find(e[id].x), y = find(e[id].y);
		if(x != y) {
			sz++;
			fa[y] = x;
		}
	}
	assert(sz == n - 1);
	id++;
	for (int i = 1; i <= n; i++) fa[i] = i;
	if (id > 1 && e[id].w == e[id - 1].w) {
		assert(false);
	}
	for (sz = 0; sz < n - 1; id++) {
		int x = find(e[id].x), y = find(e[id].y);
		if(x != y) {
			sz++;
			fa[y] = x;
			vis[id] = 1;
		}
	}
	assert(sz == n - 1);
	for (int i = 1; i <= n; i++) size[i] = 1, fa[i] = i;
	sz = 0;
	for (int i = m; i; i--) if(vis[i]) {
		int x = find(e[i].x), y = find(e[i].y);
		++sz;
		ans += 1ll * size[x] * size[y] * e[i].w;
		fa[y] = x;
		size[x] += size[y];		
	}
	assert(sz == n - 1);
	cout << ans << endl;

}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
//	int T; cin >> T; while (T--)
	run();
	return 0;
}

