/*
 * Author:  heyuhhh
 * Created Time:  2020/3/5 0:03:03
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
const int N = 1e5 + 5, M = 7;

int n, p, k;
ll dp[N][1 << M];
int s[N][M];

struct people {
    int s[7];
    int v;
    bool operator < (const people &A) const {
        return v > A.v;
    }
}a[N];

void run() {
    for(int i = 1; i <= n; i++) cin >> a[i].v;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> a[i].s[j];
        }
    }
    sort(a + 1, a + n + 1);
    auto calc = [&](int cur, int c) {
        if(k + c < cur) return 0;
        return a[k +  c + 1].v - a[cur].v;
    };
    memset(dp, -INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++) dp[0][0] += a[i].v;
    for(int i = 1; i <= n; i++) {
        for(int sta = 0; sta < 1 << p; sta++) {
            dp[i][sta] = dp[i - 1][sta];
            int c = 0;
            for(int j = 0; j < p; j++) if(sta >> j & 1) ++c;
            for(int j = 0; j < p; j++) if(sta >> j & 1) {
                dp[i][sta] = max(dp[i][sta], dp[i - 1][sta ^ (1 << j)] + a[i].s[j] + calc(i, c - 1));
            }
        }
    }
    cout << dp[n][(1 << p) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> p >> k) run();
    return 0;
}
