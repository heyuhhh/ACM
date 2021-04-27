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
vector<int> G[N]; 
int sz[N], deep[N], bson[N], ff[N];
int top[N], dfn[N], T;
void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    sz[u] = 1;
    ff[u] = fa;
    int Max = -1;
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > Max) {
                Max = sz[v];
                bson[u] = v;
            }
        }
    }
}

void dfs(int u, int fa, int topf) {
    dfn[u] = ++T;
    top[u] = topf;
    if (bson[u] != 0) {
        dfs(bson[u], u, topf);
    }
    for (auto v : G[u]) {
        if (v != fa && v != bson[u]) {
            dfs(v, u, v);
        }
    }
} 

namespace lca {
	int f[N][20], deep[N];
	void dfs(int u, int fa) {
	    deep[u] = deep[fa] + 1;
	    f[u][0] = fa;
	    for(int i = 1; i < 20; i++) {
	        f[u][i] = f[f[u][i - 1]][i - 1];
	    }   
	    for(auto v : G[u]) if(v != fa) {
	        dfs(v, u);
	    }
	}
	int LCA(int x, int y) {
	    if(deep[x] < deep[y]) swap(x, y);
	    for(int i = 19; i >= 0; i--) {
	        if(deep[f[x][i]] >= deep[y]) x = f[x][i];
	    }  
	    if(x == y) return x;
	    for(int i = 19; i >= 0; i--) {
	        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];  
	    }
	    return f[x][0];
	}	
};

struct BIT {
	int c[N];
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x, int v) {
		for (; x < N; x += lowbit(x)) {
			c[x] += v;
		}
	}
	int query(int x) {
		int res = 0;
		for (; x; x -= lowbit(x)) {
			res += c[x];
		}
		return res;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}bit;

vector<pii> At[N];
vector<int> ans;

int query(int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (deep[top[u]] < deep[top[v]]) swap(u, v);
		res += bit.query(dfn[top[u]], dfn[u]);
		u = ff[top[u]];
	}
	if (deep[u] < deep[v]) swap(u, v);
	res += bit.query(dfn[v], dfn[u]);
	return res;
}

void dfs2(int u, int fa) {
	for (auto v : G[u]) if (v != fa) {
		dfs2(v, u);
	}
	bool f = false;
	for (auto it : At[u]) {
		int x = it.first, y = it.second;
//		cout << u << ' ' << x << ' ' << y << endl;
		if (!query(x, y)) f = true;
	}
	if (f) {
		ans.emplace_back(u);
		bit.add(dfn[u], 1);
	}
}

void run() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 0);
	dfs(1, 0, 1);	
	lca::dfs(1, 0);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		At[lca::LCA(u, v)].emplace_back(u, v);
	}
	dfs2(1, 0);
	cout << sz(ans) << '\n';
	for (auto it : ans) {
		cout << it << ' ';
	}
	cout << '\n';
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

