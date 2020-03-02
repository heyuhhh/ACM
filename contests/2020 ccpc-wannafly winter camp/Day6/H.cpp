/*
 * Author:  heyuhhh
 * Created Time:  2020/2/19 11:47:00
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
const int N = 1e5 + 5, MOD = 998244353;

int n, q;
int a[N];
vector <pii> b;
ll pre[N], w[N];

int sum(int x) {
    int p = upper_bound(all(b), MP(x, INF)) - b.begin() - 1;
    if(p < 0) return 0;
    return ((p > 0 ? pre[p - 1] : 0) + 1ll * (x - b[p].fi + 1) * w[p] % MOD) % MOD;
}

int solve(int n, int x) {
    int res = 0;
    for(int i = 29; i >= 0; i--) {
        if(n >> i & 1) {
            int t = (n ^ x) >> i << i;
            int st = t ^ (1 << i);
            int ed = st + (1 << i) - 1;
            res = (1ll * res + sum(ed) - sum(st - 1) + MOD) % MOD;
        }
    }
    int t = n ^ x;
    res = (1ll * res + sum(t) - sum(t - 1) + MOD) % MOD;
    return res;
}

void run() {
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1, j; i <= n; i = j + 1) {
        j = i;
        while(j < n && a[j + 1] == a[j]) ++j;
        b.push_back(MP(a[i], j - i + 1));
    }
    for(int i = 0; i < sz(b); i++) {
        if(i == 0) w[i] = b[i].se;
        else w[i] = w[i - 1] + b[i].se;
    }
    for(int i = 0; i < sz(b); i++) {
        w[i] = 1ll * w[i] * w[i] % MOD;   
    }
    for(int i = 0; i < sz(b); i++) {
        if(i + 1 < sz(b)) {
            if(i == 0) pre[i] = 1ll * (b[i + 1].fi - b[i].fi) * w[i] % MOD;
            else pre[i] = (pre[i - 1] + 1ll * (b[i + 1].fi - b[i].fi) * w[i] % MOD) % MOD;
        }
    }
    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        int ans = (solve(r, x) - solve(l - 1, x) + MOD) % MOD;   
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> q) run();
    return 0;
}
