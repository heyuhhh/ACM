// Author : heyuhhh
// Created Time : 2020/09/15 00:14:40
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
const int N = 2e5 + 5, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    vector<ll> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = (pre[i - 1] + a[i]) % MOD;
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) 
        suf[i] = (suf[i + 1] + a[i]) % MOD;

    for (int i = 0; i < m; i++) {
        int A, B;
        cin >> A >> B;
        int t = lower_bound(all(a), B) - a.begin();
        int tot = n - t;
        if (tot < A) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1ll * (1 - 1ll * A * qpow(tot, MOD - 2) % MOD + MOD) % MOD * suf[t] % MOD;
        if (t) {
            ans = (ans + 1ll * pre[t - 1] * (1 - 1ll * A * qpow(tot + 1, MOD - 2) % MOD + MOD) % MOD) % MOD;
        }
        cout << ans << '\n';
    }
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