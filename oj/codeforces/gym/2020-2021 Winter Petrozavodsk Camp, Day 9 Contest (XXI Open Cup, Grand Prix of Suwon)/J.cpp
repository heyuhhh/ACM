// Author : heyuhhh
// Created Time : 2021/03/14 13:02:43
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
const int N = 5e5 + 5;

ll a[N];

void run() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());
    vector<ll> d(n + 1);
    d[1] = INF;
    for (int i = 2; i <= n; i++) {
        d[i] = a[i - 1] - a[i];
    }
    vector<int> lg(n + 1);
    lg[2] = 1;
    for (int i = 3; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    vector<vector<ll>> mn(n + 1, vector<ll>(21, INF));
    for (int i = 1; i <= n; i++) {
        mn[i][0] = d[i];
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j - 1) <= n; i++) {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto query = [&] (int l, int r) {
        int k = lg[r - l + 1];
        return min(mn[l][k], mn[r - (1 << k) + 1][k]);
    };
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
    }
    ll ans = -1;
    int cnt = 0;
    for (int i = 7; i <= n; i++) {
        ll nw = f[i] - f[i - 4] - a[i - 4];
        int id = upper_bound(a + 2, a + i - 4, nw, greater<ll>()) - a;
        if (id >= i - 4) continue;
        int L = id, R = i - 5;
        // cout << L << ' ' << R << ' ' << query(L, R) << '\n';
        if (query(L, R) >= a[i - 4]) continue;
        // cout << i << ' ' << L << ' ' << R << '\n';
        for (int j = L; j <= R; j++) if (j == R || a[j] != a[j + 1]) {
            int id2 = upper_bound(a + 1, a + j, a[j] + a[i - 4], greater<ll>()) - a;
            if (id2 < j) {
                ans = max(ans, a[id2] + a[j] + f[i] - f[i - 5]);
            }
        }
        break;
        // while (id < i - 4) {
        //     int id2 = upper_bound(a + 1, a + id, a[id] + a[i - 4], greater<ll>()) - a;
        //     if (id2 < id) {
        //         ans = max(ans, a[id2] + a[id] + f[i] - f[i - 5]);
        //     }
        //     id = upper_bound(a + 1, a + i - 4, a[id], greater<ll>()) - a;
        // }
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