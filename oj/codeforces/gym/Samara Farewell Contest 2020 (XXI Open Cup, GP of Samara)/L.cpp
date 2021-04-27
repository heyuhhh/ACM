// Author : heyuhhh
// Created Time : 2021/03/10 14:27:40
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
const int N = 1e6 + 5;

int a[N], cnt[N], has[N];
pii minv[N << 2];

pii upd(pii A, pii B) {
    pii res = A;
    if (B.fi < res.fi) {
        res = B;
    } else if (B.fi == res.fi) {
        res.se = max(res.se, B.se);
    }
    return res;
}

void push_up(int o) {
    minv[o] = upd(minv[o << 1], minv[o << 1|1]);
};

void build(int o, int l, int r) {
    if (l == r) {
        minv[o] = MP(cnt[l], l);
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int p) {
    if (l == r) {
        --minv[o].fi;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(o << 1, l, mid, p);
    else update(o << 1|1, mid + 1, r, p);
    push_up(o);
}

pii query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return minv[o];
    }
    int mid = (l + r) >> 1;
    pii res = MP(INF, -1);
    if (L <= mid) res = query(o << 1, l, mid, L, R);
    if (R > mid) res = upd(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}

void run() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i = 1; i <= k; i++) {
        if (cnt[i] == 0) {
            cout << 0 << '\n';
            return;
        }
        has[i] = cnt[i];
    }
    build(1, 1, k);
    int ans = INF;
    int t1, t2;
    bool f = false;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x < n) {
            int tmp = cnt[x] - has[x];
            auto it = query(1, 1, k, x + 1, k);
            int res = it.fi + tmp;
            if (res < ans) {
                ans = res;
                t1 = i;
                t2 = it.se;
            }
        }
        update(1, 1, k, x);
        --has[x];
    }
    for (int i = 1; i <= k; i++) {
        if (cnt[i] < ans) {
            f = true;
            ans = cnt[i];
            t1 = i;
        }
    }
    cout << ans << '\n';
    // cout << t1 << ' ' << t2 << '\n';
    if (f) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == t1) {
                cout << i << ' ';
            }
        }
    } else {
        for (int i = 1; i < t1; i++) {
            if (a[i] == a[t1]) {
                cout << i << ' ';
            }
        }
        for (int i = t1 + 1; i <= n; i++) {
            if (a[i] == t2) {
                cout << i << ' ';
            }
        }
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}