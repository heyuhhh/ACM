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

#define MAXN (500*500 + 10)

int hh[MAXN];
int pa[MAXN];
int rk[MAXN];
set<int> qq[MAXN];
int qa[MAXN];
int cqa;

int ufind(int i) {
    if(pa[i] != i) pa[i] = ufind(pa[i]);
    return pa[i];
}

void uset(int r, int c){
	FORIT(i,qq[c])
		if (qq[r].count(*i)) qa[*i] = cqa, qq[r].erase(*i);
		else qq[r].insert(*i);
}

int uunion(int a,int b) {
    a = ufind(a); b = ufind(b);
    if(a == b) return 0;
    if(rk[a] > rk[b])
        pa[b] =a, uset(a,b);
    else
        pa[a] = b, uset(b,a);
    if(rk[a] == rk[b]) rk[b]++;
    return 1;
}

int h,w,q;
int idx(int i, int j){return i*w + j;}


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
	FOR(i,0,MAXN) pa[i] = i, rk[i] = 0;
	cin >> h >> w >> q;
	map<int,vector<pii> > m;
	FOR(i,0,h) FOR(j,0,w) {
		int val; cin >> val;
		m[val].push_back(make_pair(i,j));
		hh[idx(i,j)] = val;
	}
	FOR(i,0,q){
		int i1,j1,i2,j2; cin >> i1 >> j1 >> i2 >> j2;
		i1--;
		j1--;
		i2--;
		j2--;
		qq[idx(i1,j1)].insert(i);
		qq[idx(i2,j2)].insert(i);
		if (idx(i1,j1) == idx(i2,j2)) qa[i] = hh[idx(i1,j1)];
	}

	FORIT(ents, m){
		cqa = ents->first;
		FORIT(p,ents->second){
			int i = p->first;
			int j = p->second;

			FOR(d,0,4) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
				if (hh[idx(i,j)] < hh[idx(ni,nj)]) continue;
				uunion(idx(i,j),idx(ni,nj));	
			}
		}
	}

	FOR(i,0,q) cout << qa[i] << endl;
}
