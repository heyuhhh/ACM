/*
 * Author:  heyuhhh
 * Created Time:  2020/6/21 8:59:29
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
    string s, t;
    cin >> s >> t;
    string ss = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ss += s[i];
        }
    }
    sort(all(s)), sort(all(t));
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    n = ss.length();
    int ans = 0;
    int p0 = 0, p1 = 0;
    int ok0 = 0, ok1 = 0;
    for (int i = 0; i < n; i++) {
        if (ss[i] == '1') {
            if (p0) {
                ++ok0;
                --p0;
            } else {
                ++p1;
                if (ok1) {
                    --ok1;
                } else {
                    ++ans;
                }
            }
        } else {
            if (p1) {
                ++ok1;
                --p1;
            } else {
                ++p0;
                if (ok0) {
                    --ok0;
                } else {
                    ++ans;
                }
            }
        }
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
