#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define rep(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
const int NN = 4e6 + 2e5 + 5;

int n, m, N, M;
char mp[1010][1010];
char s[NN];

struct node{
    int ch[27];
    int len, fa;
    node(){memset(ch, 0, sizeof(ch)), len = 0;}
}dian[NN];
int last = 1, tot = 1;
ll f[NN];
void add(int c) {
    int p = last;
    int np = last = ++tot;
    dian[np].len = dian[p].len + 1;
    f[np] = 1;
    for(; p && !dian[p].ch[c]; p = dian[p].fa) dian[p].ch[c] = np;
    if(!p) dian[np].fa = 1;
    else {
        int q = dian[p].ch[c];
        if(dian[q].len == dian[p].len + 1) dian[np].fa = q;
        else {
            int nq = ++tot; dian[nq] = dian[q];
            dian[nq].len = dian[p].len + 1;
            dian[q].fa = dian[np].fa = nq;
            for(; p && dian[p].ch[c] == q; p = dian[p].fa) dian[p].ch[c] = nq;
        }
    }
}
int q[NN], in[NN]; //*2 
void topsort() {
    int l = 1, r = 0;
    for(int i = 1; i <= tot; i++) in[dian[i].fa]++;
    for(int i = 1; i <= tot; i++) if(!in[i]) q[++r] = i;
    while(l <= r) {
        int x = q[l++];
        f[dian[x].fa] += f[x];
        if(--in[dian[x].fa] == 0) q[++r] = dian[x].fa;
    }
} 
int cnt[26];
void run() {
	memset(cnt, 0, sizeof(cnt));
	cin >> N >> M;
	n = 0;
	rep(i, 1, N) {
		rep(j, 1, N) {
			cin >> mp[i][j];
			if(mp[i][j] == '#') mp[i][j] = '{';
			s[n++] = mp[i][j];
			if (mp[i][j] < '{') {
				++cnt[mp[i][j] - 'a'];
			}
		}
		s[n++] = '{';
	}
	rep(i, 1, N) {
		rep(j, 1, N) s[n++] = mp[j][i];
		s[n++] = '{';
	}
	s[n] = 0;
	last = tot = 1;
	for (int i = 0; i < n; i++) {
		add(s[i] - 'a');
	}
	topsort();
	
	bool flag = false;
	ll ans = 0;
	while (M--) {
		string S;
		int val;
		cin >> S >> val;
		if (flag) continue;
		int len = S.length();
		if (len == 1) {
			if (cnt[S[0] - 'a'] == 0) {
				flag = true;
				continue;
			}
			ans += 1ll * cnt[S[0] - 'a'] * val;
			continue;
		}
		int now = 1;
		for (int i = 0; i < len; i++) {
			now = dian[now].ch[S[i] - 'a'];
			if (now == 0) {
				flag = true;
				break;
			}
		}
		ans += f[now] * val;
	}
	
	if (flag) ans = -1;
	cout << ans << '\n';
	
	for (int i = 1; i <= tot; i++) {
		in[i] = f[i] = q[i] = 0;
		for (int j = 0; j < 27; j++) {
			dian[i].ch[j] = 0;
		}
		dian[i].len = dian[i].fa = 0;
	}
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

