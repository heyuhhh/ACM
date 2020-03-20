/*
 * Author:  heyuhhh
 * Created Time:  2020/3/18 20:34:05
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
const int N = 2e5 + 5;

int n;
vector <int> v[N][4];

ll dp[N][10];

void chmax(ll& x, ll y) {
    x = max(x, y);
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int c, d; cin >> c >> d;
            v[i][c].push_back(d);
        }
        for(int j = 1; j <= 3; j++) {
            sort(all(v[i][j])), reverse(all(v[i][j]));
        }
    }
    memset(dp, -INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) if(dp[i][j] >= 0) {
            chmax(dp[i + 1][j], dp[i][j]);
            //Case1:
            if(sz(v[i + 1][1]) >= 3) {
                int mx1 = v[i + 1][1][0], mx2 = v[i + 1][1][1], mx3 = v[i + 1][1][2];
                if(j + 3 >= 10) chmax(dp[i + 1][(j + 3) % 10], dp[i][j] + 2 * mx1 + mx2 + mx3);
                else chmax(dp[i + 1][(j + 3) % 10], dp[i][j] + mx1 + mx2 + mx3);
            }
            //Case2:
            if(sz(v[i + 1][1]) >= 2) {
                int mx1 = v[i + 1][1][0], mx2 = v[i + 1][1][1];  
                if(j + 2 >= 10) chmax(dp[i + 1][(j + 2) % 10], dp[i][j] + 2 * mx1 + mx2);
                else chmax(dp[i + 1][(j + 2) % 10], dp[i][j] + mx1 + mx2);               
            }
            if(sz(v[i + 1][1]) >= 1 && sz(v[i + 1][2]) >= 1) {
                int mx1 = v[i + 1][1][0], mx2 = v[i + 1][2][0];  
                if(j + 2 >= 10) chmax(dp[i + 1][(j + 2) % 10], dp[i][j] + 2 * max(mx1, mx2) + min(mx1, mx2));
                else chmax(dp[i + 1][(j + 2) % 10], dp[i][j] + mx1 + mx2);                              
            }
            //Case3:
            for(int k = 1; k <= 3; k++) {
                if(sz(v[i + 1][k]) >= 1) {
                    int mx1 = v[i + 1][k][0];
                    if(j + 1 >= 10) chmax(dp[i + 1][(j + 1) % 10], dp[i][j] + 2 * mx1);
                    else chmax(dp[i + 1][(j + 1) % 10], dp[i][j] + mx1);                              
                }                  
            }
        }   
    }
    ll ans = 0;
    for(int i = 0; i < 10; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
