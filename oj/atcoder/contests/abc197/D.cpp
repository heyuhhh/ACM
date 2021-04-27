// Author : heyuhhh
// Created Time : 2021/03/27 20:39:35
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
const double pi = 3.1415926;
void run() {
    int n;
    cin >> n;
    vector<double> x(2), y(2);
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    double mx = 1.0 * (x[0] + x[1]) / 2;
    double my = 1.0 * (y[0] + y[1]) / 2;

    double a = 1.0 * (n - 2) * 90 / n;
    double delta = 180 - 2 * a;
    x[0] -= mx;
    y[0] -= my;
    double ansx = x[0] * cos(delta * pi / 180) - y[0] * sin(delta * pi / 180);
    double ansy = y[0] * cos(delta * pi / 180) + x[0] * sin(delta * pi / 180);
    ansx += mx, ansy += my;
    cout << ansx << ' ' << ansy << '\n';
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