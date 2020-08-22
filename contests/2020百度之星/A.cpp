// Author : heyuhhh
// Created Time : 2020/08/09 19:11:20
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
void run() {
    int m, p, q;
    int tmp = qpow(100, MOD - 2);
    cin >> m >> p >> q;
    p = 1ll * p * tmp % MOD;
    q = 1ll * q * tmp % MOD;
    int t = 1ll * q * qpow(p, MOD - 2) % MOD;
    int f1 = (1 + q - t + MOD) % MOD;
    int tt = (1 - t + MOD) % MOD;
    int ans = (f1 + 1ll * (m - 1) * tt % MOD) % MOD;
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