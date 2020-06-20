/*
 * Author:  heyuhhh
 * Created Time:  2020/6/15 16:24:12
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;
const double eps = 1e-5;

int n, t;
int a[N], b[N];
vector <pii> v[N];

double c[N];

struct BIT {
    double c[N];
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, double v) {
        for (; x > 0; x -= lowbit(x)) {
            c[x] = min(c[x], v);
        }
    }
    double query(int x) {
        if (x == 0) return 0;
        double res = 1e9;
        for (; x <= t; x += lowbit(x)) {
            res = min(res, c[x]);
        }
        return res;
    }
}bit;

double check(double x) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = (double)a[i] - 1.0 * b[i] * x;
    }
    for (int i = 1; i <= t; i++) {
        bit.c[i] = 1e9;
    }
    for (int i = 1; i <= t; i++) {
        for (auto it : v[i]) {
            int l = it.fi, r = i, id = it.se;
            double now = bit.query(l - 1);
            bit.update(i, now + c[id]);
        }
    }
    return bit.query(t) <= 0;
}

void run() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i <= t; i++) {
        v[t].clear();
    }
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        v[r].emplace_back(MP(l, i));
        scanf("%d%d", &a[i], &b[i]);
    }
    double l = 0, r = 1001, mid;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.3f\n", r);
}

int main() {
    int T; scanf("%d", &T); while(T--)
    run();
    return 0;
}
