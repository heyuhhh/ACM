#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5 ;
int n;
ll a[2][N], sum123[2][N], sum321[2][N], sum[2][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = n; j >= 1; j--) {
            sum[i][j] = sum[i][j + 1] + a[i][j];
            sum123[i][j] = sum123[i][j + 1] + (ll)(j - 1) * a[i][j];
            sum321[i][j] = sum321[i][j + 1] + (ll)(n + n - j) * a[i][j];
        }
    }
    ll S = 0, ans = 0, Sum = 0, now = 0;
    ll cnt = 1, cur = 0;
    for(ll j = 1; j <= n; j++) {
        Sum += sum123[cur][j + 1] + (j - 1) * sum[cur][j + 1];
        Sum += sum321[cur ^ 1][j] + (j - 1) * sum[cur ^ 1][j];
        ans = max(ans, Sum);
        now += a[cur ^ 1][j] * cnt; cnt++;
        now += a[cur ^ 1][j + 1] * cnt; cnt++;
        Sum = now;
        cur ^= 1;
    }
    cout << ans;
    return 0;
}
