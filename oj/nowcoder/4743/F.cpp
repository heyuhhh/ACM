/*
 * Author:  heyuhhh
 * Created Time:  2020/3/14 10:23:00
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
int a[N], b[N];

struct node {
    int id, h, v;
    bool operator < (const node &A) const {
        if(id != A.id) return id < A.id;
        return h < A.h;
    }
}info[N];

struct BIT {
    ll c[N];
    int lowbit(int x) {return x & (-x);}
    void upd(int x, ll v) {
        for(; x < N; x += lowbit(x)) c[x] = max(c[x], v);
    }   
    ll query(int x) {
        ll res = 0;
        for(; x; x -= lowbit(x)) res = max(res, c[x]);
        return res;   
    }
}bit;

void run() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) {
        int t, p, c; cin >> t >> p >> c;
        int x = a[p], y = b[p] + t;
        info[i] = node{y - x, x + y, c};
    }
    sort(info + 1, info + n + 1);
    vector <int> v;
    for(int i = 1; i <= n; i++) v.push_back(info[i].h);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for(int i = 1; i <= n; i++) {
        int h = lower_bound(all(v), info[i].h) - v.begin() + 1;
        bit.upd(h, bit.query(h) + info[i].v);
    }
    ll ans = bit.query(n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
