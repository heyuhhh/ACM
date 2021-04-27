// Author : heyuhhh
// Created Time : 2021/03/12 10:49:35
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
    int cnt = 0;
    vector<int> days;
    ll ans = 0, p = 0;
    ll all_p = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        all_p += a;
        if (b == 0) ++cnt;
        else {
            days.emplace_back(a - b + 1);
            p += a;
        }
    }
    sort(all(days));
    reverse(all(days));
    if (cnt == 0) {
        ans = min(days[1] + 1, days[0]);
    } else {
        ans = days[0] + (cnt == 1);
        if (cnt == 1) p = all_p;
    }
    cout << ans << ' ' << p << '\n';
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