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

int n, t;
int a[N], b[N];
vector <pii> v[N];

ll c[N];

struct BIT {
    ll c[N];
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, ll v) {
        ++x;
        x = t + 1 - x + 1;
        for (; x <= t + 1; x += lowbit(x)) {
            c[x] = min(c[x], v);
        }
    }
    ll query(int x) {
        ++x;
        x = t + 1 - x + 1;
        ll res = 1e18;
        for (; x; x -= lowbit(x)) {
            res = min(res, c[x]);
        }
        return res;
    }
}bit;

ll check(int x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] - 1ll * b[i] * x;
    }
    for (int i = 0; i <= t + 1; i++) {
        bit.c[i] = 1e18;
    }
    bit.update(0, 0);
    for (int i = 1; i <= t; i++) {
        for (auto it : v[i]) {
            int l = it.fi, r = i, id = it.se;
            ll now = bit.query(l - 1);
            if (c[id] < 0) res -= c[id], c[id] = 0;
            bit.update(i, now + c[id]);
        }
    }
    return bit.query(t) <= res;
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
        a[i] *= 10000;
    }
    int l = 0, r = 1e7 + 5, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    double ans = 1.0 * r / 10000;
    printf("%.3f\n", ans);
}

int main() {
    int T; scanf("%d", &T); while(T--)
    run();
    return 0;
}
