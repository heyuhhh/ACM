// Author : heyuhhh
// Created Time : 2020/07/27 12:45:15
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
const int N = 200 + 5;
const double eps = 1e-9;

int n, m;
int a[N][N], val[N][N];

bool check(int i, double x) {
    for (int j = 1; j <= m; j++) {
        double t = 1.0 * val[i][j] - x * a[i][j];
        if (t >= eps) {
            return true;
        }
    }
    return false;
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            val[i][j] = val[i - 1][j] + a[i][j];
        }
    }
    double ans = 0;
    for (int row = 1; row <= n; row++) {
        double l = 0, r = INF, mid;
        for (int i = 0; i < 100; i++) {
            mid = (l + r) / 2.0;
            if (check(row, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans = max(ans, l);
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int T; cin >> T; while(T--)
    run();
    return 0;
}