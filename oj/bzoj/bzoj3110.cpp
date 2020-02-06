/*
 * Author:  heyuhhh
 * Created Time:  2020/2/5 20:14:53
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
const int N = 50000 + 5, M = 20000000;

int n, m, D;
int a[N], b[N], op[N];
ll c[N], d[N], e[N];
int rt[N << 2], T;

ll sumv[M];
int ls[M], rs[M], lz[M];

void tag(int &o, int l, int r, int v) {
    if(!o) o = ++T;
    sumv[o] += 1ll * (r - l + 1) * v;
    lz[o] += v;
}
void push_down(int o, int l, int r) {
    if(lz[o]) {
        int mid = (l + r) >> 1;
        tag(ls[o], l, mid, lz[o]);
        tag(rs[o], mid + 1, r, lz[o]);
        lz[o] = 0;   
    }
}
void update(int &o, int l, int r, int L, int R) {
    if(!o) o = ++T;
    if(L <= l && r <= R) {
        tag(o, l, r, 1);
        return;
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(ls[o], l, mid, L, R);
    if(R > mid) update(rs[o], mid + 1, r, L, R);
    sumv[o] = sumv[ls[o]] + sumv[rs[o]];
}

void update(int o, int l, int r, int L, int R, int v) {
    update(rt[o], 1, n, L, R);
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(v <= mid) update(o << 1, l, mid, L, R, v);
    else update(o << 1|1, mid + 1, r, L, R, v);
}

ll query(int &o, int l, int r, int L, int R) {
    if(!o) return 0;
    if(L <= l && r <= R) return sumv[o];
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(L <= mid) res += query(ls[o], l, mid, L, R);
    if(R > mid) res += query(rs[o], mid + 1, r, L, R);
    return res;
}

int query(int o, int l, int r, int L, int R, ll c) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    ll x = query(rt[o << 1|1], 1, n, L, R);
    if(x >= c) return query(o << 1|1, mid + 1, r, L, R, c);
    else return query(o << 1, l, mid, L, R, c - x);
}

void run(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> op[i] >> a[i] >> b[i] >> c[i];
        if(op[i] == 1) d[++D] = c[i];
    }
    sort(d + 1, d + D + 1);
    D = unique(d + 1, d + D + 1) - d - 1;
    for(int i = 1; i <= m; i++) if(op[i] == 1) {
        ll t = c[i];
        c[i] = lower_bound(d + 1, d + D + 1, c[i]) - d;   
        e[c[i]] = t;
    }
    for(int i = 1; i <= m; i++) {
        if(op[i] == 1) {
            update(1, 1, D, a[i], b[i], c[i]);
        } else {
            int x = query(1, 1, D, a[i], b[i], c[i]);
            cout << e[x] << '\n';
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
