/*
 * Author:  heyuhhh
 * Created Time:  2020/4/15 20:23:48
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
const int N = 5e5 + 5;

int n, m;
int a[N], p[N], b[N];

ll minv[N << 2], lz[N << 2];

void tag(int o, ll v) {
    minv[o] += v, lz[o] += v;
}

void push_up(int o) {
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
}

void push_down(int o, int l, int r) {
    if(lz[o] != 0) {
        int mid = (l + r) >> 1;
        tag(o << 1, lz[o]);
        tag(o << 1|1, lz[o]);
        lz[o] = 0;   
    }
}

void build(int o, int l, int r) {
    lz[o] = 0;
    if(l == r) {
        if(l == 0) minv[o] = 0;
        else minv[o] = 1e18;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L > R) return;
    if(L <= l && r <= R) {
        tag(o, v); return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void modify(int o, int l, int r, int p, ll v) {
    if(l == r) {
        minv[o] = min(minv[o], v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(p <= mid) modify(o << 1, l, mid, p, v);
    else modify(o << 1|1, mid + 1, r, p, v);
    push_up(o);
}

ll query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return minv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    ll res = 1e18;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = min(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1, j = 1; i <= n; i++) {
        if (a[i] == b[j]) ++j;
        if(i == n && j <= m) {
            cout << "NO" << '\n';
            return;   
        }
    }
    build(1, 0, m);
    for (int i = 0; i < n; i++) {
        int t = lower_bound(b + 1, b + m + 1, a[i + 1]) - b;
        if (p[i + 1] < 0) update(1, 0, m, t, m, p[i + 1]);
        if (b[t] == a[i + 1]) {
            ll v = query(1, 0, m, t - 1, t - 1);
            modify(1, 0, m, t, v);
        }
        update(1, 0, m, 0, t - 1, p[i + 1]);
    }
    ll ans = query(1, 0, m, m, m);
    cout << "YES" << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
