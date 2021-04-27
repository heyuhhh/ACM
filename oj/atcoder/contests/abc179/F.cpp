// Author : heyuhhh
// Created Time : 2020/09/23 21:59:14
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
    int n, q;
    cin >> n >> q;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        r[i] = c[i] = n;
    }
    int H, W;
    H = W = n;
    ll ans = 1ll * (n - 2) * (n - 2);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            if (x >= W) {
                ans -= c[x - 1] - 2;
            } else {
                ans -= H - 2;
                for (int i = x; i < W; i++) {
                    c[i] = H;
                }
                W = x;
            }
        } else {
            if (x >= H) {
                ans -= r[x - 1] - 2;
            } else {
                ans -= W - 2;
                for (int i = x; i < H; i++) {
                    r[i] = W;
                }    
                H = x;
            }
        }
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