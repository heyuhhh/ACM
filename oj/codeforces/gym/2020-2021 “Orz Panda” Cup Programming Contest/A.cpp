// Author : heyuhhh
// Created Time : 2021/03/19 13:03:53
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
    vector<int> h(n + 2), w(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1] >> w[i + 1];
    }
    vector<int> sta;
    vector<int> r(n + 1);
    for (int i = 1; i <= n + 1; i++) {
        while (sz(sta) && h[i] < h[sta.back()]) {
            r[sta.back()] = i - 1;
            sta.pop_back();
        }
        sta.emplace_back(i);
    }
    while (!sta.empty()) sta.pop_back();
    vector<int> l(n + 1);
    for (int i = n; i >= 0; i--) {
        while (sz(sta) && h[i] < h[sta.back()]) {
            l[sta.back()] = i + 1;
            sta.pop_back();
        }
        sta.emplace_back(i);
    }
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + w[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1ll * h[i] * (sum[r[i]] - sum[l[i] - 1]));
        // cout << i << ' ' << l[i] << ' ' << r[i] << '\n';
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
    run();
    return 0;
}