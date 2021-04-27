// Author : heyuhhh
// Created Time : 2021/02/06 20:33:40
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

ll myceil(ll x) {
    return x < 0 ? x / 10000 * 10000 : (x + 9999) / 10000 * 10000;
}

ll myfloor(ll x) {
    return x < 0 ? (x - 9999) / 10000 * 10000 : x / 10000 * 10000;
}

ll mysqrt(ll x) {
    ll nw = sqrt(x + 0.5);
    while (nw * nw > x) --nw;
    while ((nw + 1) * (nw + 1) <= x) ++nw;
    return nw;
}

void run() {
    long double X, Y, R;
    cin >> X >> Y >> R;
    ll x = llroundl(X * 10000);
    ll y = llroundl(Y * 10000);
    ll r = llroundl(R * 10000);
    ll ans = 0;
    for (ll i = myceil(x - r); i <= myfloor(x + r); i += 10000) {
        // (x-X)^2+(y-Y)^2=R^2
        ll yy = mysqrt((r + x - i) * (r - x + i));
        ll up = myfloor(yy + y) / 10000;
        ll down = myceil(-yy + y) / 10000;
        ans += up - down + 1;
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