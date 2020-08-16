// Author : heyuhhh
// Created Time : 2020/08/15 14:00:57
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
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> L(n, m), R(n, -1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        L[x] = min(L[x], y);
        R[x] = max(R[x], y);
    }
    vector<vector<int>> sc(m), ec(m);
    int all = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (R[i] != -1) {
            sc[L[i]].push_back(i);
            ec[R[i]].push_back(i);
            ++all;
            res += 2 * R[i];
        }
    }

    int up = 0, down = all;
    ll ans = res;
    
    for (int i = 0; i < m; i++) {
        down -= sz(sc[i]);
        up += sz(ec[i]);
        res += 2 * up - 2 * down;
        ans = min(ans, res);
    }
    ans += n - 1;
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