// Author : heyuhhh
// Created Time : 2021/03/12 12:08:37
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
    ll m;
    cin >> n >> m;
    int t = m;
    vector<int> a(n), b(n);
    vector<pii> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        b[i] = min(b[i], t);
        if (b[i] - a[i] >= 0) {
            m += b[i] - a[i];
        } else {
            c.emplace_back(a[i], b[i]);
        }
    }
    c.emplace_back(0, 0);
    sort(all(c), [&] (pii A, pii B) {
        return A.se > B.se;
    });
    for (auto& it : c) {
        if (m - it.fi >= 0) {
            m = m - it.fi + it.se;
        } else {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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