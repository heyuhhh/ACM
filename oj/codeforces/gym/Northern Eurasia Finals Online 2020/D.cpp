// Author : heyuhhh
// Created Time : 2021/02/28 11:43:33
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m = (1 << 8);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<int>> ok(n, vector<int>(8, -1));
    auto can = [&] (int i, int j) {
        if (i + j + 1 >= n) return 0;
        if (ok[i][j] != -1) return ok[i][j];
        int all = 0;
        for (int k = 0; k < 8; k++) {
            bool f = true;
            if (s[i][k] != s[i + j + 1][k]) {
                f = false;
            }
            all += f;
        }
        return ok[i][j] = (j + 1 <= all);
    };
    function<int(int, int)> solve = [&] (int i, int s) {
        if (i < 0) return s & 1;
        if (dp[i][s] != -1) return dp[i][s];
        for (int j = 0; j < 8; j++) if(!(s >> j & 1) && can(i, j)) {
            return dp[i][s] = solve(i - 1, ((s << 1) | 1) & (m - 1));
        }
        return dp[i][s] = solve(i - 1, ((s << 1) & (m - 1)));
    };
    for (int i = 0; i < n; i++) {
        int r = solve(i - 1, (m - 1) ^ 1);
        if (r) {
            cout << 1;
        } else {
            cout << 2;
        }
    }
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