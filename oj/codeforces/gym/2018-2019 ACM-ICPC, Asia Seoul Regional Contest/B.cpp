#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 500 + 5;

int n, m;
int a[N][N], d[N][N], s[N][N];
int tmp[N][N];

void mul(int A[N][N], int B[N][N]) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				if (A[i][k] != 0 && B[k][j] != 0) {
					tmp[i][j] = min(tmp[i][j], min(A[i][k], B[k][j]));
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (tmp[i][j] != INF) A[i][j] = max(A[i][j], tmp[i][j]);
		}
	}
}

void run() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		vector<int> a(m);
		for (int j = 0; j < m; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				if (a[j] > 0 && a[j] < a[k]) ++d[j + 1][k + 1];
				if (a[j] == 0 && a[k] != 0) ++d[k + 1][j + 1];
			}
		}
	}
//	memset(s, -1, sizeof(INF));
//	memset(a, -1, sizeof(INF));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] > d[j][i]) {
//				cout << i << ' ' << j << ' ' << d[i][j] << endl;
				assert(d[i][j] != 0);
				s[i][j] = a[i][j] = d[i][j];
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][k] != 0 && s[k][j] != 0) 
					s[i][j] = max(s[i][j], min(s[i][k], s[k][j]));
			}
		}
	}
	for (int x = 1; x <= m; x++) {
		bool f = true;
		for (int y = 1; y <= m; y++) if (x != y) {
			if (s[x][y] < s[y][x]) {
				f = false;
				break;
			}
		}
		if (f) cout << x << ' ';
	}
	cout << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	run();	
	return 0;
}
