/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 22:36:15
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
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    int x = min(b / 2, min(a, b - a));
    b -= 2 * x;
    a -= x;
    int ans = x;
    int c = min(a, b);
    ans += c / 3 * 2;
    a -= c / 3 * 3;
    b -= c / 3 * 3;
    if (a > b) swap(a, b);
    for (int i = 3; i >= 0; i--) {
        if (i <= a && 2 * i <= b) {
            ans += i;
            break;   
        }
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
