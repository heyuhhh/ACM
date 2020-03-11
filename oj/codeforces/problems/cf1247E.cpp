/*
 * Author:  heyuhhh
 * Created Time:  2020/3/6 16:56:08
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
const int N = 2000 + 5, MOD = 1e9 + 7;

int n, m;
char s[N][N];
int col[N][N], row[N][N];
int dp[N][N][2];
int sumc[N][N], sumr[N][N];

void add(int &x, int y) {
    if(y < 0) y += MOD;
    if(y >= MOD) y -= MOD;
    x += y;
    if(x >= MOD) x -= MOD;   
}

void run() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> (s[i] + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            row[i][j] = row[i][j + 1] + (s[i][j] == 'R');
        }
        sort(row[i] + 1, row[i] + m + 1);
    }
    for(int j = 1; j <= m; j++) {
        for(int i = n; i >= 1; i--) {
            col[j][i] = col[j][i + 1] + (s[i][j] == 'R');
        }
        sort(col[j] + 1, col[j] + n + 1);
    }
    dp[1][1][0] = 1;
    sumr[1][1] = sumc[1][1] = 1;
    for(int j = 2; j <= m - row[1][m]; j++) {
        dp[1][j][0] = 1;
        sumc[1][j] = 1;
    }
    for(int i = 2; i <= n - col[1][n]; i++) {
        dp[i][1][1] = 1;
        sumr[i][1] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            int p = lower_bound(col[j] + n - i + 2, col[j] + n + 1, n - i + 1) - col[j];
            p = n - p + 1;
            if(col[j][n - i + 1] != n - i + 1) add(dp[i][j][1], sumc[i - 1][j] - sumc[max(0, p - 1)][j]);
            p = lower_bound(row[i] + m - j + 2, row[i] + m + 1, m - j + 1) - row[i];
            p = m - p + 1;
            if(row[i][m - j + 1] != m - j + 1) add(dp[i][j][0], sumr[i][j - 1] - sumr[i][max(0, p - 1)]);
            add(sumr[i][j], sumr[i][j - 1] + dp[i][j][1]);
            add(sumc[i][j], sumc[i - 1][j] + dp[i][j][0]);
        }
    }
    int ans = (dp[n][m][1] + dp[n][m][0]) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
