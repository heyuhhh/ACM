// Author : heyuhhh
// Created Time : 2020/11/09 10:37:26
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
const ll inf = 1e18;
void run() {
    int n;
    cin >> n;
    vector<int> c(n + 40);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    if (sum == 1) {
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                cout << max(1, i) << '\n';
                return;
            }
        }
    }
    auto chk = [&] (int x) {
        ll cnt = c[0] + c[1];
        for (int i = x; i < n + 40; i++) {
            cnt += c[i];
        }
        ll nd = 1;
        for (int i = x - 1; i >= 2; i--) {
            if (c[i] >= nd) {
                cnt += c[i] - nd;
            } else {
                nd = min(inf, 2 * nd - c[i]);
            }
        }
        return cnt >= 2 * nd;
    };
    int l = 2, r = n + 40, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (chk(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
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