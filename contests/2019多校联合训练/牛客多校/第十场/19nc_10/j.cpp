#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, \
  ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

typedef long long LL;
typedef unsigned long long ULL;

int n, k;
vector<pair<LL, LL>> b;
LL wps[8192];
LL tot;
LL dp[8192][8192];
int pre[8192][8192];

void solve(int j, int l, int r, int vl, int vr) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    for (int i = vl; i < mid and i < vr; i++) {
        LL nv = dp[j-1][i] + (wps[mid] - wps[i]) * b[i].first;
        if (nv > dp[j][mid]) {
            dp[j][mid] = nv;
            pre[j][mid] = i;
        }
    }
    solve(j, l, mid, vl, pre[j][mid] + 1);
    solve(j, mid+1, r, pre[j][mid], vr);
}

int main() {
    scanf("%d%d", &n, &k);
    rep (i, n) {
        LL w, h; scanf("%lld%lld", &w, &h);
        tot += w * h;
        b.emplace_back(h, w);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) wps[i+1] = b[i].second;
    partial_sum(wps, wps + n + 1, wps);
    rep (i, k + 1) rep (j, n + 1) dp[i][j] = LLONG_MIN;
    dp[0][0] = 0;
    Rep (i, k) solve(i, 0, n + 1, 0, n + 1);
    cout << tot - dp[k][n] << endl;
    vector<int> trans;
    int cur = n, kk = k;
    while (cur) {
        trans.push_back(cur);
        cur = pre[kk][cur];
        kk--;
    }
    reverse(range(trans));
    for (int x : trans) cerr << x << ' ' ;
    cerr << endl;
    return 0;
}
