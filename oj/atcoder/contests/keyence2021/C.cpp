// Author : heyuhhh
// Created Time : 2021/01/16 20:18:55
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
const int N = 5000 + 5, MOD = 998244353;

int pow3[N];
int a[N][N];
int cntX[N][N], cntY[N][N], dp[N][N][3];
int h, w, k;
inline int calc(int x, int y, int nd) {
    if (x >= h || y >= w) return 0;
    if (a[x][y] >= 0 && a[x][y] != nd) return 0;
    return dp[x][y][nd];
}
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
void run() {
    memset(a, -1, sizeof(a));
    scanf("%d%d%d", &h, &w, &k);
    pow3[0] = 1;
    for (int i = 1; i < 5001; i++) {
        pow3[i] = 1ll * pow3[i - 1] * 3 % MOD;
    }
    vector<vector<int>> atX(h), atY(w);
    for (int i = 0; i < k; i++) {
        int x, y;
        char op;
        scanf("%d %d %c", &x, &y, &op);
        --x, --y;
        if (op == 'X') a[x][y] = 0;
        if (op == 'R') a[x][y] = 1;
        if (op == 'D') a[x][y] = 2;
        atX[x].emplace_back(y);
        atY[y].emplace_back(x);
    }
    for (int i = 0; i < h; i++) sort(all(atX[i]));
    for (int i = 0; i < w; i++) sort(all(atY[i]));
    
    auto findY = [&] (int x, int y) {
        auto p = upper_bound(all(atY[y]), x) - atY[y].begin();
        return h - x - 1 - sz(atY[y]) + p;
    };
    auto findX = [&] (int x, int y) {
        auto p = upper_bound(all(atX[x]), y) - atX[x].begin();
        return w - y - 1 - sz(atX[x]) + p;
    };
    for (int i = 0; i < h; i++) {
        int has = 0;
        for (int j = w - 1; j >= 0; j--) {
            if (sz(atX[i]) && atX[i].back() > j) {
                ++has;
                atX[i].pop_back();
            }
            cntX[i][j] = pow3[w - 1 - j - has];
        }
    }
    for (int j = 0; j < w; j++) {
        int has = 0;
        for (int i = h - 1; i >= 0; i--) {
            if (sz(atY[j]) && atY[j].back() > i) {
                ++has;
                atY[j].pop_back();
            }
            cntY[i][j] = pow3[h - 1 - i - has];
        }
    }
    
    if (a[h - 1][w - 1] == -1) {
        for (int i = 0; i < 3; i++) dp[h - 1][w - 1][i] = 1;
    } else {
        dp[h - 1][w - 1][a[h - 1][w - 1]] = 1;
    } 
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (i == h - 1 && j == w - 1) continue;
            if (a[i][j] == 0) {
                if (i + 1 < h) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][0] = add(dp[i][j][0], 1ll * calc(i + 1, j, t) * cntX[i][j] % MOD);
                    }
                }
                if (j + 1 < w) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][0] = add(dp[i][j][0], 1ll * calc(i, j + 1, t) * cntY[i][j] % MOD);
                    }
                }
            } else if (a[i][j] == 2) {
                if (i + 1 < h) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][2] = add(dp[i][j][2], 1ll * calc(i + 1, j, t) * cntX[i][j] % MOD);
                    }
                }
            } else if (a[i][j] == 1) {
                if (j + 1 < w) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][1] = add(dp[i][j][1], 1ll * calc(i, j + 1, t) * cntY[i][j] % MOD);
                    }
                }
            } else {
                if (i + 1 < h) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][0] = add(dp[i][j][0], 2ll * calc(i + 1, j, t) * cntX[i][j] % MOD);
                    }
                }
                if (j + 1 < w) {
                    for (int t = 0; t < 3; t++) {
                        dp[i][j][0] = add(dp[i][j][0], 2ll * calc(i, j + 1, t) * cntY[i][j] % MOD);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = add(ans, dp[0][0][i]);
    }
    printf("%d", ans);
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    run();
    return 0;
}