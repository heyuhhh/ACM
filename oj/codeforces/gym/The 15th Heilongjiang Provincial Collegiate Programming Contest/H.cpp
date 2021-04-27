// Author : heyuhhh
// Created Time : 2020/11/07 14:45:51
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
//head
const int N = 10;

ll sum(ll n, int k) {
    if (k == 0) return n;
    if (k == 1) {
        if (n % 2 == 0) return n / 2 * (n + 1);
        else return (n + 1) / 2 * n;
    }
    if (k == 2) {
        ll a = n, b = n + 1, c = 2 * n + 1;
        if (a % 3 == 0) a /= 3;
        else if (b % 3 == 0) b /= 3;
        else c /= 3;
        if (a % 2 == 0) a /= 2;
        else if (b % 2 == 0) b /= 2;
        else c /= 2;
        return a * b * c;
    }
    if (k == 3) {
        ll a = n, b = n + 1;
        if (a % 2 == 0) a /= 2;
        else b /= 2;
        return a * a * b * b;
    }
}

ll calc(ll n, int k) {
    ll res = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = min(n / (n / l), n);
        res += (sum(r, k) - sum(l - 1, k)) * (n / l);
        // cout << res << endl;
    }
    return res;
}

void run() {
    int a, b;
    ll n;
    cin >> a >> b >> n;
    ll res1 = calc(n, a), res2 = calc(n, b);
    // cout << res1 << ' ' << res2 << endl;
    ll res = (res1 ^ res2);
    cout << res << '\n';
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