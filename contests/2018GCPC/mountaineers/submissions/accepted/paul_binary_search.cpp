#include <bits/stdc++.h>
using namespace std;

#define y1 Y1
#define FORN(i,n) for (int i = 0; i < (n); i++)

const int N = 1010, Q = 1e5 + 10, K = 20;
int h[N*N], p[N*N];
int lo[Q], hi[Q], c[Q], d[Q];

int Find(int a) {
	if (a == p[a]) return a;
	return p[a] = Find(p[a]);
}

void Union(int a, int b, int h) {
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (rand() & 1) swap(a,b);
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
		c[i] = I(x1,y1), d[i] = I(x2,y2);
		
		if (c[i] == d[i]) lo[i] = hi[i] = h[I(x1,y1)];
	}
	
	fill_n(hi,q,1 << K);

	FORN(iter,K) {
		vector<tuple<int,int,int>> v;

		iota(p,p+(N*N),0);
		FORN(x,m) FORN(y,n) v.emplace_back(h[I(x,y)],x,y);
		FORN(i,q) v.emplace_back((lo[i]+hi[i])/2,N,i);

		sort(begin(v),end(v));

		for (auto t: v) {
			int hh, x, y;
			tie(hh,x,y) = t;

			if (x == N) {
				int i = y;
				if (Find(c[i]) == Find(d[i])) hi[i] = hh; else lo[i] = hh;
			} else {
				FORN(k,4) {
					int nx = x+dx[k], ny = y+dy[k];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (h[I(nx,ny)] > h[I(x,y)]) continue;
					Union(I(x,y),I(nx,ny),hh);
				}
			}
		}
	}
	
	FORN(i,q) cout << hi[i] << endl;
}
