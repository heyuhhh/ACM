/*
 * Author:  heyuhhh
 * Created Time:  2020/1/27 11:35:53
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
const int N = 100 + 5;

int n;
int a[N];
int dp[N][N][2];

void run(){
    memset(dp, INF, sizeof(dp));
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(a[1] == 0) dp[1][1][1] = dp[1][0][0] = 0;
    else dp[1][a[1] & 1][a[1] & 1] = 0;
    int k = (n + 1) >> 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(a[i] == 0) {
                if(j) dp[i][j][1] = min(dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1]);
                dp[i][j][0] = min(dp[i - 1][j][1] + 1, dp[i - 1][j][0]);
            } else {
                if(a[i] & 1) {
                    if(j) dp[i][j][1] = min(dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1]);
                } else {
                    dp[i][j][0] = min(dp[i - 1][j][1] + 1, dp[i - 1][j][0]);
                }   
            }
        }
    }
    int ans;
    if(a[n] == 0) ans = min(dp[n][k][0], dp[n][k][1]);
    else ans = dp[n][k][a[n] & 1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
