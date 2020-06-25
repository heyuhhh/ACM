/*
 * Author:  heyuhhh
 * Created Time:  2020/6/23 13:33:44
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

void run() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s; cin >> s;
    int n = s.length();
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'N' && (s[i + 1] == 'W' || s[i + 1] == 'E')) {
            ans *= 2;
        }
        if (s[i] == 'S' && (s[i + 1] == 'W' || s[i + 1] == 'E')) {
            ans *= 2;
        }
        if (ans > MOD) ans -= MOD;
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
