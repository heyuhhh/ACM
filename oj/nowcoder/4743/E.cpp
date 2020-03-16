/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 23:06:41
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
const int N = 400 + 5;

int n, m, q;
int a[N];

ll calc(int v, int k) {
    int r = v % k;
    int t = v / k;
    return 1ll * r * (t + 1) * (t + 1) + 1ll * (k - r) * t * t;
}

ll solve(int v, int k) {
    return calc(v, k) - calc(v, k + 1);
}

void run() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    while(q--) {
        int id, v; cin >> id >> v;
        a[id] = v;
        priority_queue <pair<ll, pii>> q;
        for(int i = 1; i <= n; i++) {
            q.push(pair<ll, pii>{solve(a[i], 1), MP(a[i], 1)});   
        }
        int k = m - n;
        while(k--) {
            pair <ll, pii> now = q.top(); q.pop();
            int val = now.se.fi, t = now.se.se + 1;
            q.push(pair<ll, pii>{solve(val, t), MP(val, t)});   
        }
        ll ans = 0;
        while(!q.empty()) {
            pair <ll, pii> now = q.top(); q.pop();
            int val = now.se.fi, t = now.se.se;
            ans += calc(val, t);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
