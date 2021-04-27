#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;
    int sr = 0, sc = 0;
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        sr |= (1 << r[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        sc |= (1 << c[i]);
    }
    int ans = 0;
    for (int s = 0; s < 1 << 4; s++) {
        int nr = 0, nc = 0;
        for (int i = 0; i < 4; i++) if (s >> i & 1) {
            int rows = i / 2, cols = i % 2;
            nr |= (1 << rows);
            nc |= (1 << cols);
        }
        if (nr == sr && nc == sc) {
            ++ans;
        }
    }
    cout << ans << '\n';
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