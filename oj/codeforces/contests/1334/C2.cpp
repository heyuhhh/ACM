/*
 * Author:  heyuhhh
 * Created Time:  2020/4/10 23:40:56
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
const int N = 3e5 + 5;

int n;
ll a[N], b[N];
bool chk[N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    set <pair<ll, int>> s;
    for(int i = 1; i <= n; i++) s.insert(MP(a[i], i));
    ll ans = 0;
    int cnt = 0;
    while(!s.empty()) {
        pair<ll, int> now = *s.begin();
        s.erase(s.begin());
        ans += now.fi;
        if(!chk[now.se]) {
            chk[now.se] = true;
            ++cnt;
        }
        if(cnt == n) break;
        int id = now.se % n + 1;
        auto t = s.lower_bound(MP(a[id], id));
        if(t != s.end()) {
            s.erase(t);
            a[id] -= b[now.se];
            if(a[id] < 0) a[id] = 0;
            s.insert(MP(a[id], id));
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
