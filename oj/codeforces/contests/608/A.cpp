/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 17:16:33
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

int a[4], e, f;

void run(){
    for(int i = 0; i < 4; i++) cin >> a[i];
    cin >> e >> f;
    int ans = 0;
    if(e > f) {
        int d = min(a[0], a[3]);
        ans += d * e;
        a[3] -= d;
        d = *min_element(a + 1, a + 4);
        ans += d * f;
    } else {
        int d = *min_element(a + 1, a + 4);
        ans += d * f;
        a[3] -= d;
        d = min(a[0], a[3]);
        ans += d * e;
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
