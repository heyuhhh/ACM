// Author : heyuhhh
// Created Time : 2021/02/19 13:51:56
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
const int N = 1e5 + 5, MOD = 998244353;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
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
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void dec(int& x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}
void run() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << '\n';
        return;
    }
    if (n == 2) {
        cout << 1 << '\n';
        return; 
    }
    int ans = 1;
    for (int i = 1; i < n; i += 2) {
        ans = 1ll * ans * i % MOD;
    }
    int m = n / 2;
    ans = 1ll * ans * qpow(4, m - 1) % MOD * qpow(m, m - 2) % MOD;
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
    run();
    return 0;
}