/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 15:02:35
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

int n, m;
int a[N], b[N], ans[N];

void run() {
    cin >> n >> m;
    ll s = 0;
    for(int i = 1; i <= m; i++) cin >> a[i], b[i] = a[i], s += a[i];
    if(s < n) {
        cout << -1 << '\n';
        return;
    }
    ll d = s - n;
    for(int i = 1; i <= n; i++) {
        if(a[i] - 1 < d) {
            d -= a[i] - 1;
            a[i] = 1;   
        } else {
            a[i] -= d;
            d = 0;
        }
    }
    ll now = 1;
    for(int i = 1; i <= m; i++) {
        if(now + b[i] - 1 > n) {
            cout << -1 << '\n';
            return;   
        }
        ans[i] = now;
        now += a[i];
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " \n"[i == m];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
