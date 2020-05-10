/*
 * Author:  heyuhhh
 * Created Time:  2020/5/9 10:35:10
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
#define INF 0x3f3f3f3f
#define Local
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
const int N = 1000 + 5;

int n;
int c[2], val[2];
int dp[N][N], dp2[N][N];
char s[N], t[N];
int pre[N];

void run() {
    cin >> n >> c[0] >> c[1] >> val[0] >> val[1];
    cin >> (s + 1) >> (t + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
    }
    memset(dp, INF, sizeof(dp));
    memset(dp2, -INF, sizeof(dp2));
    dp[0][0] = dp2[0][0] = 0;
    auto calc = [&] (int i, int j) {
        return val[0] * (pre[i] == j) + val[1] * (i != n && pre[n] - pre[i] == c[1] - j);
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(c[1], i); j++) {
            int v = calc(i, j);
            if (t[i] != '0' && j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + v);
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - 1] + v);
            } 
            if (t[i] != '1') {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + v);
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j] + v);
            }
        }
    }
    int ans0 = dp[n][c[1]], ans1 = dp2[n][c[1]];
    if (pre[n] == c[1]) ans0 += val[1], ans1 += val[1];
    cout << ans0 << ' ' << ans1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
