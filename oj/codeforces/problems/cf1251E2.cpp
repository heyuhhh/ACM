/*
 * Author:  heyuhhh
 * Created Time:  2020/3/8 14:59:15
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
const int N = 2e5 + 5;

int n;
vector <int> v[N];

void run() {
    for(int i = 0; i < n; i++) v[i].clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int m, p; cin >> m >> p;
        v[m].push_back(p);   
    }
    ll ans = 0;
    multiset <int> s;
    int pref = n, cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        pref -= sz(v[i]);
        int need = i - (pref + cnt);
        for(auto it : v[i]) s.insert(it);
        while(need > 0) {
            --need; ++cnt;
            ans += *s.begin();
            s.erase(s.begin());
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
