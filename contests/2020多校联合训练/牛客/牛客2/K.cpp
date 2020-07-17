// Author : heyuhhh
// Created Time : 2020/07/15 11:11:44
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
const double pi = acos(-1.0);
vector<double> Sin(500), Cos(500);
void init() {
    for (int i = 0; i < 500; i++) {
        double a = 2.0 * pi * i / 500;
        Sin[i] = sin(a);
        Cos[i] = cos(a);
    }
}
void run() {
    vector<int> r(3);
    for (int i = 0; i < 3; i++) {
        cin >> r[i];
    }
    sort(all(r));
    double ans = 0;
    for (int i = 0; i < 500; i++) {
        double a = 2.0 * pi * i / 500;
        double x2 = r[1] * Cos[i], y2 = r[1] * Sin[i];
        for (int j = 0; j < 500; j++) {
            double b = 2.0 * pi * j / 500;
            double x3 = r[2] * Cos[j], y3 = r[2] * Sin[j];
            ans += fabs((x2 - r[0]) * y3 - (x3 - r[0]) * y2);
        }
    }
    ans = ans / 500 / 500 / 2;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}