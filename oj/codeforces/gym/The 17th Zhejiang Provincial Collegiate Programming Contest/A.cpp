#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int d;
int n[3];
int a[3][N];
ll ans;

void gao(int k) {
	int pMin[3] = {0, 0, 0}, pMax[3] = {0, 0, 0};
	for (int i = 0; i < n[k]; i++) {
		for (int j = 0; j < k; j++) {
			while (pMin[j] < n[j] && a[j][pMin[j]] <= a[k][i]) {
				++pMin[j];
			}
			while (pMax[j] < n[j] && abs(a[j][pMax[j]] - a[k][i]) <= d) {
				++pMax[j];
			}
		}
		for (int j = k + 1; j < 3; j++) {
			while (pMin[j] < n[j] && a[j][pMin[j]] < a[k][i]) {
				++pMin[j];
			}
			while (pMax[j] < n[j] && abs(a[j][pMax[j]] - a[k][i]) <= d) {
				++pMax[j];
			}
		}
		int t1 = -1, t2 = -1;
		for (int j = 0; j < 3; j++) if (j != k) {
			if (t1 == -1) {
				t1 = pMax[j] - pMin[j];
			} else {
				t2 = pMax[j] - pMin[j];
			}
		}
		ans += 1ll * t1 * t2;
	}
}

void run() {
	cin >> n[0] >> n[1] >> n[2];
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < n[k]; i++) {
			cin >> a[k][i];
		}
	}
	ans = 0;
	gao(0);
	gao(1);
	gao(2);
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	while (cin >> d) run();
	return 0;
}

