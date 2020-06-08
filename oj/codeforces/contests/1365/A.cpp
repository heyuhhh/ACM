/*
 * Author:  heyuhhh
 * Created Time:  2020/6/7 22:39:24
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
    vector <int> cols(m), rows(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                ++cols[j];
                ++rows[i];
            }
        }
    }
    int cntr = 0, cntl = 0;
    for (int i = 0; i < n; i++) {
        if (rows[i] == 0) ++cntr;
    }
    for (int i = 0; i < m; i++) {
        if (cols[i] == 0) ++cntl;
    }
    int t = min(cntr, cntl);
    if (t & 1) {
        cout << "Ashish" << '\n';
    } else {
        cout << "Vivek" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
