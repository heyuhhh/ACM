#include <bits/stdc++.h>
using namespace std;


void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 100;
    int res = 100;
    bool f = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    // int T; cin >> T; while (T--) 
    run();
    return 0;
}