#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 30000 + 5;

int primes[N], tot;
bool chk[N];

void init() {
	for (int i = 2; i < N; i++) {
		if (!chk[i]) primes[++tot] = i;
		for (int j = i + i; j < N; j += i) {
			chk[j] = true;
		}
	}
}

int cur;
double dp[2][N];

inline void chkmax(double& A, double B) {
	if (A < B) A = B;
}

double pre[N];

void run() {
	for (int i = 0; i < tot; i++, cur ^= 1) {
		int p = primes[i + 1];
		double logp = log(p);
		memcpy(dp[cur ^ 1], dp[cur], sizeof(dp[cur]));
		for (int j = 0; j < N; j++) {
			int cnt = 1;
			int np = p;
			while (j + np < N) {
				chkmax(dp[cur ^ 1][j + np], dp[cur][j] + cnt * logp);
				++cnt;
				np *= p;
			}
		}
	}
	for (int i = 1; i < N; i++) {
		pre[i] = max(pre[i - 1], dp[cur][i]);	
	}
	int T;
	cin >> T;
	while (T--) {
		int s;
		cin >> s;
		cout << pre[s] << '\n';	
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	init();
	run();
	return 0;
}

