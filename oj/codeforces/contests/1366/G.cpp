/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 10:42:35
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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector <int> nxt(n, -1);
    for (int i = 0; i < n; i++) if (s[i] != '.') {
        int t = 0;
        for (int j = i; j < n; j++) {
            if (s[j] != '.') ++t;
            else --t;
            if (t == 0) {
                nxt[i] = j;
                break;
            }
        }
    }
    vector <vector <int>> dp(n + 1, vector <int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            //match
            if (j < m && s[i] == t[j]) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
            //skip
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            //forward & back
            if (s[i] != '.' && nxt[i] != -1) {
                dp[nxt[i] + 1][j] = min(dp[nxt[i] + 1][j], dp[i][j]);
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
