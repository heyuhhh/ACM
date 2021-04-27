// Author : heyuhhh
// Created Time : 2021/01/10 20:46:13
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
    ll x, y;
    cin >> x >> y;
    if (x >= y) {
        cout << x - y << '\n';
        return;
    }
    ll t = 0;
    while (2ll * x <= y) {
        ++t;
        x <<= 1;
    }
    ll d = y - x;
    ll tmp = 0;
    for (int i = 62; i >= t; i--) if (d >> i & 1) {
        tmp += (1ll << (i - t));
    }
    int cnt = 0;
    for (int i = t - 1; i >= 0; i--) {
        if (d >> i & 1) {
            ++cnt;
        } else {
            if (cnt == 1) ++tmp;
            else if (cnt >= 2) tmp += 2;
            cnt = 0;
        }
    }
    if (cnt == 1) ++tmp;
    if (cnt >= 2) tmp += 2;
    ll ans = t + tmp;
    
    ++t;
    x <<= 1;
    d = x - y;
    tmp = 0;
    for (int i = 62; i >= t; i--) if (d >> i & 1) {
        tmp += (1ll << (i - t));
    }
    cnt = 0;
    for (int i = t - 1; i >= 0; i--) {
        if (d >> i & 1) {
            ++cnt;
        } else {
            if (cnt == 1) ++tmp;
            else if (cnt >= 2) tmp += 2;
            cnt = 0;
        }
    }
    if (cnt == 1) ++tmp;
    if (cnt >= 2) tmp += 2;
    ans = min(ans, t + tmp);
    
    cout << ans << endl;
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