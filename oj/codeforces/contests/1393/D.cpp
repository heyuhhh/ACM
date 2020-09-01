// Author : heyuhhh
// Created Time : 2020/08/21 11:41:06
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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> up(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) up[i][j] = 1;
            else {
                if (a[i][j] == a[i - 1][j]) up[i][j] = up[i - 1][j] + 1;
                else up[i][j] = 1;
            }
        }
    }
    vector<vector<int>> down(n, vector<int>(m));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1) down[i][j] = 1;
            else {
                if (a[i][j] == a[i + 1][j]) down[i][j] = down[i + 1][j] + 1;
                else down[i][j] = 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> L(m);
        for (int j = 0, k; j < m; j = k) {
            k = j;
            while (k < m && a[i][k] == a[i][j]) ++k;
            L[j] = 1;
            for (int p = j + 1; p < k; p++) {
                L[p] = min(L[p - 1] + 1, min(up[i][p], down[i][p]));
            }
        }
        vector<int> R(m);
        for (int j = m - 1, k; j >= 0; j = k) {
            k = j;
            while (k >= 0 && a[i][k] == a[i][j]) --k;
            R[j] = 1;
            for (int p = j - 1; p > k; p--) {
                R[p] = min(R[p + 1] + 1, min(up[i][p], down[i][p]));
            }
        }
        for (int j = 0; j < m; j++) {
            ans += min(L[j], R[j]);
        }
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