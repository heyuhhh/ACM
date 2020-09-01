// Author : heyuhhh
// Created Time : 2020/07/16 15:55:03
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
    int n, r; cin >> n >> r;
    ll ans = 0;
    int t = min(n - 1, r);
    ans += 1ll * t * (t + 1) / 2;
    r -= t;
    if (r > 0) ++ans;
    cout << ans << '\n';
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