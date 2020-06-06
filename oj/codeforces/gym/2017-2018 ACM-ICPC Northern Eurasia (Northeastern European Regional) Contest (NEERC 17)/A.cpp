/*
 * Author:  heyuhhh
 * Created Time:  2020/6/3 8:40:00
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
const int N = 2e5 + 5;

int A[N];
struct node {
    int op, x, y;
}a[N];
int n;

void Hash(int* a) {
    sort(a + 1, a + a[0] + 1);
    a[0] = unique(a + 1, a + a[0] + 1) - a - 1;
}
int find(int* a, int x) {
    return lower_bound(a + 1, a + a[0] + 1, x) - a;
}

pii maxv[N << 2];

void push_up(int o) {
    if (maxv[o << 1] > maxv[o << 1|1]) {
        maxv[o] = maxv[o << 1];
    } else {
        maxv[o] = maxv[o << 1|1];
    }
}

void update(int o, int l, int r, int x, int v, int id) {
    if (l == r) {
        maxv[o] = MP(v, id);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(o << 1, l, mid, x, v, id);
    else update(o << 1|1, mid + 1, r, x, v, id);
    push_up(o);
}

pii queryL(int o, int l, int r, int L, int R, int v) {
    if (L > R) return MP(-1, -1);
    if (l == r) {
        return maxv[o];
    }
    int mid = (l + r) >> 1;
    pii res = MP(-1, -1);
    if (R > mid && maxv[o << 1|1].fi > v) {
        res = queryL(o << 1|1, mid + 1, r, L, R, v);
    }
    if (L <= mid && res.fi <= v && maxv[o << 1].fi > v) {
        res = queryL(o << 1, l, mid, L, R, v);
    }
    return res;
}

pii queryR(int o, int l, int r, int L, int R, int v) {
    if (L > R) return MP(-1, -1);
    if (l == r) {
        return maxv[o];
    }
    int mid = (l + r) >> 1;
    pii res = MP(-1, -1);
    if (L <= mid && maxv[o << 1].fi > v) {
        res = queryR(o << 1, l, mid, L, R, v);
    }
    if (R > mid && res.fi <= v && maxv[o << 1|1].fi > v) {
        res = queryR(o << 1|1, mid + 1, r, L, R, v);
    }
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op, x, y; cin >> op >> x >> y;
        a[i] = node {op, x, y};
        A[++A[0]] = x;
    }
    Hash(A);
    auto shoot = [&] (int id, int x, int y) {
        return 1ll * (x - a[id].x) * (x - a[id].x) + 1ll * (y - a[id].y) * (y - a[id].y) < 1ll * a[id].y * a[id].y;
    };
    for (int i = 1; i <= n; i++) {
        int op = a[i].op, x = a[i].x, y = a[i].y;
        if (op == 1) {
            update(1, 1, n, find(A, x), 2 * y, i);
        } else {
            int p = find(A, x);
            pii p1 = queryL(1, 1, n, 1, p, y), p2 = queryR(1, 1, n, p + 1, n, y);
            if (p1.fi > y && shoot(p1.se, x, y)) {
                update(1, 1, n, find(A, a[p1.se].x), 0, 0);
                cout << p1.se << '\n';
                continue;
            }
            if (p2.fi > y && shoot(p2.se, x, y)) {
                update(1, 1, n, find(A, a[p2.se].x), 0, 0);
                cout << p2.se << '\n';
                continue;
            }
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
