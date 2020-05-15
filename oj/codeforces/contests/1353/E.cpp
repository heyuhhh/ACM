/*
 * Author:  heyuhhh
 * Created Time:  2020/5/14 23:57:45
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
  void err() { std::cout << std::endl; }
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

void run() {
    int n, k; cin >> n >> k;
    vector <int> dp(n + 1), sum(n + 1);
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '1');
    }
    if (sum[n] == 0) {
        cout << 0 << '\n';
        return;
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int res = sum[i] + sum[n] - sum[i + 1];
        res += (s[i] == '0');
        ans = min(ans, res);
    }
    
    auto calc = [&] (int l, int r) {
        return sum[r] - sum[l - 1];
    };
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = sum[i - 1] + (s[i - 1] == '0');
        if (i >= k) {
            dp[i] = min(dp[i], dp[i - k] + calc(i - k + 1, i - 1) + (s[i - 1] == '0'));
        } 
    }
    
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i] + sum[n] - sum[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--) 
    run();
    return 0;
}
