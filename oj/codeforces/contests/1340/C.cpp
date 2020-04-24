/*
 * Author:  heyuhhh
 * Created Time:  2020/4/24 9:37:22
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
const int N = 1e4 + 5, M = 1e3 + 5;

int n, m, g, r;
int d[N];
int dp[N][M];

void run() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];   
    }
    sort(d + 1, d + m + 1);
    cin >> g >> r;
    memset(dp, INF, sizeof(dp));
    dp[0][g] = 0;
    deque <pii> q;
    q.push_front(MP(0, g));
    while (!q.empty()) {
        pii now = q.front(); q.pop_front();
        int i = now.fi, j = now.se;
        if (i > 0) {
            int r = d[i] - d[i - 1];
            if (r < j) {
                if (dp[i - 1][j - r] > dp[i][j]) {
                    q.push_front(MP(i - 1, j - r));
                    dp[i - 1][j - r] = dp[i][j];
                }
            } else if (r == j) {
                if (dp[i - 1][g] > dp[i][j] + 1) {
                    q.push_back(MP(i - 1, g));   
                    dp[i - 1][g] = dp[i][j] + 1;
                }
            }
        }
        if (i < m) {
            int r = d[i + 1] - d[i];
            if (r < j) {
                if (dp[i + 1][j - r] > dp[i][j]) {
                    q.push_front(MP(i + 1, j - r));   
                    dp[i + 1][j - r] = dp[i][j];
                }
            } else if (r == j) {
                if (dp[i + 1][g] > dp[i][j] + 1) {
                    q.push_back(MP(i + 1, g));
                    dp[i + 1][g] = dp[i][j] + 1;
                }
            }           
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) {
        if (n - d[i] <= g && dp[i][g] != INF) {
            ans = min(ans, 1ll * dp[i][g] * (g + r) + n - d[i]);
        }
    }
    if(ans == 1e18) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
