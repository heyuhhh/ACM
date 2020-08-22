// Author : heyuhhh
// Created Time : 2020/08/06 13:05:06
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
const int N = 2e5 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int n;
int a[N], ssum[N], sum[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ssum[i] = (ssum[i - 1] + a[i]) % MOD;
        sum[i] = (sum[i - 1] + ssum[i]) % MOD;
    }
    int ans = 0;
    int p = (n + 1) / 2;
    for (int l = 1; l <= n; l++) {
        int res = 0;
        if (l <= p) {
            res = ((ll)sum[n] - sum[n - l] - sum[l - 1] + MOD + MOD) % MOD;
        } else {
            int qq = n - l + 1;
            res = ((ll)sum[n] - sum[n - qq] - sum[qq - 1] + MOD + MOD) % MOD;
        }

        res = 1ll * res * qpow(l, MOD - 2) % MOD;
        ans = (ans + res) % MOD;
    }
    ans = ans * 2 % MOD;
    int fm = qpow(1ll * n * (n + 1) % MOD, MOD - 2);
    ans = 1ll * ans * fm % MOD;
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