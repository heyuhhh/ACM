#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = 2.0 * acos(0.0);


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MAXN 2000

vector<ll> adj[MAXN];
vector<ll> wdj[MAXN];
ll p, v[MAXN];
ll od[MAXN];
ll lp[MAXN];

void dfs(ll a) {
	if (v[a]) return;
	v[a] = 1;
	FOR(i, 0, sz(adj[a])) dfs(adj[a][i]);
	v[a] = 2;
	od[p] = a;
	p--;
}

void topsort(ll n) {
	FOR(i, 0, n) v[i] = 0;
	p = n-1;
	FOR(i, 0, n) if (!v[i]) dfs(i);
}

int main(){
	int n,m; cin >> n >> m;
	FOR(i,0,m){
		int s,t,c; cin >> s >> t >> c; s--; t--;
		adj[s].push_back(t);
		wdj[s].push_back(c);
	}

	topsort(n);

	FOR(i,0,n) lp[i] = 0;
	FOR(i,0,n) FOR(j,0,sz(adj[od[i]])) lp[adj[od[i]][j]] = max(lp[adj[od[i]][j]], lp[od[i]] + wdj[od[i]][j]);
	
	ll ans = 0;
	FOR(i,0,n) ans = max(lp[i],ans);
	cout << ans << endl;
}
