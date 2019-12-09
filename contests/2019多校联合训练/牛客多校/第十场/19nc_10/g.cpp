#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, \
  ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

typedef long long LL;
typedef unsigned long long ULL;

struct point {
    double x, y;

    point(double x, double y) : x(x), y(y) {}
    point operator + (point rhs) { return {x + rhs.x, y + rhs.y}; }
    point operator - (point rhs) { return {x - rhs.x, y - rhs.y}; }
    point operator * (double k) { return {k * x, k * y}; }
    point rot() { return {-y, x}; }
    double operator * (point rhs) { return x * rhs.y - y * rhs.x; }
    double length() { return hypot(x, y); }
};

int n;
vector<point> pts;

pair<double, double> check(point vec) {
    vector<double> res;
    rep (i, n)
        res.push_back(pts[i] * vec / vec.length());
    nth_element(res.begin(), res.begin() + n / 2 - 1, res.end());
    double d1 = res[n/2-1];
    nth_element(res.begin(), res.begin() + n / 2, res.end());
    double d2 = res[n/2];
    return {(d2 - d1) / 2.0, (d1 + d2) / 2.0};
}

pair<double, double> ans1(0.0, 0.0), ans2(0.0, 0.0);
pair<int, int> id1, id2;

void solve1() { // mid
    rep (i, n) {
        rep (j, i) {
            auto cur = check((pts[i] - pts[j]).rot());
            if (cur > ans1) {
                ans1 = cur;
                id1 = {i, j};
            }
        }
    }
}

void solve2() { // parallel
    rep (i, n) {
        rep (j, i) {
            auto cur = check(pts[i] - pts[j]);
            if (cur > ans2) {
                ans2 = cur;
                id2 = {i, j};
            }
        }
    }
}

int main() {
    cin >> n;
    rep (i, n) {
        double x, y; cin >> x >> y;
        pts.emplace_back(x, y);
    }
    solve1(); solve2();
    double ans = max(ans1, ans2).first;
    printf("%.12f\n", ans);
#ifdef DEBUG_INFO
    if (ans1 > ans2) {
        point vec = (pts[id1.first] - pts[id1.second]).rot(); vec = vec * (1.0 / vec.length());
        point init = vec.rot() * -ans1.second;
        point p1 = init - vec * 2000000.0, p2 = init + vec * 2000000.0;
        fprintf(stderr, "1 %d %d\n", id1.first, id1.second);
        fprintf(stderr, "%.9f %.9f %.9f %.9f\n", p1.x, p1.y, p2.x, p2.y);
    } else {
        point vec = pts[id2.first] - pts[id2.second]; vec = vec * (1.0 / vec.length());
        point init = vec.rot() * -ans2.second;
        point p1 = init - vec * 2000000.0, p2 = init + vec * 2000000.0;
        fprintf(stderr, "2 %d %d\n", id2.first, id2.second);
        fprintf(stderr, "%.9f %.9f %.9f %.9f\n", p1.x, p1.y, p2.x, p2.y);
    }
#endif
    return 0;
}
