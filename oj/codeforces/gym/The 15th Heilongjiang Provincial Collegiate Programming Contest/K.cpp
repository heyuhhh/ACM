// Author : heyuhhh
// Created Time : 2020/11/07 13:49:58
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void run() {
    int n;
    cin >> n;
    vector<int> fac(n + 1), inv(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    auto C = [&] (int n, int m) {
        return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    vector<vector<int>> d(n + 1);
    for (int i = 0; i < n; i++) {
        int dp, x;
        cin >> dp >> x;
        d[dp].emplace_back(x);
    }
    if (sz(d[1]) != 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 2; i < n; i++) {
        if (!sz(d[i]) && sz(d[i + 1])) {
            cout << 0 << '\n';
            return;
        }
    }
    int ans = 1, pre = 1, last = 1;
    for (int i = 2; i <= n; i++) if (sz(d[i])) {
        vector<int>& now = d[i];
        sort(all(now));
        int p1 = sz(now) - 1;
        int res = C(sz(now) + last - 1, last - 1);
        int tmp = 1;
        // cout << res << endl;
        for (int j = pre + sz(d[i]); j > pre; j--) {
            while (p1 >= 0 && now[p1] >= j) --p1;
            res = 1ll * res * (sz(now) - p1 - tmp) % MOD;
            ++tmp;
        }
        if (p1 != -1) {
            cout << 0 << '\n';
            return;
        }
        pre += sz(d[i]);
        last = sz(d[i]);
        // cout << i << ' ' << res << endl;
        ans = 1ll * ans * res % MOD;
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