// Author : heyuhhh
// Created Time : 2021/03/14 20:02:48
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
    vector<int> p;
    for (int i = 2; i <= 50; i++) {
        bool f = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                f = false;
            }
        }
        if (f) p.emplace_back(i);
    }
    ll ans = 3e18;
    for (int i = 0; i < 1 << (sz(p)); i++) {
        bool f = true;
        ll res = 1;
        for (int j = 0; j < n; j++) {
            bool ok = false;
            for (int k = 0; k < sz(p); k++) if (i >> k & 1) {
                if (a[j] % p[k] == 0) {
                    ok = true;
                }
            }
            f &= ok;
        }
        if (f) {
            for (int k = 0; k < sz(p); k++) if (i >> k & 1) {
                res *= p[k];
            }
            ans = min(ans, res);
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