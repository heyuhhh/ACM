/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 20:06:28
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
const int N = 1e5 + 5;

void run() {
    int n, m, x; cin >> n >> m >> x;
    vector <vector <int>> a(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(m + 1);
        a[i][m] = k;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INF;
    for (int i = 0; i < 1 << n; i++) {
        vector <int> cnt(m, 0);
        int res = 0;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            res += a[j][m];
            for (int k = 0; k < m; k++) {
                cnt[k] += a[j][k];
            }
        }
        bool f = true;
        for (auto it : cnt) {
            if (it < x) f = false;
        }
        if (f) {
            ans = min(ans, res);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
