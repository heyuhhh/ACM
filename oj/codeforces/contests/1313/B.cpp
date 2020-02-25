/*
 * Author:  heyuhhh
 * Created Time:  2020/2/24 10:15:33
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
const int N = 1e5 + 5;

int n, x, y;

int gao(int sum, int op) {
    int s = max(1, sum - n), t = min(n, sum - 1);
    int l = t - s + 1 - (s <= x && x <= t), r = t - s + 1 - (s <= y && y <= t);
    int res = min(l, r);
    l = n - t - (x >= sum), r = n - t - (y >= sum);
    if(op) {
        res += min(s - 1, l) + min(s - 1, r);
        l -= s - 1, r -= s - 1;
        if(l > 0 && r > 0) res += min(l, r);
    } else res += s - 1;
    return res;
}

void run(){
    cin >> n >> x >> y;
    int ans1 = n - gao(x + y + 1, 1), ans2 = gao(x + y, 0) + 1;
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
