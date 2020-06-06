/*
 * Author:  heyuhhh
 * Created Time:  2020/6/3 12:37:31
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
const int N = 1e6 + 5;

int A[N];
struct node {
    int op, x, y;
}a[N];
int n;

void Hash(int* a) {
    sort(a + 1, a + a[0] + 1);
    a[0] = unique(a + 1, a + a[0] + 1) - a - 1;
}
int find(int x) {
    return lower_bound(A + 1, A + A[0] + 1, x) - A;
}

set <int> tr[N << 2];
auto shoot = [&] (int id, int x, int y) {
    return 1ll * (x - a[id].x) * (x - a[id].x) + 1ll * (y - a[id].y) * (y - a[id].y) < 1ll * a[id].y * a[id].y;
};

int ans;

void insert(int o, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        if (v > 0) {
            tr[o].insert(v);
        } else {
            tr[o].erase(-v);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) insert(o << 1, l, mid, L, R, v);
    if (R > mid) insert(o << 1|1, mid + 1, r, L, R, v);
}

void query(int o, int l, int r, int p, int x, int y) {
    for (auto it : tr[o]) {
        if (shoot(it, x, y)) {
            ans = it;
        }
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (p <= mid) query(o << 1, l, mid, p, x, y);
    else query(o << 1|1, mid + 1, r, p, x, y);
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op, x, y; cin >> op >> x >> y;
        a[i] = node {op, x, y};
        if (op == 1) {
            A[++A[0]] = x;
        } else {
            A[++A[0]] = x - y;
            A[++A[0]] = x + y;
        }
    }
    Hash(A);   
    for (int i = 1; i <= n; i++) {
        int op = a[i].op, x = a[i].x, y = a[i].y;
        if (op == 1) {
            insert(1, 1, A[0], find(x - y), find(x + y), i);
        } else {
            ans = -1;
            query(1, 1, A[0], find(x), x, y);
            cout << ans << '\n';
            if (ans != -1) {
                insert(1, 1, A[0], find(a[ans].x - a[ans].y), find(a[ans].x + a[ans].y), -ans);
            }
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
