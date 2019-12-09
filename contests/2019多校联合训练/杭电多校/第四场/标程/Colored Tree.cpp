#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e5 + 5;
const int M = 600;
const int L = 20;

vector<int> con[MX];
int vis[MX], col[MX], sz[MX], dp[MX], prv[MX], buf[MX];
int fst[MX], pos[MX], pn, st[MX], en[MX], id[MX];
int cnt[MX / M + 5][MX], Count[MX], Add[MX];
int anc[MX][L];

vector<int> qry[MX];
int last[MX];

set<int> S[MX];

void dfs(int u) {
	vis[u] = true;
	sz[u] = 1;
	for (int i = con[u].size() - 1; i >= 0; i--) if (!vis[con[u][i]]) {
		dp[con[u][i]] = dp[u] + 1;
		dfs(con[u][i]);
		sz[u] += sz[con[u][i]];
		prv[con[u][i]] = u;
	}
}

void hld(int u, int hd) {
	fst[u] = hd;
	pos[u] = st[u] = ++pn;
	id[pn] = u;
	int v = -1;
	for (int i = con[u].size() - 1; i >= 0; i--) {
		if (con[u][i] != prv[u] && sz[v] < sz[con[u][i]]) v = con[u][i];
	}
	if (v != -1) hld(v, hd);
	for (int i = con[u].size() - 1; i >= 0; i--) {
		if (con[u][i] != prv[u] && con[u][i] != v) hld(con[u][i], con[u][i]);
	}
	en[u] = pn;
}

void update(int u, int v, int val, int tar) {
	if (u == tar) u++;
	if (v < u) return;
	u--, v--;
	int grp_st = u / M, grp_en = v / M;
	for (int i = grp_st + 1; i < grp_en; i++) Add[i] += val;
	u++, v++;
	if (grp_st == grp_en) {
		for (int i = u; i <= v; i++) {
			cnt[grp_st][Count[i]]--;
			Count[i] += val;
			cnt[grp_st][Count[i]]++;
		}
	} else {
		for (int i = u; i <= (grp_st + 1) * M; i++) {
			cnt[grp_st][Count[i]]--;
			Count[i] += val;
			cnt[grp_st][Count[i]]++;
		}
		for (int i = grp_en * M + 1; i <= v; i++) {
			cnt[grp_en][Count[i]]--;
			Count[i] += val;
			cnt[grp_en][Count[i]]++;
		}
	}
}

void go(int u, int v, int val) {
	int fu, fv, tar = v;
	while (true) {
		fu = fst[u], fv = fst[v];
		if (fu == fv) break;
		if (dp[fu] > dp[fv]) {
			swap(u, v);
			swap(fu, fv);
		}
		update(pos[fv], pos[v], val, pos[tar]);
		v = prv[fv];
	}
	if (pos[u] > pos[v]) swap(u, v);
	update(pos[u], pos[v], val, pos[tar]);
}

int BIT[MX];

int get(int u) {
	int res = 0;
	for (int i = u; i > 0; i -= i & -i) res += BIT[i];
	return res;
}

void add(int u, int v) {
	for (int i = u; i < MX; i += i & -i) BIT[i] += v;
}

void get_col(int n) {
	for (int i = 1; i <= n; i++) qry[en[i]].push_back(st[i]);
	for (int i = 1; i <= n; i++) {
		if (!last[col[i]]) add(i, 1);
		else add(i, 1), add(last[col[i]], -1);
		last[col[i]] = i;
		for (int j = qry[i].size() - 1; j >= 0; j--) {
			int u = qry[i][j];
			Count[u] = get(i) - get(u - 1);
		}
	}
}

void get_cnt(int n) {
	for (int i = 1, nn = 0; i <= n; i += M, nn++) {
		int lim = min(i + M, n + 1);
		for (int j = i; j < lim; j++) {
			cnt[nn][Count[j]]++;
		}
	}
}

void get_S(int n) {
	for (int i = 1; i <= n; i++) {
		S[col[i]].insert(i);
	}
}

void get_anc(int n) {
	for (int i = 1; i <= n; i++) anc[i][0] = prv[i];
	for (int i = 1; i < L; i++) {
		for (int j = 1; j <= n; j++) anc[j][i] = anc[anc[j][i - 1]][i - 1];
	}
}

int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = L - 1; i >= 0; i--) {
		if (dp[anc[u][i]] >= dp[v]) u = anc[u][i];
		if (u == v) return u;
	}
	for (int i = L - 1; i >= 0; i--) {
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	}
	return anc[u][0];
}

int main() {
	
	freopen("count.in", "r", stdin);
	freopen("count.ans", "w", stdout);

	ios_base::sync_with_stdio(0);	
	int times; cin >> times;
	while (times--) {
		
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < MX; i++) vis[i] = Add[i] = 0, dp[i] = prv[i] = last[i] = BIT[i] = 0, S[i].clear(), con[i].clear();
		
		int n, q; cin >> n >> q;
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			con[u].push_back(v), con[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) cin >> buf[i];
		
		dp[1] = 1, pn = 0;
		dfs(1);
		hld(1, 1);

		for (int i = 1; i <= n; i++) col[pos[i]] = buf[i];

		get_col(n);
		get_cnt(n);
		get_S(n);
		get_anc(n);
		
		while (q--) {
			int type; cin >> type;
			if (type == 1) {
				int u, v; cin >> u >> v;
				int c = col[pos[u]];
				if (c == v) continue;
				
				set<int> :: iterator it = S[c].lower_bound(st[u]), iit;
				int tar = 0, w;
				iit = it; iit++;
				if (iit != S[c].end()) {
					w = id[*iit];
					w = lca(u, w);
					tar = w;
				}
				if (it != S[c].begin()) {
					iit = it; iit--;
					w = id[*iit];
					w = lca(u, w);
					if (dp[w] > dp[tar]) tar = w;
				}
				
				go(u, tar, -1);
				
				it = S[v].lower_bound(st[u]);
				tar = 0;
				w = id[*it];
				w = lca(u, w);
				tar = w;
				if (it != S[v].begin()) {
					iit = it; iit--;
					w = id[*iit];
					w = lca(u, w);
					if (dp[w] > dp[tar]) tar = w;
				}
				
				go(u, tar, 1);
				
				S[c].erase(st[u]), S[v].insert(st[u]);
				col[st[u]] = v;
			} else {
				int k; cin >> k;
				int ans = 0;
				for (int i = 0; i < MX / M + 5; i++) ans += cnt[i][k - Add[i]];
				printf("%d\n", ans);
			}
		}
	}
	
	return 0;
	
}
