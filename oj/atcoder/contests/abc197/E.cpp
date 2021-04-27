// Author : heyuhhh
// Created Time : 2021/03/27 20:18:13
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
void run() {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    vector<int> L(n, INF), R(n, -INF);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> c[i];
        --c[i];
        L[c[i]] = min(L[c[i]], x[i]);
        R[c[i]] = max(R[c[i]], x[i]);
    }
    vector<ll> dp(2, 0);
    vector<int> last(2);
    for (int i = 0; i < n; i++) if (R[i] != -INF) {
        vector<ll> ndp(2, 1e18);
        ndp[0] = min(dp[0] + abs(R[i] - last[0]) + R[i] - L[i], dp[1] + abs(R[i] - last[1]) + R[i] - L[i]);
        ndp[1] = min(dp[0] + abs(last[0] - L[i]) + R[i] - L[i], dp[1] + abs(last[1] - L[i]) + R[i] - L[i]);
        last[0] = L[i];
        last[1] = R[i];
        swap(dp, ndp);
    }
    ll ans = min(dp[0] + abs(last[0]), dp[1] + abs(last[1]));
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}