#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 3e6 + 5;

void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0, g = a;
        return ;
    }
    exgcd(b, a % b, g, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
}

ll CRT(const vector<int>& a, const vector<int>& m) {
    assert(sz(a) == sz(m));
    ll x0 = a[0], m0 = m[0], n = sz(a);
    for (int i = 1; i < n; i++) {
        ll x1 = a[i], m1 = m[i], x, y, d;
        exgcd(m0, m1, d, x, y);
        if ((x0 - x1) % d) return -1;
        x = (x1 - x0) / d * x % (m0 / d * m1);
        x0 = (x * m0 + x0) % (m0 / d * m1);
        m0 = m0 / d * m1;
        if (x0 < 0) x0 += m0;
    }
    return x0;
}

int a[N], b[N];
vector<int> G[N];
int tot;
bool vis[N];
vector<int> V;

void dfs(int u) {
	vis[u] = true;
	V.emplace_back(u);
	for (auto v : G[u]) if (!vis[v]) {
		dfs(v);
	}
}

int nxt[N];

void Get_next(const char *s) {
    int j, L = strlen(s);
    nxt[0] = j = -1;
    for(int i = 1; i < L; i++) {
        while(j >= 0 && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}

pii findPos(const char* s, const char* t) {
	int L1 = strlen(s), L2 = strlen(t);
	int fir = -1, sec = -1;
	for (int i = 0, j = -1; i < L1; i++) {
		while (j >= 0 && (j == L2 - 1 || s[i] != t[j + 1])) j = nxt[j]; 
		if (s[i] == t[j + 1]) ++j;
		if (j == L2 - 1) {
			if (fir == -1) {
				fir = i;
			} else {
				sec = i - fir;
				fir -= L2 - 1;
				break;
			}
		}
	}
	return make_pair(fir, sec);
}

void run() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int to = 2 * i;
		if (to >= n) to -= n - 1;
		G[i].emplace_back(to);
	}
	vector<int> a, b; 
	for (int i = 0; i < n; i++) if (!vis[i]) {
		V.clear();
		dfs(i);
		string newS = "", newT = "";
		for (auto it : V) {
//			cout << it << ' ';
			newS += s[it];
			newT += t[it];
		}
//		cout << endl;
		newS += newS + newS;
		Get_next(newT.c_str());
		pii now = findPos(newS.c_str(), newT.c_str());
		if (now.fi == -1) {
			cout << -1 << '\n';
			return;
		}
		++tot;
		a.emplace_back(now.fi), b.emplace_back(now.se);
	}	
	ll res = CRT(a, b);
	cout << res << '\n';
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

