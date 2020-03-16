/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 20:15:51
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

ll f[N];
int t;

void init() {
    ll Max = 4e18;
    f[1] = 1, f[2] = 3;
    for(int i = 3;; i++) {
        f[i] = f[i - 1] * 2;
        if(i % 2 == 0) ++f[i];
        if(f[i] >= Max) {
            t = i; break;   
        }
    }
}

void run() {
    ll n; cin >> n;
    int p = lower_bound(f + 1, f + t + 1, n) - f;
    if(p & 1) cout << "XiaoQiao" << '\n';
    else cout << "XiaoHuiHui" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
