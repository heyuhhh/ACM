/*
 * Author:  heyuhhh
 * Created Time:  2020/2/17 16:22:45
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
const int N = 500 + 5, M = 2e5 + 5;

int n, m;
int a[N][N], b[N];
int dp[N][N];

void add(int r1, int c1, int r2, int c2, int v) {
    a[r1][c1] += v;
    a[r1][c2 + 1] -= v;
    a[r2 + 1][c1] -= v;
    a[r2 + 1][c2 + 1] += v;
}

void run(){
    for(int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        add(1, l, r, n, 1);
        add(l, l, r, r, -2);
        b[l] += 2, b[r + 1] -= 2;   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i - 1][j];
        }   
    }
    memset(dp, INF, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        b[i] += b[i - 1];   
        a[i][i] += b[i];
        dp[i][i] = a[i][i];
    }
    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] += a[i][j];
        }   
    }
    cout << dp[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
