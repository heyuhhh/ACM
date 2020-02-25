/*
 * Author:  heyuhhh
 * Created Time:  2020/2/25 21:11:41
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
const int N = (1 << 17) + 5, M = 18;

int n, k;
int dp[M][N][2][2];
bool fan[N];

void run(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        fan[x] = 1;   
    }
    memset(dp, -INF, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (1 << n); j += (1 << i)) {
            if(i == 1) {
                dp[i][j][fan[j]][fan[j + 1]] = (fan[j] | fan[j + 1]);
                dp[i][j][fan[j + 1]][fan[j]] = (fan[j] | fan[j + 1]);
            } else {
                for(int x1 = 0; x1 < 2; x1++) {
                    for(int y1 = 0; y1 < 2; y1++) {
                        for(int x2 = 0; x2 < 2; x2++) {
                            for(int y2 = 0; y2 < 2; y2++) {
                                int cost = dp[i - 1][j][x1][y1] + dp[i - 1][j + (1 << (i - 1))][x2][y2];
                                if(x1 || x2) ++cost;
                                if(y1 || y2) ++cost;
                                
                                dp[i][j][x1][x2] = max(dp[i][j][x1][x2], cost + (x2 | y1));
                                dp[i][j][x1][x2] = max(dp[i][j][x1][x2], cost + (x2 | y2));
                                
                                dp[i][j][x1][y1] = max(dp[i][j][x1][y1], cost + (x2 | y1));
                                dp[i][j][x1][y2] = max(dp[i][j][x1][y2], cost + (x2 | y2));
                                
                                dp[i][j][x2][x1] = max(dp[i][j][x2][x1], cost + (x1 | y1));
                                dp[i][j][x2][x1] = max(dp[i][j][x2][x1], cost + (x1 | y2));
                                
                                dp[i][j][x2][y1] = max(dp[i][j][x2][y1], cost + (x1 | y1));
                                dp[i][j][x2][y2] = max(dp[i][j][x2][y2], cost + (x1 | y2));
                            }
                        }
                    }
                }
            }
        }   
    }
    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ans = max(ans, dp[n][1][i][j] + (i | j));
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
