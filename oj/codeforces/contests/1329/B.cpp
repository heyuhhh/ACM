/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 19:38:37
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
const int N = 31;

int C[N][N], dp[N][N];
int cnt[N];

void run() {
    int d, m; cin >> d >> m;
    C[0][0] = (1 % m);
    for(int i = 1; i < N; i++) {
        C[i][0] = (1 % m);
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
        }
    }
    int ans = 0;
    int high;
    for(int i = N - 1; i >= 0; i--) if(d >> i & 1) {
        high = i; break;
    }
    for(int i = 0; i < N; i++) {
        cnt[i] = (1 << i);
        if(high == i) {
            cnt[i] = (d ^ (1 << i)) + 1;
            break;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i <= high; i++) {
        for(int j = 0; j <= high + 1; j++) if(dp[i][j]) {
            for(int k = j + 1; k <= high + 1; k++) {
                dp[i + 1][k] = (dp[i + 1][k] + 1ll * dp[i][j] * cnt[k - 1] % m) % m;
            }
        }
    }
    for(int i = 1; i <= high + 1; i++) {
        for(int j = 1; j <= high + 1; j++) {
            ans = (ans + dp[i][j]) % m;
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
