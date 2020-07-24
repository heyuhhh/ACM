// Author : heyuhhh
// Created Time : 2020/07/18 21:11:26
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
    int n = 20;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0], y[n] = y[0];
    auto sq = [&] (double t) {
        return t * t;
    };
    vector<double> d(n);
    double tot = 0;
    for (int i = 0; i < n; i++) {
        d[i] = sqrt(sq(x[i + 1] - x[i]) + sq(y[i + 1] - y[i]) + 0.5);
        tot += x[i] * y[i + 1] - x[i + 1] * y[i];
    }
    if (tot < 0) {
        reverse(all(d));
    }
    int a, b;
    for (int i = 0; i < n; i++) {
        if ((int)(d[i] + 0.5) == 6) a = i;
        if ((int)(d[i] + 0.5) == 8) b = i;
    }
    if ((a + 2) % n == b) {
        cout << "right" << '\n';
    } else {
        cout << "left" << '\n';
    }
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