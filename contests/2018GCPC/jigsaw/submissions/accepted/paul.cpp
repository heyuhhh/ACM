#include <bits/stdc++.h>
using namespace std;

#define FORN(i,n) for (int i = 0; i < (n); i++)

const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

void fail() {
	cout << "impossible" << endl;
	exit(0);
}

int main() {
	int n; cin >> n;
	
	vector<array<int,4>> b(n);
	vector<int> xor_val(4*n+1);
	FORN(i,n) FORN(j,4) {
		cin >> b[i][j];
		xor_val[b[i][j]] ^= i;
	}

	vector<int> x(n), y(n);
	int xmin = 0, xmax = 0, ymin = 0, ymax = 0;

	queue<int> q;
	vector<bool> mark(n);
	q.push(0);
	mark[0] = true;

	while (!q.empty()) {
		int i = q.front(); q.pop();
		xmin = min(xmin,x[i]);
		xmax = max(xmax,x[i]);
		ymin = min(ymin,y[i]);
		ymax = max(ymax,y[i]);
		
		FORN(dir,4) {
			int e = b[i][dir];
			if (e == 0) continue;
			int j = xor_val[e] ^ i;
			
			if (mark[j]) continue;
			
			// update position/orientation
			x[j] = x[i] + dx[dir], y[j] = y[i] + dy[dir];
			while (b[j][dir^2] != e) rotate(begin(b[j]),begin(b[j])+1,end(b[j]));
			
			q.push(j);
			mark[j] = true;
		}
	}
	
	// were all pieces reached?
	FORN(i,n) if (!mark[i]) fail();

	int h = xmax-xmin+1, w = ymax-ymin+1;

	// is the size of the bounding box correct?
	if (h * 1LL * w != n) fail();

	vector<vector<int>> res(h,vector<int>(w,-1));
	FORN(i,n) res[x[i]-xmin][y[i]-ymin] = i;
	
	// are there any empty cells?
	FORN(x,h) FORN(y,w) if (res[x][y] == -1) fail();
	
	// are the edges consistent?
	FORN(x,h) FORN(y,w) FORN(dir,4) {
		int nx = x+dx[dir], ny = y+dy[dir];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
			if (b[res[x][y]][dir] != 0) fail();
		} else {
			if (b[res[x][y]][dir] == 0) fail();
			if (b[res[x][y]][dir] != b[res[nx][ny]][dir^2]) fail();
		}
	}

	cout << h << " " << w << endl;
	FORN(x,h) FORN(y,w) cout << res[x][y]+1 << " \n"[y+1==w];
}
