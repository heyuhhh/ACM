// Author : heyuhhh
// Created Time : 2021/03/19 16:58:09
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
    int n;
    cin >> n;
    int T = n - 1;
    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++) {
        int f;
        cin >> f;
        --f;
        G[f].emplace_back(i);
    }
    int fz = 0;
    for (int i = 0; i < n; i++) {
        fz += max(0, sz(G[i]) - 1);
    }
    int fm = qpow(T, MOD - 2);
    int ans = 1ll * fz * fm % MOD;
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