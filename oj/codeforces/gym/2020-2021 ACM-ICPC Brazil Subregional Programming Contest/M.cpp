// Author : heyuhhh
// Created Time : 2020/12/10 17:22:55
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
const int BASE = 5782344, MOD = 1e9 + 7;

int poww[N];

void init() {
    poww[0] = 1;
    for (int i = 1; i < N; i++) {
        poww[i] = 1ll * poww[i - 1] * BASE % MOD;
    }
}

int n, q;
ll x[N], y[N], hs[N];
int id[N];

int ls[N * 22], rs[N * 22], sz[N * 22], rt[N], T;
list<int> val[N * 22];

void ins(int& o, int last, int l, int r, int id, int v) {
    o = ++T;
    ls[o] = ls[last];
    rs[o] = rs[last];
    sz[o] = sz[last] + 1;
    if (l == r) {
        val[o].splice(val[o].end(), val[last]);
        val[o].emplace_back(v);
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid) ins(ls[o], ls[last], l, mid, id, v);
    else ins(rs[o], rs[last], mid + 1, r, id, v);
}

vector<int> V;

void query(int o, int l, int r, int L, int R) {
    if (o == 0) return;
    if (l == r) {
        if (r <= R && sz[o]) {
            int res = 0;
            for (auto& it : val[o]) {
                V.emplace_back(it);
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (sz[ls[o]]) {
        query(ls[o], l, mid, L, R);
        if (sz[rs[o]]) {
            query(rs[o], mid + 1, r, L, R);
        }
    } else if (sz[rs[o]]) {
        query(rs[o], mid + 1, r, L, R);
    }
} 

void run() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        ll xx = 2 * y[i] - x[i];
        ll yy = -2 * y[i] - x[i];
        x[i] = xx, y[i] = yy;
        hs[++hs[0]] = y[i];
    }
    sort(hs + 1, hs + hs[0] + 1);
    hs[0] = unique(hs + 1, hs + hs[0] + 1) - hs - 1;
    for (int i = 1; i <= n; i++) {
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&] (int A, int B) {
        return x[A] < x[B];
    });
    for (int i = 1; i <= n; i++) {
        ins(rt[i], rt[i - 1], 1, hs[0], lower_bound(hs + 1, hs + hs[0] + 1, y[id[i]]) - hs, id[i]);
    }
    ll p = 0;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        a = -1 - (p + a) % MOD;
        b = (p + b) % MOD;
        ll xx = 2ll * b - a;
        ll yy = -2ll * b - a;
        a = xx, b = yy;
        int l = 1, r = n + 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (x[id[mid]] <= a) l = mid + 1;
            else r = mid;
        }
        int t = l - 1;
        int rb = upper_bound(hs + 1, hs + hs[0] + 1, b) - hs - 1;
        p = 0;
        if (t && rb) {
            V.clear();
            query(rt[t], 1, hs[0], 1, rb);
            sort(all(V));
            for (int i = 0; i < sz(V); i++) {
                p = (p + 1ll * poww[i] * V[i] % MOD) % MOD;
            }
        }
        cout << p << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
/*
a - 2 * b <= x - 2 * y
a + 2 * b <= x + 2 * y
*/