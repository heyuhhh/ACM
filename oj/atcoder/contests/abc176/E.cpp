// Author : heyuhhh
// Created Time : 2020/08/22 20:42:04
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row(n);
    vector<int> col(m);
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
        ++row[x[i]], ++col[y[i]];
    }
    int ans = 0;
    int cntr = 0, cntc = 0;
    ll tot = 0;
    int maxr = *max_element(all(row)), maxc = *max_element(all(col));
    for (int i = 0; i < n; i++) {
        if (maxr == row[i]) ++cntr;
    }
    for (int j = 0; j < m; j++) {
        if (maxc == col[j]) ++cntc;
    }
    for (int i = 0; i < k; i++) {
        ans = max(ans, row[x[i]] + col[y[i]] - 1);
        if (row[x[i]] == maxr && col[y[i]] == maxc) {
            ++tot;
        }
    }
    if (tot != 1ll * cntr * cntc) {
        ans = maxr + maxc;
    }
    cout << ans << '\n';
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