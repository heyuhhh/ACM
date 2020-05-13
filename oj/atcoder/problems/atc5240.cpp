/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 15:30:59
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
#include <numeric>
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

struct apple {
    int p, id;
    bool operator < (const apple &A) const {
        return p > A.p;
    }
}a[3 * N];

void run() {
    int x, y, A, B, C;
    cin >> x >> y >> A >> B >> C;
    int n = 0;
    for (int i = 1; i <= A; i++) {
        int p; cin >> p;
        a[++n] = apple {p, 1};
    }
    for (int i = 1; i <= B; i++) {
        int p; cin >> p;
        a[++n] = apple {p, 2};
    }
    for (int i = 1; i <= C; i++) {
        int p; cin >> p;
        a[++n] = apple {p, 3};
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    vector <int> v;
    for (int i = 1; i <= n; i++) {
        if (a[i].id == 1) {
            if (x) {
                --x;
                ans += a[i].p;
            }
        } else if (a[i].id == 2) {
            if (y) {
                --y;
                ans += a[i].p;
            }
        } else {
            v.push_back(a[i].p);
        }
        if (x + y == sz(v)) {
            ans += accumulate(all(v), 0ll);
            break;   
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
