/*
 * Author:  heyuhhh
 * Created Time:  2020/2/11 15:41:25
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
#define INF 0x3f3f3f3f3f3f3f3f
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
const int N = 2000 + 5;

int n, m1, m2;
int x[2], y[2];
ll a[N][N];

struct yTree {
    ll maxv[N << 2];
    void build(int o, int l, int r, int L, int R) {
        if(l == r) {
            for(int i = L; i <= R; i++) {
                maxv[o] = max(maxv[o], a[i][l]);
            }   
            return ;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid, L, R);
        build(o << 1|1, mid + 1, r, L, R);
        maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
    }
    ll query(int o, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            return maxv[o];
        }   
        ll res = 0; int mid = (l + r) >> 1;
        if(L <= mid) res = query(o << 1, l, mid, L, R);
        if(R > mid) res = max(res, query(o << 1|1, mid + 1, r, L, R));
        return res;
    }
};

struct xTree {
    yTree t[N << 2];
    void build(int o, int l, int r) {
        t[o].build(1, 1, n, l, r);
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1|1, mid + 1, r);
    }
    ll query(int o, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            return t[o].query(1, 1, n, y[0], y[1]);
        }   
        ll res = 0; int mid = (l + r) >> 1;
        if(L <= mid) res = query(o << 1, l, mid, L, R);
        if(R > mid) res = max(res, query(o << 1|1, mid + 1, r, L, R));
        return res;
    }
}X;

void run() {
    for(int i = 1; i <= m1; i++) {
        int w;
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> w;
        a[x[0]][y[0]] += w;
        a[x[1] + 1][y[1] + 1] += w;
        a[x[1] + 1][y[0]] -= w;
        a[x[0]][y[1] + 1] -= w;
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            a[i][j] += a[i - 1][j];
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
        }
    }
    X.build(1, 1, n);
    for(int i = 1; i <= m2; i++) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        ll ans = X.query(1, 1, n, x[0], x[1]);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m1 >> m2) run();
    return 0;
}
