/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 22:47:35
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 50 + 5, M = 2e4 + 5;

int n, m, k;
int dp[N][M];
int a[N][M], sum[N][M];
int pre[M], suf[M], id_p[M], id_s[M];

void run(){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];   
        }
    }
    auto calc = [&](int i, int a, int b) {
        return sum[i][b] - sum[i][a - 1] + sum[i + 1][b] - sum[i + 1][a - 1];
    };
    auto init = [&](int r) {
        for(int i = k; i <= m; i++) {
            if(dp[r][i] > pre[i - 1]) {
                pre[i] = dp[r][i];
            } else {
                pre[i] = pre[i - 1];
            }
        }   
        for(int i = m; i >= k; i--) {
            if(dp[r][i] > suf[i + 1]) {
                suf[i] = dp[r][i];
            } else {
                suf[i] = suf[i + 1];
            }
        }
    };
    for(int i = k; i <= m; i++) {
        dp[1][i] = calc(1, i - k + 1, i);   
    }
    init(1);
    for(int i = 2; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            int t = sum[i + 1][j] - sum[i + 1][j - k];
            dp[i][j] = max(pre[j - k], suf[j + k]) + calc(i, j - k + 1, j) - t;
            for(int s = j - k + 1; s <= min(m, j + k - 1); s++) {
                if(s <= j) dp[i][j] = max(dp[i][j], dp[i - 1][s] + sum[i][j] - sum[i][s]);
                else dp[i][j] = max(dp[i][j], dp[i - 1][s] + sum[i][s - k] - sum[i][j - k]);
            }
            dp[i][j] += t;
        }
        init(i);
    }
    int ans = pre[m];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}
