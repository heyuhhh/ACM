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

int h,w;
vi adj[1000000];
int idx(int x, int y) {return x * h + y;}

int eT[3000000];

int cp = 0;
int visi[1000000];
int d[1000000];
void dfs(int i,int cd){
	if (visi[i] != -1) return;
	visi[i] = cp;
	eT[cp++] = i;
	d[i] = cd;
	FORIT(j,adj[i]){
		int cpb = cp;
		dfs(*j,cd+1);
		if (cp != cpb) eT[cp++] = i;
	}
}

struct rmt{
	rmt *l,*r;
	int lv, rv;
	int min;
};

rmt* build(int l, int r){
	rmt * t = new rmt();
	t-> lv = l; t-> rv = r;
	if (l == r){
		t->min = d[eT[l]];
	} else {
		t->l = build(l,(l+r)/2);
		t->r = build((l+r)/2+1,r);
		t->min = min(t->l->min, t->r->min);
	}

	return t;
}

int rmin(rmt*t, int l, int r){
	if (l <= t->lv && t->rv <= r) return t->min;
	if (r < t->lv) return oo;
	if (t->rv < l) return oo;
	return min(rmin(t->l,l,r), rmin(t->r,l,r));
}

int main(){
	cin >> h >> w;
	string l; getline(cin,l); getline(cin,l);
	memset(visi,-1,sizeof(visi));
	memset(eT,0,sizeof(eT));
	FOR(i,0,h) {
		getline(cin,l);
		FOR(j,1,2*w){
			// compute index
			int x = (j-1) / 2;
			int y = i;
			int m = j % 2;
			if (m == 1 && l[j] == ' ') {
				adj[idx(x,y)].push_back(idx(x,y+1));
				adj[idx(x,y+1)].push_back(idx(x,y));
			}

			if (m == 0 && l[j] == ' ') {
				adj[idx(x,y)].push_back(idx(x+1,y));
				adj[idx(x+1,y)].push_back(idx(x,y));
			}
		}
	}

	dfs(0,0);
	rmt*t = build(0,2*h*w-1);

	int q; cin >> q;
	int lx, ly; cin >> ly >> lx; 
  lx--; ly--;
	ll acc = 0;
	FOR(i,0,q-1){
		int x,y; cin >> y >> x;
		int a = visi[idx(--x,--y)];
		int b = visi[idx(lx,ly)];
		int lca = rmin(t, min(a,b), max(a,b));
		acc += d[idx(x,y)] + d[idx(lx,ly)] - 2*lca;
		lx = x, ly = y;
	}

	cout << acc << endl;
}
