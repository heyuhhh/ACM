/*
 * Author:  heyuhhh
 * Created Time:  2020/3/1 22:51:58
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
const int N = 1e6 + 5;

int n, m, p;
pii a[N], b[N];
ll mina[N], minb[N];

struct monster {
    int x, y, z;  
    bool operator < (const monster &A) const {
        return x < A.x;   
    }
}c[N];

ll maxv[N << 2], lz[N << 2];
ll d[N];

void push_up(int o) {
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
}

void tag(int o, int l, int r, ll v) {
    maxv[o] += v;
    lz[o] += v;
}

void push_down(int o, int l, int r) {
    if(lz[o]) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;
    }   
}

void build(int o, int l, int r) {
    if(l == r) {
        maxv[o] = -d[l];
        return;
    }   
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

ll query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return maxv[o];   
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    ll res = -1e18;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = max(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    for(int i = 1; i <= m; i++) cin >> b[i].fi >> b[i].se;
    sort(a + 1, a + n + 1, [&](pii A, pii B) {
        return A.fi < B.fi;
    });
    sort(b + 1, b + m + 1, [&](pii A, pii B) {
        return A.fi < B.fi;
    });
    vector <int> aa;
    for(int i = 1; i <= n; i++) aa.push_back(a[i].fi);
    mina[n + 1] = minb[m + 1] = INF;
    for(int i = n; i >= 1; i--) mina[i] = min(mina[i + 1], (ll)a[i].se);
    for(int i = m; i >= 1; i--) minb[i] = min(minb[i + 1], (ll)b[i].se);
    for(int i = 1; i <= p; i++) {
        cin >> c[i].x >> c[i].y >> c[i].z;   
    }
    sort(c + 1, c + p + 1);
    memset(d, INF, sizeof(d));
    for(int i = 1; i <= m; i++) {
        d[b[i].fi] = min(d[b[i].fi], (ll)b[i].se);
    }
    build(1, 1, N - 1);
    ll ans = -mina[1] - minb[1];
    for(int i = 1; i <= p; i++) {
        update(1, 1, N - 1, c[i].y + 1, N - 1, c[i].z);
        ll t = query(1, 1, N - 1, c[i].y + 1, N - 1);
        int tt = upper_bound(all(aa), c[i].x) - aa.begin() + 1;
        ans = max(ans, t - mina[tt]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> p) run();
    return 0;
}
