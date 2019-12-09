#include <iostream>
#include <algorithm>
#include <functional>
#include <assert.h>

const int maxn = 2e5 + 7;

typedef std::pair<int, int> Pair;
struct GP {
    typedef std::function<void(int, Pair *, int*)> WFUNC;
    Pair v[maxn];
    int f[maxn];
    int sz;
    void init() {
        sz = 0;
    }

    void push(int a, int b) {
        v[++sz] = Pair(a, b);
    }

    WFUNC _work;
    GP(WFUNC _work) : _work(_work) {}
    void work() { _work(sz, v, f); }
    int operator()(const int idx) const { assert(0 <= idx); assert(idx <= sz * 2); return f[idx]; }

    void output() {
        printf("%d", f[1]);
        for (int i = 2; i <= 2 * sz; i++) printf(" %d", f[i]);
        puts("");
    }
} ;

GP gp1([](int n, Pair *v, int *f) {
    // a >= b
    static int o[maxn * 2];
    int sz = 0;
    for (int i = 1; i <= n; i++) o[++sz] = v[i].first, o[++sz] = v[i].second;
    std::sort(o + 1, o + sz + 1, std::greater<int>());
    f[0] = 0;
    for (int i = 1; i <= 2 * n; i++)
        f[i] = f[i - 1] + o[i];
}) ;

GP gp2([](int n, Pair *v, int *f) {
    // a < b
    sort(v + 1, v + n + 1,
        [](const Pair &a, const Pair &b) -> bool { return a.first + a.second > b.first + b.second; });

    f[0] = 0;
    for (int i = 1; i <= n; i++)
        f[2 * i] = f[2 * i - 2] + v[i].first + v[i].second;

    int mn = v[1].second;
    for (int i = 1; i <= n; i++) {
        if (v[i].second < mn) mn = v[i].second;
        f[2 * i - 1] = f[2 * i] - mn;
    }

    int mx = 0;
    for (int i = n; i >= 1; i--) {
        if (v[i].first > mx) mx = v[i].first;
        f[2 * i - 1] = std::max(f[2 * i - 1], f[2 * i - 2] + mx);
    }
}) ;

int main() {
    int n, t;
    scanf("%d", &t);
    auto find_cross = [](const GP &f, int n, int offset, int bias) -> int {
        // f: a non-decreasing, convex function.
        // return_value: the minimum k that f(k) < f(k - offset) + bias (offset < k <= n).
        // If such k doesn't exist, return n + 1
        assert(offset >= 1);
        assert(offset <= n + 1);
        int i = offset, j = n, mid;
        //std::cout << '#' << ' ' << offset << ' ' << n << std::endl;
        while (i <= j) {
            mid = (i + j) >> 1;
            assert(mid >= 0);
            assert(mid - offset >= 0);
            if (f(mid) >= f(mid - offset) + bias) i = mid + 1;
            else j = mid - 1;
        }
        //std::cout << '#' << i << std::endl;
        return i;
    } ;

    auto g = [&](int x, int y) -> int { return find_cross(gp1, 2 * gp1.sz, y - x, gp2(y) - gp2(x)) + x; };
    using namespace std;
    while (t--) {
        scanf("%d", &n);
        gp1.init();
        gp2.init();
        for (int i = 1, a, b; i <= n; i++) {
            scanf("%d%d", &a, &b);
            if (a >= b) gp1.push(a, b);
            else gp2.push(a, b);
        }
        gp1.work();
        gp2.work();
        if (gp1.sz == 0) { gp2.output(); continue; }
        if (gp2.sz == 0) { gp1.output(); continue; }

        //gp1.output();
        //gp2.output();

        int sz = 0;
        static int o[maxn];
        for (int i = 0; i <= 2 * gp2.sz; i++) {
            while (sz >= 2 && g(o[sz], i) <= g(o[sz - 1], o[sz])) {
                sz--;
            }
            o[++sz] = i;
        }
        /* for (int i = 1; i <= sz; i++) cout << o[i] << ' ';
        cout << endl;
        for (int i = 1; i < sz; i++) cout << g(o[i], o[i + 1]) << ' ';
        cout << endl; */

        //cout << g(0, 2) << '!' << endl;
        //cout << g(2, 4) << '!' << endl;

        int ptr = 1;
        printf("%d", std::max(gp1(1), gp2(1)));
        for (int i = 2; i <= 2 * n; i++) {
            while (ptr < sz && i >= g(o[ptr], o[ptr + 1])) ptr++;
            //cout << i << ' ' << o[ptr] << endl;
            printf(" %d", gp2(o[ptr]) + gp1(i - o[ptr]));
        }
        puts("");
    }
    return 0;
}
