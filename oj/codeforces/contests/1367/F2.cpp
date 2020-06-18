/*
 * Author:  heyuhhh
 * Created Time:  2020/6/17 0:08:56
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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }   
    vector <vector <int>> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    auto last = [&] (int v, int p) {
        int t = lower_bound(all(pos[v]), p) - pos[v].begin() - 1;
        if (t == -1) return t;
        return t;
    };
    vector <vector <int>> dp(n, vector <int>(2, 0));
    dp[0][0] = sz(pos[0]);
    int Max = sz(pos[0]);
    for (int i = 1; i < n; i++) if (sz(pos[i])) {
        int cnt = sz(pos[i]);
        int k = last(i - 1, pos[i][0]);
        if (k == -1) {
            dp[i][0] = cnt;
        } else {
            if (k == sz(pos[i - 1]) - 1) {
                dp[i][0] = dp[i - 1][0] + cnt;
                dp[i][1] = dp[i - 1][1] + cnt;
            } else {
                dp[i][1] = k + 1 + cnt;
            }
        }
        for (int j = 0; j < cnt; j++) {
            int p = pos[i][j];
            int k = last(i - 1, p);
            if (k == -1) {
                Max = max(Max, cnt - j);
            } else {
                if (k == sz(pos[i - 1]) - 1) {
                    Max = max(Max, max(dp[i - 1][0], dp[i - 1][1]) + cnt - j);
                } else {
                    Max = max(Max, cnt - j + k + 1);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        Max = max(Max, max(dp[i][0], dp[i][1]));
    }
    cout << n - Max << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
