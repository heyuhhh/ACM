/*
 * Author:  heyuhhh
 * Created Time:  2020/6/12 9:28:53
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
const int N = 1e5 + 5, MOD = 998244353;

void run() {
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector <int> r(m, -1);
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        if (j >= 0 && a[i] == b[j]) {
            r[j] = i;
            --j;
        }
    }
    if (r[0] == -1) {
        cout << 0 << '\n';
        return;
    }
    r.push_back(n);
    for (int i = 0; i < r[0]; i++) {
        if (a[i] < b[0]) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = r[j] + 1; i < r[j + 1]; i++) {
            if (a[i] < b[j]) {
                cout << 0 << '\n';
                return;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < m - 1; i++) {
        int j = r[i + 1];
        while (j > r[i] && a[j] >= b[i + 1]) {
            --j;
        }
        ans = 1ll * ans * (r[i + 1] - j) % MOD;
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
