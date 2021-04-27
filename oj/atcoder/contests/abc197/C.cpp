// Author : heyuhhh
// Created Time : 2021/03/27 20:41:26
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 1e18;
    for (int s = 0; s < 1 << n; s++) {
        ll ss = 0;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            ss |= a[i];
            if (s >> i & 1) {
                res ^= ss;
                ss = 0;
            }
        }
        res ^= ss;
        ans = min(ans, res);
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