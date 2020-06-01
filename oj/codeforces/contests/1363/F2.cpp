/*
 * Author:  heyuhhh
 * Created Time:  2020/6/1 21:01:21
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
#include <functional>
#include <numeric>
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
const int N = 1e5 + 5;

void run() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string ss = s, tt = t;
    sort(all(ss)), sort(all(tt));
    if (ss != tt) {
        cout << -1 << '\n';
        return;
    }
    s = '#' + s;
    t = '#' + t;
    vector <vector <int>> dp(n + 1, vector<int>(n + 1, INF));   
    vector <vector <int>> suf_s(n + 2, vector<int>(26)), suf_t(n + 2, vector<int>(26));
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            suf_s[i][j] = suf_s[i + 1][j];
            suf_t[i][j] = suf_t[i + 1][j];
        }
        ++suf_s[i][s[i] - 'a'];
        ++suf_t[i][t[i] - 'a'];
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (suf_s[i + 1][t[j] - 'a'] > suf_t[j + 1][t[j] - 'a']) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
