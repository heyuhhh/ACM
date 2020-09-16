// Author : heyuhhh
// Created Time : 2020/09/13 21:02:47
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
    vector<int> x(n), y(n);
    vector<int> a(4, -2000000000);
    vector<int> b(4, 2000000000);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        a[0] = max(a[0], x[i] + y[i]);
        b[0] = min(b[0], x[i] + y[i]);

        a[1] = max(a[1], x[i] - y[i]);
        b[1] = min(b[1], x[i] - y[i]);

        a[2] = max(a[2], -x[i] + y[i]);
        b[2] = min(b[2], -x[i] + y[i]);

        a[3] = max(a[3], -x[i] - y[i]);
        b[3] = min(b[3], -x[i] - y[i]);
    }
    int ans = -2000000000;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, a[i] - b[i]);
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