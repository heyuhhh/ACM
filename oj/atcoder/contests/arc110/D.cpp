// Author : heyuhhh
// Created Time : 2020/12/06 22:17:15
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
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int C(int n, int m) {
    int res = 1;
    for (int i = n - m + 1; i <= n; i++) {
        res = 1ll * res * i % MOD;
    }
    for (int i = 1; i <= m; i++) {
        res = 1ll * res * qpow(i, MOD - 2) % MOD;
    }
    return res;
}

void run() {
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    cout << C(m + n, s + n) << '\n';
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