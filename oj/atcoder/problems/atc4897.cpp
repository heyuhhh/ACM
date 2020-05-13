/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 15:47:51
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
const int N = 11, M = 1000 + 5;

void run() {
    int n, m, k; cin >> n >> m >> k;
    vector <string> s(n);
    vector <vector <int>> sum(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (i) sum[i][j] += sum[i - 1][j];
            if (j) sum[i][j] += sum[i][j - 1];
            if (i && j) sum[i][j] -= sum[i - 1][j - 1];
            if (s[i][j] == '1') ++sum[i][j];
        }
    }
    auto calc = [&] (int r1, int r2, int c1, int c2) {
        int res = sum[r2][c2];
        if (r1) res -= sum[r1 - 1][c2];
        if (c1) res -= sum[r2][c1 - 1];
        if (r1 && c1) res += sum[r1 - 1][c1 - 1];
        return res;  
    };
    auto chk = [&] (vector <int>& rows, int j1, int j2) {
        int last = 0;
        for (int i = 0; i < sz(rows); i++) {
            if (calc(last, rows[i], j1, j2) > k) return false;
            last = rows[i] + 1;
        }
        return true;
    };
    int ans = INF;
    for (int sta = 0; sta < 1 << (n - 1); sta++) {
        vector <int> rows;
        for (int i = 0; i < n - 1; i++) if (sta >> i & 1) {
            rows.push_back(i);
        }
        rows.push_back(n - 1);
        vector <int> dp(m + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            int l = 1, r = i + 1, mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (chk(rows, mid - 1, i - 1)) r = mid;
                else l = mid + 1;
            }
            dp[i] = dp[r - 1] + 1;
        }
        int res = sz(rows) + dp[m] - 2;
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
