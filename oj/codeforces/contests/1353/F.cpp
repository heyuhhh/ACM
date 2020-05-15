/*
 * Author:  heyuhhh
 * Created Time:  2020/5/14 22:53:49
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f3f3f3f3f
//#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 100 + 5;

int n, m;
ll a[N][N], dp[N][N];

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    auto calc = [&](int sx, int sy, int ex, int ey, int op) {
        int x, y;
        if (op == 0) x = ex, y = ey;
        else x = sx, y = sy;
        ll res = 0;
        for (int i = sx; i <= ex; i++) {
            for (int j = sy; j <= ey; j++) {
                int d = abs(x - i) + abs(y - j);
                if (op == 0) {
                    if (a[i][j] >= a[x][y] - d) {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - a[x][y] + d;
                    }
                } else {
                    if (a[i][j] >= a[x][y] + d) {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - a[x][y] - d;
                    }
                }
            }
        }
        return 0;
    };
    ll res = INF;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    dp[i][j] = INF;
                }
            }
            dp[1][0] = 0;
            calc(1, 1, x, y, 0);
            calc(x, y, n, m, 1);
            res = min(res, dp[n][m]);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
