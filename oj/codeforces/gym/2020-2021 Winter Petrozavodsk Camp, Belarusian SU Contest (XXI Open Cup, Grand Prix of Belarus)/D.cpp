// Author : heyuhhh
// Created Time : 2021/02/19 17:00:52
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> last(n, vector<int>(40, -1));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 40; j++) {
            last[i][j] = last[i - 1][j];
        }
        for (int j = 0; j < 40; j++) if (a[i - 1] >> j & 1) {
            last[i][j] = i - 1;
        }
    }
    vector<ll> dp(n, 0);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 40; j++) if (a[i] >> j & 1) {
            int p = last[i][j];
            if (p != -1) {
                dp[i] = max(dp[i], dp[p] + (a[p] & a[i]));
            }
        }
    }
    ll ans = *max_element(all(dp));
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