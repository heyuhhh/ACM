// Author : heyuhhh
// Created Time : 2020/07/26 11:22:01
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
const int N = 1e5 + 5;

int n;
int f[N][20], lg[N];

void init() {
    lg[2] = 1;
    for (int i = 3; i < N; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << (j - 1)) <= n) {
                f[i][j] = (f[i][j - 1] & f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return (f[l][k] & f[r - (1 << k) + 1][k]);
}

map<int, vector<pii>> mp;
vector<pii> v[N];

int rt[N], tot;
int lc[N * 30 * 23], rc[N * 30 * 23], sumv[N * 30 * 23];

void build(int &o, int l, int r) {
    o = ++tot;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc[o], l, mid); build(rc[o], mid + 1, r);
}

void insert(int& o, int last, int l, int r, int p, int v) {
    o = ++tot;
    lc[o] = lc[last], rc[o] = rc[last];
    sumv[o] = sumv[last] + v;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (p <= mid) insert(lc[o], lc[last], l, mid, p, v);
    else insert(rc[o], rc[last], mid + 1, r, p, v);
}

int query(int o, int l, int r, int L, int R) {
    if (!o) return 0;
    if (L <= l && r <= R) {
        return sumv[o];
    }
    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) {
        res += query(lc[o], l, mid, L, R);
    }
    if (R > mid) {
        res += query(rc[o], mid + 1, r, L, R);
    }
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0];
    }
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int l = j + 1, r = n + 1, mid;
            int k = query(i, j);
            while (l < r) {
                mid = (l + r) >> 1;
                if (query(i, mid) == k) l = mid + 1;
                else r = mid;
            }
            mp[k].push_back(MP(i, j));
            // cout << k << ' ' << i << ' ' << l - 1 << '\n';
            j = l - 1;
        }
    }
    for (auto it : mp) {
        sort(all(it.se), [&](pii A, pii B) {
            if (A.fi != B.fi) return A.fi < B.fi;
            return A.se < B.se;
        });
        vector<pii>& now = it.se;
        for (int i = 0; i < sz(now); i++) {
            v[now[i].se].push_back(MP(now[i].fi, 1));
            if (i) {
                v[now[i].se].push_back(MP(now[i - 1].fi, -1));
            }
        }
    }
    build(rt[0], 1, n);
    for (int i = 1; i <= n; i++) {
        sort(all(v[i]));
        rt[i] = rt[i - 1];
        for (auto it : v[i]) {
            insert(rt[i], rt[i], 1, n, it.fi, it.se);
        }
    }
    int q; cin >> q;
    int lastans = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l ^ lastans) % n + 1;
        r = (r ^ lastans) % n + 1;
        if (l > r) swap(l, r);
        int ans = query(rt[r], 1, n, l, r);
        cout << ans << '\n';
        lastans = ans;
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