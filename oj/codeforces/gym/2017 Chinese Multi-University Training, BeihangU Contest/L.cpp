/*
 * Author:  heyuhhh
 * Created Time:  2020/6/2 11:46:41
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
#include <functional>
#include <numeric>
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
const int N = 1e6 + 5, MOD = 1e9 + 7;

int fac[N], inv[N];
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
}

int n, _;
struct seg {
    int l, r;
}a[N];

void run() {
    ++_;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].r;
    }
    vector <vector<pii>> L(n + 1);
    for (int i = 1; i <= n; i++) {
        L[a[i].l].push_back(MP(a[i].r, i));
    }
    for (int i = 1; i <= n; i++) {
        sort(all(L[i]));        
    }
    cout << "Case #" << _ << ": ";
    int ans = fac[n];
    function <int(int, int)> dfs;
    bool f = false;
    dfs = [&](int l, int r) {
        if (l > r) return 0;
        int t = sz(L[l]) - 1;
        if (t < 0) {
            f = true;
            return 0;
        }
        pii now = L[l][t];
        L[l].pop_back();
        int nr = now.fi, m = now.se;
        if (nr != r) {
            f = true;
            return 0;
        }
        int sz = 1 + dfs(l, m - 1) + dfs(m + 1, r);
        ans = 1ll * ans * inv[sz] % MOD;
        return sz;
    };
    dfs(1, n);
    if (f) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    while (cin >> n) {
        run();
    }
    return 0;
}
