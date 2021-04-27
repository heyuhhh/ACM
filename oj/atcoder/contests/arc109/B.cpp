// Author : heyuhhh
// Created Time : 2020/12/04 15:20:41
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
    ll l = 1, r = n + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if ((__int128)mid * (mid + 1) / 2 <= (__int128)n + 1) l = mid + 1;
        else r = mid;
    }
    ll ans = n - (l - 1) + 1;
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