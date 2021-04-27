// Author : heyuhhh
// Created Time : 2021/02/27 20:56:53
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

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll z = x ;
    x = y;
    y = z - y * (a / b);
} 
// ax + by = c
bool calc(ll a, ll b, ll c, ll& x, ll& y) {
    ll g = __gcd(abs(a), abs(b));
    if(c % g != 0) return false;
    a /= g, b /= g, c /= g;
    exgcd(abs(a), abs(b), x, y);
    x *= c;
    y *= c;
    if (a < 0) x = -x;
    if (b < 0) y = -b;
    return true;
}

void run() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    long long ans = 9e18;
    for (int a = 0; a < y; a++) {
        for (int b = 0; b < q; b++) {
            ll A = 2 * (x + y), B = -(p + q);
            ll C = b - a + p - x;
            ll g = __gcd(abs(A), abs(B));
            // cout << B << ' ' << A << ' ' << C << '\n';
            // x*B+y*A=C
            ll X, Y;
            ll f = calc(B, A, C, X, Y);
            if (!f) continue;
            assert(B * X + A * Y == C);

            ll k = 1e18;
            A /= g, B /= g;
            if (X < 0) {
                k = (-X + abs(A) - 1) / abs(A);
            } else {
                k = -(X / abs(A));
            }

            if (Y < 0) {
                k = max(k, (-Y + abs(B) - 1) / abs(B));
            } else {
                k = min(k, -(Y / abs(B)));
            }

            X += k * A;
            Y -= k * B;

            ans = min(ans, p - X * B + b - 1);
            ans = min(ans, x + Y * A + a - 1);
        }
    }
    if (ans == 9e18) {
        cout << "infinity" << '\n';
    } else {
        cout << ans << '\n';
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