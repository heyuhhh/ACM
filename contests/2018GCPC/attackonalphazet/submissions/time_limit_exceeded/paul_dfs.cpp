#include <bits/stdc++.h>
using namespace std;

const int N = 1010, oo = 0x3f3f3f3f;
int dist[N][N];

string a[N];

const int di[] = {1,-1,0,0}, dj[] = {0,0,1,-1};

bool is_wall(int i, int j, int dir) {
	return (dir == 0 && a[i+1][2*j+1] == '_') ||
	       (dir == 1 && a[i][2*j+1] == '_') ||
		   (dir == 2 && a[i+1][2*j+2] == '|') ||
		   (dir == 3 && a[i+1][2*j] == '|');
}

int ni, nj;

bool dfs(int i, int j) {
	if (i == ni && j == nj) return true;

	for (int dir = 0; dir < 4; dir++) {
		if (is_wall(i,j,dir)) continue;
		int ni = i+di[dir], nj = j+dj[dir];
		if (dist[ni][nj] < oo) continue;
		dist[ni][nj] = dist[i][j]+1;
		if (dfs(ni,nj)) return true;
	}
	return false;
}

int main() {
	int h, w; cin >> h >> w;
	getline(cin,a[0]);
	for (int i = 0; i < h+1; i++) getline(cin,a[i]);
	
	int m, i, j;
	cin >> m >> i >> j;
  i--; j--;
	
	long long res = 0;
	for (int k = 1; k < m; k++) {
		cin >> ni >> nj;
    ni--; nj--;
		memset(dist,0x3f,sizeof dist);
		dist[i][j] = 0;
		dfs(i,j);
		res += dist[ni][nj];
		i = ni, j = nj;
	}
	cout << res << endl;
}
