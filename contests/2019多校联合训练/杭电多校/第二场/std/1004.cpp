#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define mp make_pair
#define pb push_back
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;
typedef pair<pair<int, ll>, pair<int, ll> > ptt;

const int N = 1e5 + 2;

int n, q, a[N], lg[N << 2];
vector<pii> Q[N];
vector<pair<pii, ll> > ans;
vector<ll> line[N];

struct Gra {
	static const int N = ::N << 2;
	int L, hd[N], ne[N], fr[N], to[N]; ll val[N];
	inline void init(int n) { L = 0; rep(i, 1, n + 1) hd[i] = -1; }
	inline void _add(int u, int v, ll w) { fr[L] = u; to[L] = v; val[L] = w; ne[L] = hd[u]; hd[u] = L++; }
	inline void add(int u, int v, ll w) { _add(u, v, w); _add(v, u, w); }
	inline void read() { init(n); rep(i, 1, n) { int u, v, w; cin >> u >> v >> w; add(u, v, w << 1); } }
};

struct LCARMQ {
	vector<vi> a; vi lft, dep; int L; vector<ll> dis;
	inline int rmin(int x, int y) { return dep[x] < dep[y] ? x : y; }
	inline void add(int x) { a[0][L++] = x; }
	void dfs(int c, int fa, const Gra &g) {
		lft[c] = L; add(c);
		for(int i = g.hd[c]; ~i; i = g.ne[i]) if(g.to[i] != fa) {
			int t = g.to[i];
			dep[t] = dep[c] + 1;
			dis[t] = dis[c] + g.val[i];
			dfs(t, c, g); add(c);
		}
	}
	inline void build(const Gra &g) {
		int t = g.L + 10; a = vector<vi>(lg[t] + 2); rep(i, 0, sz(a)) a[i] = vi(t);
		lft = dep = vi(t); dis = vector<ll>(t);
		L = 0; dfs(1, 0, g); dep[0] = -1;
		rep(i,1,sz(a)){
			int lim = L+1-(1<<i);
			rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
		}
	}
	inline int lca(const int &_x,const int &_y){
		int x = lft[_x] , y = lft[_y];
		if(x > y) swap(x , y);
		int i = lg[y-x+1];
		return rmin(a[i][x] , a[i][y+1-(1<<i)]);
	}
	inline ll Dis(const int &x, const int &y) { return dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
}R1, R2;

namespace T1 {
	const int N = ::N << 1;
	Gra G, g; int L, n, sz[N]; bool vis[N << 1], col[::N]; ll val[::N];
	vi vec, tim; int F(int x) { return lower_bound(all(tim), x) - tim.begin() + 1; }
#define ls rt << 1
#define rs ls | 1
	vector<pair<int, ll> > nd[N << 1];
	int st, ed; ll now, sval, eval;
	void init(int n) {
		rep(i, 0, n << 2 | 1) nd[i].clear();
	}
	void upd(int L, int R, int p, ll c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			nd[rt].pb(mp(p, c));
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) upd(L, R, p, c, l, mid, ls);
		if(R > mid) upd(L, R, p, c, mid + 1, r, rs);
	}
	void dfs(int l, int r, int rt, vector<pair<int, ptt> > &res) {
		int ps = st, pe = ed; ll pn = now, psv = sval, pev = eval;
		for(auto u : nd[rt]) {
			if(now == -1) {
				st = ed = u.fi;
				sval = eval = u.se;
				now = u.se << 1;
				continue;
			}
			ll ds = R2.Dis(u.fi, st) + sval + u.se, de = R2.Dis(u.fi, ed) + eval + u.se;
			if(ds >= de && ds > now) ed = u.fi, eval = u.se, now = ds;
			else if(de >= ds && de > now) st = u.fi, sval = u.se, now = de;
		}
		if(l < r) {
			int mid = l + r >> 1;
			dfs(l, mid, ls, res);
			dfs(mid + 1, r, rs, res);
		} else {
			res.pb(mp(tim[l - 1], mp(mp(st, sval), mp(ed, eval))));
		}
		st = ps, ed = pe, now = pn, sval = psv, eval = pev;
	}
	void dfssz(int u, int fa, int Sz, int &rt) {
		sz[u] = 1;
		for(int i = g.hd[u]; ~i; i = g.ne[i]) if(!vis[i] && g.to[i] != fa) {
			int v = g.to[i];
			dfssz(v, u, Sz, rt);
			sz[u] += sz[v];
			if(rt == -1 || max(sz[g.to[rt]], Sz - sz[g.to[rt]]) > max(sz[v], Sz - sz[v])) rt = i;
		}
	}
	void dfs2(int u, int fa) {
		if(u <= L) vec.pb(u);
		for(int i = g.hd[u]; ~i; i = g.ne[i]) if(!vis[i] && g.to[i] != fa) dfs2(g.to[i], u);
	}
	// seg divide
	vector<pair<int, ptt> > gao(bool Col, int U, int W) {
		for(auto u : vec) val[u] = R1.Dis(u, U) + W;//, dd(u), de(val[u]);
		tim.clear(); for(auto u : vec) for(auto q : Q[u]) tim.pb(q.fi);
		sort(all(tim)); tim.erase(unique(all(tim)), tim.end());
		init(sz(tim));
		for(auto u : vec) {
			rep(i, 0, sz(Q[u])) {
				int st = F(Q[u][i].fi), ed = (i == sz(Q[u]) - 1 ? sz(tim) : F(Q[u][i + 1].fi) - 1);
				upd(st, ed, u, val[u] + Q[u][i].se, 1, sz(tim), 1);
			}
		}
		st = ed = 0; now = -1;
		vector<pair<int, ptt> > res;
		dfs(1, sz(tim), 1, res);
		return res;
	}
	void init() {
		fill_n(vis, n << 1, 0);
	}
	void dfs(int u) {
		int I = 0; dfssz(u, 0, 0, I);
		if(sz[u] == 1) return ;
		int tot = sz[u];
		dfssz(u, 0, sz[u], I = -1);
		vis[I] = vis[I ^ 1] = 1;

		vec.clear(); dfs2(g.fr[I], 0);
		if(0 < sz(vec) && sz(vec) < tot) {
			vector<pair<int, ptt> > vec1 = gao(0, g.fr[I], g.val[I] >> 1);
			vec.clear(); dfs2(g.to[I], 0);
			if(0 < sz(vec) && sz(vec) < tot) {
				vector<pair<int, ptt> > vec2 = gao(1, g.to[I], g.val[I] >> 1);
				tim.clear(); for(auto t : vec1) tim.pb(t.fi); for(auto t : vec2) tim.pb(t.fi);
				sort(all(tim)); tim.erase(unique(all(tim)), tim.end());
				int p1 = 0, p2 = 0;
				rep(i, 0, sz(tim)) {
					int t = tim[i], tr = (i == sz(tim) - 1 ? q : tim[i + 1] - 1);
					while(p1 + 1 < sz(vec1) && vec1[p1 + 1].fi <= t) ++p1;
					while(p2 + 1 < sz(vec2) && vec2[p2 + 1].fi <= t) ++p2;
					ll res = 0;
					res = max(res, R2.Dis(vec1[p1].se.fi.fi, vec2[p2].se.fi.fi) + vec1[p1].se.fi.se + vec2[p2].se.fi.se);
					res = max(res, R2.Dis(vec1[p1].se.fi.fi, vec2[p2].se.se.fi) + vec1[p1].se.fi.se + vec2[p2].se.se.se);
					res = max(res, R2.Dis(vec1[p1].se.se.fi, vec2[p2].se.fi.fi) + vec1[p1].se.se.se + vec2[p2].se.fi.se);
					res = max(res, R2.Dis(vec1[p1].se.se.fi, vec2[p2].se.se.fi) + vec1[p1].se.se.se + vec2[p2].se.se.se);
					ans.pb(mp(mp(t, tr), res));
				}
			}
		}
		dfs(g.fr[I]), dfs(g.to[I]);
	}
	void rebuild(int u, int fa, const Gra &G) {
		if(u == 1) L = n = ::n, g.init(n << 1);
		bool F = 0; int pre = u;
		for(int i = G.hd[u]; ~i; i = G.ne[i]) if(G.to[i] != fa) {
			if(F) {
				if(~G.ne[i]) {
					g.add(pre, ++n, 0);
					g.add(n, G.to[i], G.val[i]);
					pre = n;
				} else { g.add(pre, G.to[i], G.val[i]); }
			} else { g.add(u, G.to[i], G.val[i]); F = 1; }
			rebuild(G.to[i], u, G);
		}
	}
}

namespace T2 {
	Gra g;
}

void solve() {
	ans.clear();
	// read
	rep(i, 1, n + 1) cin >> a[i], a[i] <<= 1;
	T1::G.read(); T2::g.read();
	rep(i, 1, n + 1) Q[i].clear();
	rep(i, 1, q + 1) {
		int u, w; cin >> u >> w; w <<= 1;
		if(i > 1 && !sz(Q[u])) Q[u].pb(mp(1, a[u]));
		Q[u].pb(mp(i, w));
	}
	rep(i, 1, n + 1) if(!sz(Q[i])) Q[i].pb(mp(1, a[i]));
	// LCARMQ
	R2.build(T2::g);
	// 
	T1::rebuild(1, 0, T1::G);
	T1::init();
	R1.build(T1::g); 
	T1::dfs(1);
	// print
	rep(i, 1, q + 1) line[i].clear();
	for(auto u : ans) {
		int l = u.fi.fi, r = u.fi.se;
		line[l].pb(u.se);
		line[r + 1].pb(-u.se);
	}
	multiset<ll> s;
	rep(i, 1, q + 1) {
		for(auto u : line[i]) {
			if(u >= 0) s.insert(u);
			else s.erase(s.find(-u));
		}
		auto t = s.end();
		cout << *(--t) / 2 << endl;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 2, N << 2) lg[i] = lg[i >> 1] + 1;
	while(cin >> n >> q) {
		solve();
	}
	return 0;
}
