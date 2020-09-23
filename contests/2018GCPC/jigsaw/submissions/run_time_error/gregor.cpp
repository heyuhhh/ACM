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

int pcs[400000][4][4];

map<int,vector<int> > hasE;
map<pii,pii> pos;

int dx[] = { 0, 1, 0,-1};
int dy[] = {-1, 0, 1, 0};

bool fail = false;
int maxX = 0;	
int maxY = 0;	

struct c{pii x; int y, z, u;};

stack<c> st;

void idfs(pii mypos, int p, int k, int s){
	if (mypos.first < 0 || mypos.second < 0) {fail = true; return;}
	maxX = max(maxX,mypos.first);
	maxY = max(maxY,mypos.second);

	int os = s % 2 ? (4 - s) : (2 - s);
	pii np = make_pair(mypos.first + dx[s], mypos.second + dy[s]);
	if (pos.find(np) != pos.end()) return;
	
	FOR(opi,0,2) if (hasE[pcs[p][k][s]][opi] != p){
		int op = hasE[pcs[p][k][s]][opi]; 
		if (op < 0 || op > 300000) cout << op << endl;
		FOR(nk,0,4) if (pcs[op][nk][os] == pcs[p][k][s]){
			pos[np] = make_pair(op,nk);
			FOR(ts,0,4) if (pcs[op][nk][ts]) {
				c cc;
				cc.x = np;
				cc.y = op;
				cc.z = nk;
				cc.u = ts;
				st.push(cc);
				//dfs(np,op,nk,ts);
			}
		}
	}
}

void dfs(pii mypos, int p, int k, int s){
	c cc; cc.x = mypos; cc.y = p; cc.z = k; cc.u = s;
	st.push(cc);
	while (sz(st)){
		cc = st.top(); st.pop();
		idfs(cc.x,cc.y,cc.z,cc.u);
	}
}



int main(){
	int n; cin >> n;
	
	int sp = -1, sr;
	FOR(i,0,n) {
		FOR(j,0,4) cin >> pcs[i][0][3-j];

		FOR(j,0,4) {
			if (pcs[i][0][j]) hasE[pcs[i][0][j]].push_back(i);
			FOR(k,1,4) pcs[i][k][(j+k) % 4] = pcs[i][0][j];
		}

		FOR(k,0,4) if (pcs[i][k][0] == 0 && pcs[i][k][3] == 0) sp = i, sr = k;
	}

	if (n == 1){
		if (sz(hasE) == 0) cout << "1 1\n 1" << endl; else cout << "impossible" << endl;
		return 0;
	}

	pos[make_pair(0,0)] = make_pair(sp,sr);
	if (sp != -1){
		if (pcs[sp][sr][1]) dfs(make_pair(0,0), sp, sr, 1); 
		else if (pcs[sp][sr][2]) dfs(make_pair(0,0), sp, sr, 2); 
		else fail=true;
	} else fail = true;

	maxX++; maxY++;
	cerr << maxX << " " << maxY << endl;

	if (maxX * maxY != n) fail = true;
	if (sz(pos) != n) fail = true;
	FOR(x,0,maxX) if (!fail) FOR(y,0,maxY) FOR(s,0,4) if (x + dx[s] < maxX && x + dx[s] >= 0 && y + dy[s] < maxY && y + dy[s] >= 0)
		if (pcs[pos[make_pair(x,y)].first][pos[make_pair(x,y)].second][s] !=
						pcs[pos[make_pair(x+dx[s],y+dy[s])].first][pos[make_pair(x+dx[s],y+dy[s])].second][s%2?(4-s):(2-s)])
				fail = true;


	if (fail) {
		cout << "impossible" << endl;
		return 0;
	}

	cout << maxY << " " << maxX << endl;
	FOR(y,0,maxY){
		FOR(x,0,maxX) cout << (x ? " " : "") << pos[make_pair(x,y)].first + 1;
		cout << endl;
	}
	return 0;
}
