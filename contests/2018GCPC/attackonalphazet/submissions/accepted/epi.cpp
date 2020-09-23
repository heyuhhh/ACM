#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = ll(b) - 1; i >= (a); i--)
#define DBG(x) ({if(1) cerr << "DBG: " << (#x) << " = " << (x) << endl; })

ll x_size;
ll ind;
vl first;
vl depth;
vector<pll> valid_moves = {{0,-1},{-1,0},{0,1},{1,0}};

inline ll hashCoords(ll x, ll y) {
	return x_size * y + x;
}

void createTree(vector<string>& maze, vector<vector<bool>>& visited, stack<tuple<ll,ll,ll,ll>> &st) { //ll x, ll y, ll curDepth) {
  ll x, y, curDepth, skip;
  while(!st.empty()) {
    tie(x,y,curDepth,skip) = st.top();
    st.pop();
    visited[x][y] = true;
    if(skip == 0)
  	  first[hashCoords(x,y)] = ind;
    depth[ind++] = curDepth;
    FOR(i,skip,4) {
      //0 -> go north
      if(i == 0 && maze[y][2 * x + 1] == '_')
        continue;
      // 1 -> go west
      if(i == 1 && maze[y + 1][2 * x] == '|')
        continue;
      // 2 -> go south
      if(i == 2 && maze[y + 1][2 * x + 1] == '_')
        continue;
      // 3 -> go east
      if(i == 3 && maze[y + 1][2 * x + 2] == '|')
        continue;
    
      pll move = valid_moves[i];
      if(visited[x + move.xx][y + move.yy])
        continue;
      st.push(mt(x, y, curDepth, i + 1));
      st.push(mt(x + move.xx, y + move.yy, curDepth + 1, 0));
      break;
    }
  }
}

    
int main() {
	ios_base::sync_with_stdio(false);
	ll y_size, n_queries;
  string line;
  getline(cin, line);
  stringstream ss;
  ss.str(line);
	ss >> y_size >> x_size;
	vector<string> maze(y_size + 1);

  FOR(i,0,y_size + 1) getline(cin, maze[i]);
  
	// init Lowest Common Ancestor

	first.resize(x_size * y_size,-1);
	depth.resize(2*x_size*y_size -1);

  ind = 0;
  vector<vector<bool>> visited(x_size, vector<bool>(y_size, false));
  stack<tuple<ll, ll, ll, ll>> st;
  st.push(mt(0LL,0LL,0LL,0LL));
  // create tree from maze
  createTree(maze, visited, st);
  

  // init Range Minimum Query
	ll N = sz(depth);
	vl ld(N + 1);
	ld[1] = 0;
	FOR(i,2,N + 1) {
		ld[i] = ld[i-1];
		if(2LL << ld[i] <= i) ld[i]++;
	}

	vvl imin(N,vl(ld[N] + 1));

	FOR(i,0, N) imin[i][0] = i;

	FOR(j,1,ld[N] + 1) {
		FOR(i,0,N - (1LL << j) + 1) {
			ll i1 = imin[i][j-1];
			ll i2 = imin[i + (1LL << (j-1))][j-1];
			imin[i][j] = (depth[i1] <= depth[i2])? i1 : i2;
		}
	}
	cin >> n_queries;

	// queries
	ll dist = 0;
	ll qX, qY;
	cin >> qY >> qX;
  qX--;
  qY--;
	FOR(i,1,n_queries) {
		ll tX,tY;
		cin >> tY >> tX;
    tY--;
    tX--;
			
		ll fA = first[hashCoords(qX,qY)];
		ll fB = first[hashCoords(tX,tY)];

		if(fA > fB) {
			ll t = fA;
			fA = fB;
			fB = t;
		}

		ll dA = depth[fA];
		ll dB = depth[fB];
		

		ll n = ld[fB - fA];
		fB -= (1LL << n);
		ll dLCA = depth[imin[fA][n]] <= depth[imin[fB][n]] ? depth[imin[fA][n]] : depth[imin[fB][n]];
		
		dist += (dA - dLCA) + (dB - dLCA);

		qX = tX;
		qY = tY;
	}

	cout << dist << endl;

	return 0;
}
