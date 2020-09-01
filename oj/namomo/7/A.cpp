// Author : heyuhhh
// Created Time : 2020/08/29 19:00:42
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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    double ans = 1.0 * (n - m) / (x + y);
    if (x != y) {
        if (y > x) 
            ans = min(ans, 1.0 * m / (y - x));
        else 
            ans = min(ans, 1.0 * (n - m) / (x - y));
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}