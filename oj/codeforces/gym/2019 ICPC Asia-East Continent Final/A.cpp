#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

int C[N][N];
void init() {
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    int evenN = (n + 2) / 2;
    int oddN = n + 1 - evenN;
    int evenM = (m + 2) / 2;
    int oddM = m + 1 - evenM;

    // cout << C[evenN][2] << ' ' << C[oddN][2] << '\n';

    ll ans = (C[evenM][2] + C[oddM][2]) * (n + 1) + (C[evenN][2] + C[oddN][2]) * (m + 1);
    ans += 2ll * (C[evenM][2] + C[oddM][2]) * (C[evenN][2] + C[oddN][2]);

    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    run();
    return 0;
}