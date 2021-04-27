// Author : heyuhhh
// Created Time : 2021/03/26 13:21:57
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
    string s, t;
    cin >> s >> t;
    auto calc = [&] (string& S) {
        ll l = 0, r = (1ll << n);
        bool rev = 0;
        for (int i = 0; i < n; i++) {
            ll m = (l + r) >> 1;
            if (S[i] == '1') {
                if (!rev) l = m;
                else r = m;
                rev ^= 1;
            } else {
                if (rev) l = m;
                else r = m;
            }
            // cout << l << ' ' << r << endl;
        }
        return l;
    };
    ll ans = calc(t) - calc(s) - 1;
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