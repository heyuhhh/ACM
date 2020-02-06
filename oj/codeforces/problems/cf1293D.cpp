/*
 * Author:  heyuhhh
 * Created Time:  2020/1/24 9:55:58
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e3 + 5;
const ll MAX = 2e16;

ll x0, y0, ax, ay, bx, by;
ll t;

struct Point {
    ll x, y;   
}p[N];

ll dis(Point A, Point B) {
    return abs(A.x - B.x) + abs(A.y - B.y);   
}

void run(){
    cin >> p[0].x >> p[0].y >> t;
    int n;
    p[n = 1] = Point {x0, y0};
    for(int i = 2;; i++) {
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
        if(x0 > MAX || y0 > MAX) break;
        p[i] = Point {x0, y0};
        n = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ll tot = dis(p[0], p[i]);
        if(tot <= t) ans = max(ans, 1);
        for(int j = 1; j <= n; j++) {
            if(tot + dis(p[i], p[j]) <= t) ans = max(ans, 1 + abs(i - j));
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> x0 >> y0 >> ax >> ay >> bx >> by) run();
    return 0;
}
