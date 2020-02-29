/*
 * Author:  heyuhhh
 * Created Time:  2020/2/28 20:50:36
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
const int N = 1000 + 5;

int n, m;
char s[N][N];
int dp[N][N];

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);   
    }
    memset(dp, INF, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == '1') continue;
            if(i == 1) {
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);   
            } else {
                if(j == 1) {
                    if(s[i - 1][j + 1] == '0') {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);   
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j]);   
                    }
                } else {
                    dp[i][j] = dp[i][j - 1];
                    if(j == m) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    else if(s[i - 1][j + 1] == '0') {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j]);   
                    }
                }
            }
        }   
    }
    int ans;
    if(dp[n][m] == INF) ans = -1;
    else ans = dp[n][m];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
