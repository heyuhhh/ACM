/*
 * Author:  heyuhhh
 * Created Time:  2020/2/18 15:29:15
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
const int N = 5000 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

int inv(int x) {
    return qpow(x, MOD - 2);   
}

int n, m;
int a[N];
int f[N], h[N];
int x[N], y[N];
int l[N], r[N];
vector <int> v[N];

void run(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ++r[a[i]];
    }
    for(int i = 1; i <= m; i++) {
        cin >> f[i] >> h[i];   
        v[f[i]].push_back(h[i]);
    }
    for(int i = 1; i <= n; i++) sort(all(v[i]));
    pii ans(0, 0);
    auto upd = [&](int x, int y) {
        if(x > ans.fi) ans = MP(x, 0);
        if(x == ans.fi) ans.se = (ans.se + y) % MOD;
    };
    auto calc = [&](int i) {
        int a = upper_bound(all(v[i]), l[i]) - v[i].begin();
        int b = upper_bound(all(v[i]), r[i]) - v[i].begin();
        if(a > b) swap(a, b);
        int cnt1 = 1ll * a * (b - 1) % MOD, cnt2 = a + b;
        if(cnt1 > 0) {
            x[i] = 2;
            y[i] = cnt1;
        } else if(cnt2 > 0) {
            x[i] = 1;
            y[i] = cnt2;
        } else {
            x[i] = 0;
            y[i] = 1;
        }
    };
    int tx = 0, ty = 1;
    for(int i = 1; i <= n; i++) {
        calc(i);
        tx += x[i];
        ty = 1ll * ty * y[i] % MOD;
    }
    upd(tx, ty);
    for(int i = 1; i <= n; i++) {
        int now = a[i];
        tx -= x[now];
        ty = 1ll * ty * inv(y[now]) % MOD;
        ++l[now], --r[now];
        if(binary_search(all(v[now]), l[now])) {
            int t = upper_bound(all(v[now]), r[now]) - v[now].begin();
            if(r[now] >= l[now]) --t;
            if(t > 0) {
                x[now] = 2;
                y[now] = t;
            } else {
                x[now] = y[now] = 1;   
            }
            int nx = tx + x[now], ny = 1ll * ty * y[now] % MOD;
            upd(nx, ny);
        }
        calc(now);
        tx += x[now];
        ty = 1ll * ty * y[now] % MOD;
    }
    cout << ans.fi << ' ' << ans.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
