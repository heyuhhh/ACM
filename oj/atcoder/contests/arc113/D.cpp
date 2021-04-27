// Author : heyuhhh
// Created Time : 2021/02/21 20:51:15
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
void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void run() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int tmp;
        if (n > 1) {
            tmp = 1ll * (qpow(i, n) - qpow(i - 1, n) + MOD) % MOD * (m == 1 ? m : qpow(k - i + 1, m)) % MOD; 
        } else {
            tmp = (qpow(k - i + 1, m) - qpow(k - i, m) + MOD) % MOD;
        }
        add(ans, tmp);
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