// Author : heyuhhh
// Created Time : 2020/11/18 14:51:41
#include<bits/stdc++.h>
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
const int N = 2000 + 5;
#define y1 skljdfa

int _;

struct line {
    double x1, x2, y;
    int d;
    bool operator < (const line& A) const {
        return y < A.y;
    }
} l[N];
int n, m;

double x[N];
int D;
int find(double v) {
    return lower_bound(x + 1, x + D + 1, v) - x;
}

double sumv[N << 2];
int cnt[N << 2];

void pushup(int o, int l, int r) {
    if (cnt[o]) {
        sumv[o] = x[r + 1] - x[l];
    } else {
        sumv[o] = sumv[o << 1] + sumv[o << 1|1];
    }
}

void update(int o, int l, int r, int L, int R, int v) {
    if (l >= L && r <= R) {
        cnt[o] += v;
        pushup(o, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(o << 1, l, mid, L, R, v);
    if (R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    pushup(o, l, r);
}

void run() {
    ++_;
    m = 0;
    for (int i = 1; i <= n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        l[++m] = line{x1, x2, y1, 1};
        l[++m] = line{x1, x2, y2, -1};
        x[++D] = x1;
        x[++D] = x2;
    }
    sort(x + 1, x + D + 1);
    D = unique(x + 1, x + D + 1) - x - 1;
    memset(cnt, 0, sizeof(cnt));
    memset(sumv, 0, sizeof(sumv));
    sort(l + 1, l + m + 1);
    double ans = 0;
    for (int i = 1; i < m; i++) {
        int op = l[i].d;
        int L = find(l[i].x1);
        int R = find(l[i].x2) - 1;
        assert(L <= R);
        update(1, 1, D, L, R, op);
        if (i < m) ans += (l[i + 1].y - l[i].y) * sumv[1];
    }
    cout << "Test case #" << _ << '\n' << "Total explored area: ";
    cout << ans << '\n';
    cout << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    while (cin >> n && n) run();
    return 0;
}