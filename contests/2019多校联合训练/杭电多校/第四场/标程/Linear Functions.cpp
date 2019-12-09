#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int A[N], B[N], C[N], P[N], f[N], d[N], s[N], e[N];
long long dp[N], add[N];

vector<int> V[N];

int main() {
	int N, T;
	ios_base::sync_with_stdio(false);
	while (cin >> N >> T) {
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) cin >> B[i];
		for (int i = 1; i <= N; i++) cin >> P[i];
		int G = max(1, (int)(sqrt(N) / 2));
		long long ansv = 0, anst = 0;
		for (int i = 1; i <= N; i++) ansv += A[i];
		for (int i = 1; i <= N; i++) {
			if (!B[i]) continue;
			int cur = 0;
			int mind = P[i], minj = 0, flag = 0;
			for (int j = 1; j <= G; j++) {
				cur += B[i];
				if (cur >= P[i]) cur -= P[i];
				if (minj == 0 || cur < mind || P[i] - cur < mind) {
					flag = cur <= P[i] / 2;
					mind = min(cur, P[i] - cur);
					minj = j;
				}
			}
			V[minj].push_back(i);
			f[i] = flag;
			d[i] = mind;
			s[i] = P[i] / mind;
			e[i] = mind * s[i];
		}
		memset(dp, 0, sizeof(long long) * (T + 1));
		for (int i = 1; i <= N; i++) C[i] = A[i];
		for (int minj = 1; minj <= G; minj++) if (!V[minj].empty()) {
			long long delta = 0;
			for (int i : V[minj]) delta += (f[i] ? d[i] : -d[i]);
			for (int j = 0; j < minj; j++) {
				int U = (T - j) / minj + 1;
				memset(add, 0, sizeof(long long) * U);
				for (int i : V[minj]) {
					int cur = C[i];
					int upp = P[i] - e[i];
					add[0] += cur;
					int k = 0;
					if (f[i]) {
						k = (P[i] - cur - 1) / d[i] + 1;
						if (k >= U) continue;
						cur += d[i] * k - P[i];
						while (k < U) {
							add[k] -= P[i];
							k += s[i];
							cur -= upp;
							if (cur < 0) {
								k++;
								cur += d[i];
							}
						}
					} else {
						k = cur / d[i] + 1;
						if (k >= U) continue;
						cur += P[i] - d[i] * k;
						while (k < U) {
							add[k] += P[i];
							k += s[i];
							cur += upp;
							if (cur >= P[i]) {
								k++;
								cur -= d[i];
							}
						}
					}
				}
				dp[j] += add[0];
				for (int k = j + minj, l = 1; k <= T; l++, k += minj) add[l] += add[l - 1] + delta, dp[k] += add[l];
				for (int i : V[minj]) {
					C[i] += B[i];
					C[i] -= (C[i] >= P[i]) * P[i];
				}
			}
		}
		for (int i = 1; i <= T; i++) if (dp[i] > ansv) ansv = dp[i], anst = i;
		for (int i = 1; i <= G; i++) V[i].clear();
		cout << ansv << ' ' << anst << endl;
	}
	return 0;
}

