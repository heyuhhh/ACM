// Author : heyuhhh
// Created Time : 2020/07/14 17:06:09
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
const int N = 2000 + 5;
const double eps = 1e-9;
typedef pair<double, double> pdd;
int n;
struct Point {
    int x, y;
} a[N];
pdd solve(Point a, Point b, Point c) //三点共圆圆心公式
{
    double fm1=2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
    double fm2=2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);
    if (fm1 == 0 || fm2 == 0) {
        return MP(1e18, 1e18);
    }
    double fz1=a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
    double fz2=a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;

    double X = (fz1 * (a.y - c.y) - fz2 * (a.y - b.y)) / fm1;
    double Y = (fz1 * (a.x - c.x) - fz2 * (a.x - b.x)) / fm2;
    return MP(X, Y);
}

bool operator == (pdd A, pdd B) {
    return fabs(A.fi - B.fi) <= eps && fabs(A.se - B.se) <= eps;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    vector<pdd> res;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pdd now = solve({0, 0}, a[i], a[j]);
            if (now == MP(1e18, 1e18)) continue;
            res.push_back(now);
        }
    }
    if (sz(res) == 0) {
        cout << 1 << '\n';
        return;
    }
    sort(all(res));
    int ans = 1, t = 1;
    pdd now = res[0];
    for (int i = 1; i < sz(res); i++) {
        if (res[i] == now) {
            ++t;
        } else {
            ans = max(ans, t);
            now = res[i];
            t = 1;
        }
    }
    ans = max(ans, t);
    for (int i = 2; i <= n; i++) {
        if (i * (i - 1) == 2 * ans) {
            cout << i << '\n';
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}