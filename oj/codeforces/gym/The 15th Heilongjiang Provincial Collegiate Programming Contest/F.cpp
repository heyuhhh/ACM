// Author : heyuhhh
// Created Time : 2020/11/07 16:20:13
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;
const int dx[] = {0, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 0, -1, 0, -1};
void run() {
    int x0, y0;
    cin >> x0 >> y0;
    int n;
    cin >> n;
    vector<pii> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].fi >> points[i].se;
    }
    sort(all(points), [&] (pii A, pii B) {
        if (A.se != B.se) return A.se < B.se;
        return A.fi > B.fi;
    });
    vector<int> dp(n + 1, INF);
    auto check = [&] (ll sx, ll sy, ll ex, ll ey) {
        if (ey < sy) return false;
        if (sx == ex) {
            if ((ey - sy) % 2 == 0) return true;
            return false;
        }
        if (ex > sx) {
            ll dx = ex - sx;
            ll ly = dx, ry = 2 * dx;
            if (sy + ly <= ey) {
                if (ly != ry) return true;
                if ((ey - (sy + ly)) % 2 == 0) return true;
            }
            return false;
        }
        if (ex < sx) {
            ll dx = sx - ex;
            ll ly = dx, ry = 2 * dx;
            if (sy + ly <= ey) {
                if (ly != ry) return true;
                if ((ey - (sy + ly)) % 2 == 0) return true;
            }
            return false;
        }
    };
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 7; k++) {
            int nx = points[i - 1].fi + dx[k];
            int ny = points[i - 1].se + dy[k];
            for (int j = 0; j < i; j++) {
                if (j == 0) {
                    if (check(x0, y0, nx, ny)) {
                        dp[i] = min(dp[i], dp[0] + 1);
                    }
                } else if (points[j - 1].se != points[i - 1].se) {
                    if (check(points[j - 1].fi, points[j - 1].se, nx, ny)) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                    if (check(points[j - 1].fi, points[j - 1].se + 1, nx, ny)) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (dp[i] != INF) {
        ans = max(ans, dp[i]);
        cout << i << ' ' << dp[i] << endl;
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}