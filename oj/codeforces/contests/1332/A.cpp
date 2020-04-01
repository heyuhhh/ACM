/*
 * Author:  heyuhhh
 * Created Time:  2020/3/31 21:38:57
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x, y; cin >> x >> y;
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    int w = r2 - r1, h = c2 - c1;
    if(w) {
        int t = min(a / w, b / w);
        a -= t * w, b -= t * w;
        int tt = min(a, b);
        a -= tt, b -= tt;          
    }
    if(a > x - r1 || b > r2 - x) {
        cout << "NO" << '\n';
        return;   
    }
    if(h) {
        int t = min(c / h, d / h);
        c -= t * h, d -= t * h;
        int tt = min(c, d);
        c -= tt, d -= tt;          
    }
    if(c > y - c1 || d > c2 - y) {
        cout << "NO" << '\n';
        return;   
    }
    cout << "YES" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
