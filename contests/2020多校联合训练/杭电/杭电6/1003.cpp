// Author : heyuhhh
// Created Time : 2020/08/07 20:33:27
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
const int N = 1e6 + 5, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int fac[N], inv[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}
int C(int n, int m) {
    if (n < m) return 0;
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void run() {
    vector<int> a(3);
    int sum = 0;
    int k;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << -1 << '\n';
        return;
    }
    
    sort(all(a));
    k = sum / 3;
    if (a[1] >= k) {
        cout << 2 * (k - a[0]) << '\n';
        return;
    }
    int d1 = k - a[0], d2 = k - a[1];
    int ans = 0;
    int inv2 = qpow(2, MOD - 2);
    int tt = inv2;
    for (int i = 1, res; i < d1 + d2; i++) {
        res = 1ll * tt * C(i - 1, d1 - 1) % MOD * (i + 2 * (d1 + d2 - i)) % MOD;
        ans = (ans + res) % MOD;
        res = 1ll * tt * C(i - 1, d2 - 1) % MOD * (i + 2 * (d1 + d2 - i)) % MOD;
        ans = (ans + res) % MOD;
        tt = 1ll * tt * inv2 % MOD;
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
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}