/*
 * Author:  heyuhhh
 * Created Time:  2020/2/17 21:24:13
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
const int N = 50 + 5, M = 20 + 5;

int n;
int a[N];
int dp[N][N];

void run(){
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int mx = a[i];
        for(int j = i; j >= 1; j--) {
            mx = max(mx, a[j]);
            int c = (i - j + 1) / 2;
            for(int k = c; k <= n; k++) {
                dp[i][k] = max(dp[i][k], dp[j - 1][k - c] + (i - j + 1) * mx);   
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dp[n][i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
