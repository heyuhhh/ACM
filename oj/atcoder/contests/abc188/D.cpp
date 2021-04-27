// Author : heyuhhh
// Created Time : 2021/01/10 20:11:55
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
    int n, C;
    cin >> n >> C;
    vector<pii> V;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ++b;
        V.emplace_back(a, c);
        V.emplace_back(b, -c);
    }
    ll tot = 0, last = -1;
    ll ans = 0;
    sort(all(V));
    for (int i = 0; i < sz(V); i++) {
        int x = V[i].fi, c = V[i].se;
        if (last != -1) {
            ans += 1ll * (x - last) * min(tot, (ll)C);
        }
        tot += c;
        last = x;
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