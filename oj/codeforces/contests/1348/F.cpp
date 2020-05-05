/*
 * Author:  heyuhhh
 * Created Time:  2020/5/4 18:33:33
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
const int N = 2e5 + 5;

int n;
int p[N], p2[N];
struct node {
    int l, r, id;
    bool operator < (const node &A) const {
        if (l != A.l) return l < A.l;
        return r < A.r;
    }   
}a[N];

pii maxv[N << 2];

void upd(int o, int l, int r, int p, int v) {
    if (l == r) {
        maxv[o] = MP(v, l);
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) upd(o << 1, l, mid, p, v);
    else upd(o << 1|1, mid + 1, r, p, v);
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
}

pii query(int o, int l, int r, int L, int R) {
    if (L > R) return MP(0, 0);
    if (L <= l && r <= R) return maxv[o];
    int mid = (l + r) >> 1;
    pii ans(0, 0);
    if (L <= mid) ans = query(o << 1, l, mid, L, R);
    if (R > mid) ans = max(ans, query(o << 1|1, mid + 1, r, L, R));
    return ans;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    set <pii> s;
    for (int i = 1, k = 1; i <= n; i++) {
        while (k <= n && a[k].l <= i) {
            s.insert(MP(a[k].r, k));
            ++k;
        }
        auto it = s.begin();
        p[a[it->se].id] = i;
        p2[i] = it->se;
        s.erase(it);
    }
    for (int i = 1; i <= n; i++) {
        int id = p2[i];
        pii res = query(1, 1, n, a[id].l, i - 1);
        if (res.fi >= i) {
            cout << "NO" << '\n';
            for (int j = 1; j <= n; j++) {
                cout << p[j] << " \n"[j == n];
            }
            swap(p[a[p2[res.se]].id], p[a[p2[i]].id]);
            for (int j = 1; j <= n; j++) {
                cout << p[j] << " \n"[j == n];
            }
            return ;
        }
        upd(1, 1, n, i, a[id].r);
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
