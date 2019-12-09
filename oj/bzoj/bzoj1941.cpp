/*
 * Author:  heyuhhh
 * Created Time:  2019/11/25 19:33:50
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
//#define Local
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
const int N = 5e5 + 5;

int n;
int x[N], y[N];

int D;
struct Point {
    int mn[2], mx[2];
    int d[2], l, r;
    int& operator [] (int x) {return d[x];}
    bool operator < (const Point &A) const {
        return d[D] < A.d[D];
    }
    Point(int x = 0, int y = 0) {
        d[0] = x, d[1] = y;
        l = r = 0;
        mn[0] = mx[0] = x;
        mn[1] = mx[1] = y;   
    }
}p[N];
int rt;
struct kdtree {
    Point tr[N];
    int ans, tot;
    void push_up(int o) {
        Point f = tr[o];
        Point ls = tr[f.l], rs = tr[f.r];
        for(int i = 0; i < 2; i++) {
            if(f.l) tr[o].mn[i] = min(tr[o].mn[i], ls.mn[i]), tr[o].mx[i] = max(tr[o].mx[i], ls.mx[i]);
            if(f.r) tr[o].mn[i] = min(tr[o].mn[i], rs.mn[i]), tr[o].mx[i] = max(tr[o].mx[i], rs.mx[i]);
        }
    }
    int build(int l, int r, int now) {
        int mid = (l + r) >> 1;
        D = now;
        nth_element(p + l, p + mid, p + r + 1);
        tr[mid] = p[mid];
        if(l < mid) tr[mid].l = build(l, mid - 1, now ^ 1);
        if(r > mid) tr[mid].r = build(mid + 1, r, now ^ 1);
        push_up(mid);   
        return mid;
    }
    int get(Point t1, Point t2) {
        int res = 0;
        for(int i = 0; i < 2; i++) {
            res += max(0, t1[i] - t2.mx[i]) + max(0, t2.mn[i] - t1[i]);
        }
        return res;
    }
    int dis(Point t1, Point t2) {
        int res = 0;
        for(int i = 0; i < 2; i++) {
            res += abs(t1[i] - t2[i]);   
        }
        return res;   
    }
    int get2(Point t1, Point t2) {
        int res = 0;
        for(int i = 0; i < 2; i++) {
            res += max(abs(t1[i] - t2.mx[i]), abs(t1[i] - t2.mn[i]));   
        }
        return res;
    }
    void query_min(int o, int now, Point T) {
        int lv = INF, rv = INF;
        int ok = 0;
        for(int i = 0; i < 2; i++) {
            if(T[i] != tr[o][i]) ok = 1;
        }
        if(ok) ans = min(ans, dis(T, tr[o]));
        if(tr[o].l) lv = get(T, tr[tr[o].l]);
        if(tr[o].r) rv = get(T, tr[tr[o].r]);
        if(lv < rv) {
            if(lv < ans) query_min(tr[o].l, now ^ 1, T);
            if(rv < ans) query_min(tr[o].r, now ^ 1, T);
        } else {
            if(rv < ans) query_min(tr[o].r, now ^ 1, T);
            if(lv < ans) query_min(tr[o].l, now ^ 1, T);
        }
    }
    void query_max(int o, int now, Point T) {
        int lv = 0, rv = 0;
        int ok = 0;
        for(int i = 0; i < 2; i++) {
            if(T[i] != tr[o][i]) ok = 1;   
        }
        if(ok) ans = max(ans, dis(T, tr[o]));
        if(tr[o].l) lv = get2(T, tr[tr[o].l]);
        if(tr[o].r) rv = get2(T, tr[tr[o].r]);
        if(lv > rv) {
            if(lv > ans) query_max(tr[o].l, now ^ 1, T);
            if(rv > ans) query_max(tr[o].r, now ^ 1, T);
        } else {
            if(rv > ans) query_max(tr[o].r, now ^ 1, T);
            if(lv > ans) query_max(tr[o].l, now ^ 1, T);
        }
    }
    int query_min(int x, int y) {
        ans = INF;
        query_min(rt, 0, Point(x, y));
        return ans;
    }
    int query_max(int x, int y) {
        ans = 0;
        query_max(rt, 0, Point(x, y));
        return ans;
    }
}kd;

void run(){
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[i] = Point(x[i], y[i]);
    }
    rt = kd.build(1, n, 0);
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        int Min = kd.query_min(x[i], y[i]);
        int Max = kd.query_max(x[i], y[i]);
        ans = min(ans, Max - Min);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
