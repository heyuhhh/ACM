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

struct node {
    int ch[26];
    int len, fa;
    node() { memset(ch, 0, sizeof(ch)), len = 0; }
} dian[N];
int last = 1, tot = 1;
int f[N];
set<int> S[N];
void add(int id, int c) {
    int p = last;
    int np = last = ++tot;
    S[np].emplace(id);
    dian[np].len = dian[p].len + 1;
    f[np] = 1;
    for (; p && !dian[p].ch[c]; p = dian[p].fa) dian[p].ch[c] = np;
    if (!p)
        dian[np].fa = 1;
    else {
        int q = dian[p].ch[c];
        if (dian[q].len == dian[p].len + 1)
            dian[np].fa = q;
        else {
            int nq = ++tot;
            dian[nq] = dian[q];
            dian[nq].len = dian[p].len + 1;
            dian[q].fa = dian[np].fa = nq;
            for (; p && dian[p].ch[c] == q; p = dian[p].fa) dian[p].ch[c] = nq;
        }
    }
}

vector<pii> Q[N];
int ans[N];
int n, m;
vector<int> G[N];
void dfs(int u) {
    for (auto v : G[u]) {
        dfs(v);
        if (sz(S[v]) > sz(S[u])) {
        	swap(S[u], S[v]);
        }
        for (auto it : S[v]) {
        	S[u].insert(it);
        }
    }
    for (auto it : Q[u]) {
    	int d = it.first, id = it.second;
    	auto p = S[u].begin();
    	int res = 0;
    	while (p != S[u].end()) {
    		++res;
    		p = S[u].lower_bound((*p) + d);
    	}
    	ans[id] = res;
    }
}

map<int, int> mp[N];

struct query {
	int p, d, id;
	bool operator < (const query& A) const {
		if (p == A.p) return d < A.d;
		return p < A.p;
	}
}q[N];
int D;

void run() {
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		add(i + 1, s[i] - 'a');
	}
    for (int i = 1; i <= tot; i++) {
        if (dian[i].fa) {
            G[dian[i].fa].emplace_back(i);
        }
    }
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= m; i++) {
		string t;
		cin >> t;
		int len = t.length();
		int p = 1;
		bool f = true;
		for (int j = 0; j < len; j++) {
			p = dian[p].ch[t[j] - 'a'];
			if (p == 0) {
				f = false;
				break;	
			}
		}
		if (!f) {
			ans[i] = 0;
			continue;
		}
		q[++D] = query{p, len, i};
	}
	sort(q + 1, q + D + 1);
	for (int i = 1; i <= D; i++) {
		if (!(q[i].p == q[i - 1].p && q[i].d == q[i - 1].d)) {
			Q[q[i].p].emplace_back(q[i].d, q[i].id);
		}
	}
	dfs(1);
	for (int i = 1; i <= D; i++) {
		if (ans[q[i].id] == -1) {
			ans[q[i].id] = ans[q[i - 1].id];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
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

