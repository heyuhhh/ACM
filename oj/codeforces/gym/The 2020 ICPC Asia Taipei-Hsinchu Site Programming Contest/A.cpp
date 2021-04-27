#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;
    // 2a >= b
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        int x = i, y = n / i;
        if (2 * x >= y) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T; while (T--)
    run();
    return 0;
}