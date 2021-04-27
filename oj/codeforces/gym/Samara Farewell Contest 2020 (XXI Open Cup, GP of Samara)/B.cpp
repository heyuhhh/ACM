// Author : heyuhhh
// Created Time : 2021/03/09 14:09:07
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
const double eps = 1e-10;
void run() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    auto check = [&] (double x) {
        long double res = 0;
        for (int i = 0; i < n; i++) {
            res += max(b[i] - a[i] * x, d[i] - c[i] * x);
        }
        return res >= 0;
    };
    long double l = 0, r = 1e29, mid;
    while (r - l >= eps) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
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