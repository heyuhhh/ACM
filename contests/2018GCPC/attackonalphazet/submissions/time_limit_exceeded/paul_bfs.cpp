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

int qi[N*N], qj[N*N];

int main() {
	int h, w; cin >> h >> w;
	getline(cin,a[0]);
	for (int i = 0; i < h+1; i++) getline(cin,a[i]);
	
	int m, si, sj;
	cin >> m >> si >> sj;
  si--; sj--;
	
	long long res = 0;
	for (int k = 1; k < m; k++) {
		cerr << k << endl;
		int ti, tj;
		cin >> ti >> tj;
    ti--; tj--;
		
		memset(dist,0x3f,sizeof dist);
		int qh = 0, qt = 1;
		dist[si][sj] = 0;
		qi[0] = si, qj[0] = sj;

		while (qh < qt) {
			int i = qi[qh], j = qj[qh++];
			if (i == ti && j == tj) break;
			
			for (int dir = 0; dir < 4; dir++) {
				if (is_wall(i,j,dir)) continue;
				int ni = i+di[dir], nj = j+dj[dir];
				if (dist[ni][nj] < oo) continue;
				dist[ni][nj] = dist[i][j]+1;
				qi[qt] = ni, qj[qt++] = nj;
			}
		}
		res += dist[ti][tj];
		si = ti, sj = tj;
	}
	cout << res << endl;
}
