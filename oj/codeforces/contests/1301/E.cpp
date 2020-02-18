/*
 * Author:  heyuhhh
 * Created Time:  2020/2/14 18:51:29
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
const int N = 500 + 5;

int n, m, q;
char s[N][N];
ll a[N][N];
int b[N][N], c[N][N];
int x[2], y[2];

ll sum(int x1, int y1, int x2, int y2) {
    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

bool chk(int sx, int sy, int l, ll x) {
    if(sx + l - 1 > n || sy + l - 1 > m) return false;
    return sum(sx, sy, sx + l - 1, sy + l - 1) == 1ll * l * l * x;
}

struct yTree {
    int maxv[N << 2], minv[N << 2];
    void build(int o, int l, int r, int L, int R) {
        if(l == r) {
            for(int i = L; i <= R; i++) {
                maxv[o] = max(maxv[o], c[i][l]);
            }   
            return ;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid, L, R);
        build(o << 1|1, mid + 1, r, L, R);
        maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
    }
    pii query(int o, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            return MP(minv[o], maxv[o]);
        }   
        int mid = (l + r) >> 1;
        pii res(INF, 0);
        if(L <= mid) res = query(o << 1, l, mid, L, R);
        if(R > mid) {
            pii tmp = query(o << 1|1, mid + 1, r, L, R);
            if(tmp.fi < res.fi) res.fi = tmp.fi;
            if(tmp.se > res.se) res.se = tmp.se;
        }
        return res;
    }
};

struct xTree {
    yTree t[N << 2];
    void build(int o, int l, int r) {
        t[o].build(1, 1, m, l, r);
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1|1, mid + 1, r);
    }
    pii query(int o, int l, int r, int L, int R, int L2, int R2) {
        if(L <= l && r <= R) {
            return t[o].query(1, 1, m, L2, R2);
        }   
        int mid = (l + r) >> 1;
        pii res(INF, 0);
        if(L <= mid) res = query(o << 1, l, mid, L, R, L2, R2);
        if(R > mid) {
            pii tmp = query(o << 1|1, mid + 1, r, L, R, L2, R2);
            if(tmp.fi < res.fi) res.fi = tmp.fi;
            if(tmp.se > res.se) res.se = tmp.se;
        }
        return res;
    }
}X;

bool chk(int sx, int sy, int ex, int ey, int x) {
    if(ex < sx || ey < sy) return 0;
    pii res = X.query(1, 1, n, sx, ex, sy, ey);
    return x <= res.se;
}

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == 'R') a[i][j] = 0;
            else if(s[i][j] == 'G') a[i][j] = 1;
            else if(s[i][j] == 'Y') a[i][j] = 1 + n * m;
            else a[i][j] = 1ll * n * n * m * m + n * m + 1;
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j];
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] += a[i][j - 1];
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ll x;
            if(s[i][j] == 'R') {
                x = 0;
            } else if(s[i][j] == 'G') {
                x = 1;
            } else if(s[i][j] == 'Y') {
                x = n * m + 1;
            } else {
                x = n * n * m * m + n * m + 1;
            }
            int l = 1, r = max(n, m) + 1, mid;
            while(l < r) {
                mid = (l + r) >> 1;
                if(chk(i, j, mid, x)) l = mid + 1;
                else r = mid;   
            }
            b[i][j] = l - 1;
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(s[i][j] == 'R') {
            int l = b[i][j];
            if(i + l > n || j + l > m) continue;
            if(s[i][j + l] == 'G' && b[i][j + l] >= l) {
                if(s[i + l][j] == 'Y' && b[i + l][j] == l) {
                    if(s[i + l][j + l] == 'B' && b[i + l][j + l] >= l) {
                        c[i + l - 1][j + l - 1] = max(c[i + l - 1][j + l - 1], l);
                    }
                }   
            }
        }   
    }
    X.build(1, 1, n);
    while(q--) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        int l = 0, r = max(n, m) + 1, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(chk(x[0] + mid - 1, y[0] + mid - 1, x[1] - mid, y[1] - mid, mid)) l = mid + 1;
            else r = mid;   
        }
        cout << 4 * (l - 1) * (l - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> q) run();
    return 0;
}
