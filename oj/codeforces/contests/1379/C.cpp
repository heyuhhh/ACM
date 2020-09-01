// Author : heyuhhh
// Created Time : 2020/07/19 17:58:39
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    if (n == 1) {
        int ans = *max_element(all(a));
        cout << ans << '\n';
        return;
    }
    vector<int> c = a;
    sort(all(c));
    vector<ll> sum(m);
    sum[0] = c[0];
    for (int i = 1; i < m; i++) {
        sum[i] = sum[i - 1] + c[i];
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int t = upper_bound(all(c), b[i]) - c.begin();
        t = max(t, m - n);
        ll res = sum[m - 1] - (t > 0 ? sum[t - 1] : 0);
        int x = n - (m - t);
        if (x <= 0) {
            ans = max(ans, res);
            continue;
        }
        if (a[i] <= b[i]) {
            --x;
            res += a[i];
        }
        res += 1ll * x * b[i];
        ans = max(ans, res);
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