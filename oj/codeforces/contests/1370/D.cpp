/*
 * Author:  heyuhhh
 * Created Time:  2020/6/21 8:15:28
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
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    auto check = [&] (int s, int x, int m) {
        int cnt = 0;
        for (int i = s; i < n; i++) {
            if (a[i] <= x) {
                ++cnt, ++i;
                if (cnt >= m) {
                    if (s && (k & 1)) {
                        if (i < n) return true;
                        return false;
                    }
                    if (!s && !(k & 1)) {
                        if (i < n) return true;
                        return false;
                    }
                    return true;
                }
            }
        }
        return false;
    };
    auto solve = [&] (int s, int m) {
        //choose from s
        int l = 1, r = INF, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(s, mid, m)) r = mid;
            else l = mid + 1;
        }
        return r;
    };
    int ans = min(solve(0, (k + 1) / 2), solve(1, k / 2));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
