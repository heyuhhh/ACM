/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 20:25:48
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
int x[N], y[N];
vector <int> vx, vy;
vector <int> v[N];
bool chk[N];

struct BIT {
    int c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, int v = 1) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);   
    }
}bit; 

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        vx.push_back(x[i]), vy.push_back(y[i]);   
    }
    sort(all(vx)), sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());
    for(int i = 1; i <= n; i++) {
        x[i] = lower_bound(all(vx), x[i]) - vx.begin() + 1;   
        y[i] = lower_bound(all(vy), y[i]) - vy.begin() + 1;   
        v[y[i]].push_back(x[i]);
    }
    for(int i = 1; i <= n; i++) sort(all(v[i]));
    ll ans = 0;
    for(int i = n; i >= 1; i--) {
        for(auto it : v[i]) {
            if(!chk[it]) {
                chk[it] = true;
                bit.add(it);
            }
        }
        int all = bit.query(n);
        for(int j = 0; j < sz(v[i]); j++) {
            if(j == 0) {
                int l = bit.query(v[i][j] - 1), r = all - l - 1;
                ans += 1ll * (l + 1) * (r + 1);
            } else {
                int l = bit.query(v[i][j] - 1), r = all - l - 1;
                l -= bit.query(v[i][j - 1]);
                ans += 1ll * (l + 1) * (r + 1);
            }
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
