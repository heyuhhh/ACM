/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 11:56:12
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
const int N = 50 + 5;

int n;
char s[N][N];
int sum[N][N], dp[N][N][N][N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for(int j = 1; j <= n; j++) {
            sum[i][j] = (s[i][j] == '#');
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] += sum[i][j - 1];
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] += sum[i - 1][j];
        }   
    }   
    auto query = [&](int r1, int c1, int r2, int c2) {
        return sum[r2][c2] + sum[r1 - 1][c1 - 1] - sum[r2][c1 - 1] - sum[r1 - 1][c2];
    };
    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= n; y1++) {
            for(int x2 = x1; x2 <= n; x2++) {
                for(int y2 = y1; y2 <= n; y2++) {
                    dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
                    if(x1 == x2 && y1 == y2) dp[x1][y1][x2][y2] = (s[x1][y1] == '#');
                }   
            }
        }   
    }
    for(int k1 = 1; k1 <= n; k1++) {
        for(int k2 = 1; k2 <= n; k2++) {
            for(int x1 = 1; x1 <= n; x1++) {
                for(int y1 = 1; y1 <= n; y1++) {
                    int x2 = x1 + k1 - 1, y2 = y1 + k2 - 1;
                    if(x2 > n || y2 > n) break;
                    int& now = dp[x1][y1][x2][y2];
                    if(k1 >= k2) {
                        for(int t = x1; t <= x2; t++) {
                            if(query(t, y1, t, y2) == 0) {
                                now = min(now, dp[x1][y1][t - 1][y2] + dp[t + 1][y1][x2][y2]);
                            }
                        }
                    } else {
                        for(int t = y1; t <= y2; t++) {
                            if(query(x1, t, x2, t) == 0) {
                                now = min(now, dp[x1][y1][x2][t - 1] + dp[x1][t + 1][x2][y2]);   
                                //if(x1 == 4 && y1 == 3 && x2 == 4 && y2 == 4) {
                                    //dbg(x1, t, x2, t, dp[x1][y1][x2][t - 1], dp[x1][t + 1][x2][y2]);   
                                //}
                            }
                        }
                    }
                }   
            }
        }   
    }
    cout << dp[1][1][n][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run(); 
    return 0;
}
