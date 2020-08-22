// Author : heyuhhh
// Created Time : 2020/07/21 13:25:57
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
const int N = 1e5 + 5, MOD = 1e9 + 9;
const int A = 691504013, B = 308495997, sqrt5 = 383008016, inv5 = 276601605;
template <class T>
inline void rd(T& x) {
    x = 0;
    char k = getchar();
    while (k > '9' || k < '0') k = getchar();
    while (k <= '9' && k >= '0') x = x * 10 + k - 48, k = getchar();
}
inline int qpow(ll a, ll b) {
    ll res = 1;
    if (a >= MOD) a %= MOD;
    // if (a > 0) {
    //     b %= (MOD - 1);
    // } else if (b >= MOD - 1) {
    //     b = b % (MOD - 1) + MOD - 1;
    // }
    
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int fac[N], inv[N], tmp[N];
inline void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    tmp[0] = tmp[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        tmp[i] = 1ll * (MOD - MOD / i) * tmp[MOD % i] % MOD;
        inv[i] = 1ll * inv[i - 1] * tmp[i] % MOD;
    }
}

inline int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

ll n, c, k;

inline void run() {
    rd(n), rd(c), rd(k);
    ll ans = 0;
    int cv = qpow(inv5, k);
    int d = qpow(1ll * A * qpow(B, MOD - 2) % MOD, c);
    int b = qpow(qpow(B, k), c);
    int dd = qpow(d, n + 1);
    int bb = qpow(b, n + 1);
    int s1 = 1, s2 = 1;
    for (int i = 0; i <= k; ++i) {
        int res = C(k, i);
        int t = 1ll * b * s1 % MOD;
        if (t == 1) {
            res = 1ll * ((n + 1) % MOD) * res % MOD;
        } else {
            int fm = qpow(t - 1, MOD - 2);
            int fz = 1ll * bb * s2 % MOD - 1 + MOD;
            res = 1ll * res * fz % MOD * fm % MOD;
        }
        if ((k - i) & 1) ans -= res;
        else ans += res;
        s1 = 1ll * s1 * d % MOD;
        s2 = 1ll * s2 * dd % MOD;
    }
    ans = ans % MOD * cv % MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);    
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    init();
    int T; rd(T); while(T--)
    run();
    return 0;
}