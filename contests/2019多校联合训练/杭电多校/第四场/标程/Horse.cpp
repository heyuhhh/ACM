#include <bits/stdc++.h>
using namespace std;
const int maxk = 110, maxm = 110, maxn = 10010;
typedef long long LL;
LL h[maxn];
LL dp1[maxm][maxn];
int ck, qh, qt, q[maxn];
LL sh[maxn], sw[maxn], dp2[maxk][maxn];
inline LL w(int l, int r) { return sw[r] - sw[l] - sh[l] * (r - l); }
inline double g(int x, int y) { return 1.0 * (dp2[ck - 1][x] - dp2[ck - 1][y] - sw[x] + sw[y] + sh[x] * x - sh[y] * y) / (sh[x] - sh[y]); };
inline void chkmin(LL &a, LL b) { if (a > b) a = b; }
inline void chkmax(LL &a, LL b) { if (a < b) a = b; }
int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int tc;
	for (scanf("%d", &tc); tc--;) {
 		int n, m, k;
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", h + i);
			sh[i] = sh[i - 1] + h[i];
			sw[i] = sw[i - 1] + sh[i];
		}
		memset(dp1, 0, sizeof(dp1));
		for (int i = 1; i <= m; ++i) for (int j = n - i + 1; j >= 1; --j) {
			dp1[i][j] = dp1[i][j + 1];
			chkmax(dp1[i][j], dp1[i - 1][j + 1] + h[j] * (n - j + 1));
		}
		for (int i = 1; i <= n; ++i) dp2[0][i] = w(0, i);
		for (ck = 1; ck <= k; ++ck) {
			qh = qt = 0;
			q[qt++] = ck - 1;
			for (int i = ck; i <= n; ++i) {
				for (; qt - qh >= 2 && g(q[qh], q[qh + 1]) < i; ++qh);
				dp2[ck][i] = dp2[ck - 1][q[qh]] + w(q[qh], i);
				for (; qt - qh >= 2 && g(q[qt - 2], q[qt - 1]) >= g(q[qt - 1], i); --qt);
				q[qt++] = i;
			}
/*			for (int i = ck; i <= n; ++i) {
				LL v = 0x3f3f3f3f3f3f3f3fLL;
				for (int j = ck - 1; j < i; ++j) {
					LL t = dp2[ck - 1][j] + w(j, i);
					v = v < t ? v : t;
				}
				if (dp2[ck][i] != v) printf("%lld %lld\n", dp2[ck][i], v);
				assert(dp2[ck][i] == v);
			}*/
		}
		LL ans = 0x3f3f3f3f3f3f3f3fLL;
		for (ck = 0; ck <= k; ++ck) chkmin(ans, dp2[ck][n]);
		printf("%lld\n", dp1[m][1] - ans);
	}
	return 0;
}
