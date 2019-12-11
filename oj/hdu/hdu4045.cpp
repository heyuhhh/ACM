/*
 * Author:  heyuhhh
 * Created Time:  2019/12/10 19:14:48
 */
// dp预处理+第二类斯特林数
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
const int N = 1005, MOD = 1e9 + 7;

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;   
}

int n, m, r, k;
int dp[N][N];

int s[N][N];
void init() {
    s[0][0] = 1;
    for(int i = 1; i < N; i++) 
        for(int j = 1; j <= i; j++) 
            s[i][j] = (1ll * j * s[i - 1][j] % MOD + s[i - 1][j - 1]) % MOD;
}

void run(){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= r; j++) {
            add(dp[i][j], dp[i - 1][j]);
            add(dp[i][j], dp[max(i - k, 0)][j - 1]);
        }
    }
    int tot = dp[n][r];
    int sum = 0;
    for(int i = 1; i <= m; i++) add(sum, s[r][i]);
    int ans = 1ll * tot * sum % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    while(cin >> n >> r >> k >> m) run();
    return 0;
}
