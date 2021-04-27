// Author : heyuhhh
// Created Time : 2020/10/03 20:29:25
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> l(2 * n), r(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        if (a[i] >= 0) l[a[i]].emplace_back(b[i]);
        if (b[i] >= 0) r[b[i]].emplace_back(a[i]);
    }


    vector<int> cnt(2 * n);
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && b[i] >= 0 && a[i] > b[i]) {
            cout << "No" << '\n';
            return;
        }
        if (a[i] >= 0) ++cnt[a[i]];
        if (b[i] >= 0) ++cnt[b[i]];
    }
    for (int i = 0; i < 2 * n; i++) {
        if (cnt[i] > 1) {
            cout << "No" << '\n';
            return;
        }
    }

    auto check = [&] (int L, int R) {
        int m = (L + R) >> 1;
        int len = m - L + 1;
        for (int i = L; i <= m; i++) {
            for (auto j : l[i]) {
                if (j >= 0 && j != i + len) return false;
                if (j < 0 && sz(r[i + len]) && r[i + len][0] != i) return false;
            }
            if (sz(r[i])) return false;
        }
        for (int i = m + 1; i <= R; i++) {
            for (auto j : r[i]) {
                if (j >= 0 && j != i - len) return false;
                if (j < 0 && sz(l[i - len]) && l[i - len][0] != i) return false;
            }
            if (sz(l[i])) return false;
        }
        return true;
    };
    vector<vector<bool>> ok(2 * n, vector<bool>(2 * n));
    for (int l = 0; l < 2 * n; l++) {
        for (int r = l; r < 2 * n; r++) if ((r - l + 1) % 2 == 0) {
            ok[l][r] = check(l, r);
            // cout << l << ' ' << r << ' ' << ok[l][r] << '\n';
        }
    }
    vector<bool> dp(2 * n + 1);
    dp[0] = true;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= i; j++) {
            if ((i - j + 1) % 2 == 0) {
                dp[i] = (dp[i] | (dp[j - 1] & ok[j - 1][i - 1]));
            }
        }
    }
    if (dp[2 * n]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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