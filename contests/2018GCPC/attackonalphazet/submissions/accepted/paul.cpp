#include <bits/stdc++.h>
using namespace std;

const int N = 1010, K = 20;
int h[N*N];
int p[N*N][K];

string a[N];
int u[N][N];

const int di[] = {1,-1,0,0}, dj[] = {0,0,1,-1};

bool is_wall(int i, int j, int dir) {
	return (dir == 0 && a[i+1][2*j+1] == '_') ||
	       (dir == 1 && a[i][2*j+1] == '_') ||
		   (dir == 2 && a[i+1][2*j+2] == '|') ||
		   (dir == 3 && a[i+1][2*j] == '|');
}

int n = 1;

void dfs(int v, int i, int j) {
	h[v] = h[ p[v][0] ] + 1;
	u[i][j] = v;
	for (int k = 1; k < K; k++) p[v][k] = p[ p[v][k-1] ][k-1];
	
	for (int dir = 0; dir < 4; dir++) {
		if (is_wall(i,j,dir)) continue;
		if (u[i+di[dir]][j+dj[dir]]) continue;
		p[++n][0] = v;
		dfs(n, i+di[dir], j+dj[dir]);
	}
}

int lca(int v, int w) {
	if (h[w] > h[v]) swap(v,w);

	int dh = h[v]-h[w];
	for (int k = 0; k < K; k++) if (dh & (1 << k)) v = p[v][k];

	if (v == w) return v;
	
	for (int k = K-1; k >= 0; k--) {
		if (p[v][k] != p[w][k]) v = p[v][k], w = p[w][k];
	}
	return p[v][0];
}

int dist(int v, int w) {
	int x = lca(v,w);
	return h[v]+h[w]-2*h[x];
}

int main() {
	int h, w; cin >> h >> w;
	getline(cin,a[0]);
	for (int i = 0; i < h+1; i++) getline(cin,a[i]);
	
	dfs(1,0,0);
	
	int m, i, j;
	cin >> m >> i >> j;
  i--; j--;
	
	long long res = 0;
	for (int k = 1; k < m; k++) {
		int ni, nj;
		cin >> ni >> nj;
		res += dist(u[i][j], u[--ni][--nj]);
		i = ni, j = nj;
	}
	cout << res << endl;
}
