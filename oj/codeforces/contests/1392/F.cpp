// Author : heyuhhh
// Created Time : 2020/08/22 17:26:01
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
const int N = 1e5 + 5;
void run() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll tot = 0;
    auto ok = [&] (ll x, int i) {
        return 1ll * (n - i) * x + tot <= sum && sum <= 1ll * (2 * x + n - i - 1) * (n - i) / 2 + tot;
    };
    auto ok2 = [&] (ll x) {
        return sum <= 1ll * (2 * x + n - 1) * n / 2;
    };
    ll l = 0, r = 1e12 + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (ok2(mid)) r = mid;
        else l = mid + 1;
    }
    ll x = r;
    for (int i = 0; i < n; i++) {
        while (!ok(x, i)) ++x;
        tot += x;
        cout << x;
        if (i != n - 1) cout << ' ';
        else cout << '\n';
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