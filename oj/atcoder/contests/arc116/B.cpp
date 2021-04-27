// Author : heyuhhh
// Created Time : 2021/03/28 20:09:24
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
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> sum(n);
    int ans = mul(a[0], a[0]);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        ans = add(ans, mul(a[i], mul(qpow(2, i - 1), sum[i - 1])));
        sum[i] = add(sum[i - 1], mul(a[i], qpow(qpow(2, i), MOD - 2)));
        ans = add(ans, mul(a[i], a[i]));
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