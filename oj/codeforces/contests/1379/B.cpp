// Author : heyuhhh
// Created Time : 2020/07/19 17:15:25
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
    int l, r;
    ll m;
    cin >> l >> r >> m;
    ll L = m - (r - l), R = m + r - l;
    for (int i = l; i <= r; i++) {
        if (R < i) continue;
        ll t = R / i * i;
        if (t < L) continue;
        ll d = m - t;
        ll a = i, b, c;
        if (d < 0) {
            d = -d;
            c = r;
            b = r - d;
        } else {
            c = r - d;
            b = r;
        }
        assert(l <= b && b <= r);
        assert(l <= c && c <= r);
        cout << a << ' ' << b << ' ' << c << '\n';
        return;
    }
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