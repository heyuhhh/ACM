/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 19:00:39
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

int n;
int a[N];
int cnt[33];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> a[i]; x = a[i];
        for(int j = 30; j >= 0; j--) {
            if(x >> j & 1) ++cnt[j];  
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 30; j++) if(a[i] >> j & 1) {
            ans += 1ll * cnt[j] * (1 << j);
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
