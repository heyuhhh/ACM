#include <bits/stdc++.h>
using namespace std;

#define FORN(i,n) for (int i = 0; i < (n); i++)

const int N = 1010, Q = 1e5 + 10;
int h[N*N], p[N*N];
set<int> s[N*N];
int res[Q];

int Find(int a) {
	if (a == p[a]) return a;
	return p[a] = Find(p[a]);
}

void Union(int a, int b, int h) {
	a = Find(a), b = Find(b);
	if (a == b) return;
	//if (s[a].size() > s[b].size()) swap(a,b);
	
	for (int i: s[a]) {
		if (s[b].count(i)) {
			res[i] = h;
			s[b].erase(i);
		} else {
			s[b].insert(i);
		}
	}
	s[a].clear();
	p[a] = b;
}

int I(int x, int y) { return x*N + y; }

const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int main() {
	int m, n, q;
	cin >> m >> n >> q;

	FORN(x,m) FORN(y,n) cin >> h[I(x,y)];
	
	FORN(i,q) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		s[I(x1,y1)].insert(i);
		s[I(x2,y2)].insert(i);
		
		if (x1 == x2 && y1 == y2) res[i] = h[I(x1,y1)];
	}
	
	vector<tuple<int,int,int>> v;

	iota(p,p+(N*N),0);
	FORN(x,m) FORN(y,n) v.emplace_back(h[I(x,y)],x,y);
	
	sort(begin(v),end(v));

	for (auto t: v) {
		int hh, x, y;
		tie(hh,x,y) = t;
		FORN(k,4) {
			int nx = x+dx[k], ny = y+dy[k];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (h[I(nx,ny)] > h[I(x,y)]) continue;
			Union(I(x,y),I(nx,ny),hh);
		}
	}
	
	FORN(i,q) cout << res[i] << endl;
}
