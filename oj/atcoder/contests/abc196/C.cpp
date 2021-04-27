// Author : heyuhhh
// Created Time : 2021/03/20 20:03:48
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
    ll n;
    cin >> n;
    int cnt = 0;
    ll x = n;
    while (x) {
        ++cnt;
        x /= 10;
    }
    x = n;
    if (cnt & 1) {
        ll ans = 0;
        for (int i = 1; i <= cnt / 2; i++) {
            ans = ans * 10 + 9;
        }
        cout << ans << '\n';
        return;
    }
    vector<int> d;
    for (int i = 1; i <= cnt / 2; i++) {
        x /= 10;
    }
    ll p = x;
    ll t = x;
    while (x) {
        d.emplace_back(x % 10);
        x /= 10;
    }
    reverse(all(d));
    for (auto it : d) {
        t = t * 10 + it;
    }
    ll ans = 0;
    if (t <= n) {
        ans = p;
    } else {
        ans = p - 1;
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