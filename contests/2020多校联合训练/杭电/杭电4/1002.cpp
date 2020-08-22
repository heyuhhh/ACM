// Author : heyuhhh
// Created Time : 2020/07/30 12:48:55
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
const double eps = 1e-7;
void run() {
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> d[i];
        int nd = (100 + a[i] - 1) / a[i];
        t[i] = (nd - 1) * d[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double res = 0;
        for (int j = 0; j < n; j++) {
            if (fabs(t[i] - t[j]) < eps) {
                res += 0.5;
            } else if (t[i] > t[j] + eps) {
            } else {
                res += 1;
            }
        }
        res /= 1.0 * n;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int T; cin >> T; while(T--)
    run();
    return 0;
}