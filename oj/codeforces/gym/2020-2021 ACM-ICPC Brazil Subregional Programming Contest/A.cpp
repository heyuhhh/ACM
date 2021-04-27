#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<double> f(n + b);
    vector<double> sum(n + b);

    auto calc = [&] (int l, int r) {
        if (r >= n) r = n - 1;
        if (l <= 0) l = 1;
        if (l > r) return 0.0;
        return sum[r] - sum[l - 1];
    };

    double P = 1.0 / (b - a + 1);

    for (int i = 1; i < n + b; i++) {
        if (a == 0) {
            f[i] = (P * calc(i - b, i - a - 1) + 1) / (1.0 - P);
        } else {
            f[i] = P * calc(i - b, i - a) + 1;
        }
        sum[i] = sum[i - 1] + f[i];
    }
    cout << f[n] << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    // int T; cin >> T; while (T--) 
    run();
    return 0;
}