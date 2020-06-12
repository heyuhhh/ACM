/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 22:55:58
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
    int n, m; cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int t = n + m - 1;
    int d = t / 2;
    int ans = 0;
    for (int k = 0; k < d; k++) {
        vector <vector <int>> cnt(2, vector <int>(2));
        int i = 0, j = k;
        if (j >= m) {
            i += j - m + 1;
            j = m - 1;
        }
        while (j >= 0 && i < n) {
            ++cnt[0][a[i][j]];
            ++i, --j;
        }
        i = n - 1, j = m - 1 - k;
        if (j < 0) {
            i += j;
            j = 0;
        }
        while (j < m && i >= 0) {
            ++cnt[1][a[i][j]];
            --i, ++j;
        }
        ans += min(cnt[0][0] + cnt[1][0], cnt[0][1] + cnt[1][1]);
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
