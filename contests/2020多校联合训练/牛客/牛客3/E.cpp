// Author : heyuhhh
// Created Time : 2020/07/18 13:37:37
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
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 1; i < n; i += 2) {
        ans += a[i] - a[i - 1];
    }
    vector<ll> dp(n);
    dp[0] = -a[0];
    dp[2] = -a[0] - a[1] + a[2];
    for (int i = 4; i < n - 1; i += 2) {
        dp[i] = dp[i - 2] + a[i] - a[i - 1];
        if (i < n - 2) {
            dp[i] = min(dp[i], dp[i - 4] - a[i - 3] + a[i - 2] + a[i - 1] - a[i]);
        }
    }
    ans += dp[n - 2] + a[n - 1]; 
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