/*
 * Author:  heyuhhh
 * Created Time:  2020/6/8 13:36:25
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
const int N = 3e4 + 5, MOD = 1e9 + 7;

int n, blo;
int a[N], b[N];
int fib[N];
int ans[N];

struct query {
    int l, r, id;
    bool operator < (const query& A) const {
        if ((l - 1) / blo != (A.l - 1) / blo) {
            return (l - 1) / blo < (A.l - 1) / blo;
        }
        if ((l - 1) / blo % 2 != (A.l - 1) / blo % 2) {
            return r < A.r;
        }
        return r > A.r;
    }
} q[N];

int cnt[N];
int now[N << 2], pre[N << 2], sz[N << 2];

void push_up(int o) {
    sz[o] = sz[o << 1] + sz[o << 1|1];
    pre[o] = (pre[o << 1] + 1ll * pre[o << 1|1] * (sz[o << 1] > 0 ? fib[sz[o << 1] - 1] : 0) + 1ll * now[o << 1|1] * fib[sz[o << 1]]) % MOD;
    now[o] = (now[o << 1] + 1ll * pre[o << 1|1] * fib[sz[o << 1]] + 1ll * now[o << 1|1] * fib[sz[o << 1] + 1]) % MOD;
}

void update(int o, int l, int r, int p, int v) {
    if (l == r) {
        sz[o] += v;
        pre[o] = now[o] = 0;
        if (v > 0) now[o] = b[p];
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(o << 1, l, mid, p, v);
    else update(o << 1|1, mid + 1, r, p, v);
    push_up(o);
}

void add(int x, int val) {
    cnt[a[x]] += val;
    if (val == 1) {
        if (cnt[a[x]] == 1) update(1, 1, b[0], a[x], 1);
    } else {
        if (cnt[a[x]] == 0) update(1, 1, b[0], a[x], -1);
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    b[0] = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + b[0] + 1, a[i]) - b;
    }
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    blo = sqrt(n + 0.5);
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= Q; i++) {
        for (; r < q[i].r; ++r) add(r + 1, 1);
        for (; r > q[i].r; --r) add(r, -1);
        for (; l < q[i].l; ++l) add(l, -1);
        for (; l > q[i].l; --l) add(l - 1, 1);
        ans[q[i].id] = now[1];
    }
    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
