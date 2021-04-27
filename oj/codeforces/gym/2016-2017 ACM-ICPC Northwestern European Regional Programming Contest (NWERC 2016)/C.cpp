// Author : heyuhhh
// Created Time : 2021/03/26 13:45:16
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
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    int last = 0;
    long double res = 0;

    for (int i = 1; i <= n; i++) {
        int l, r;
        double f;
        cin >> l >> r >> f;
        res += (l - last);
        res += (long double)f * (r - l);
        last = r;
    }
    res += (y - last);
    long double ans = x / res;
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