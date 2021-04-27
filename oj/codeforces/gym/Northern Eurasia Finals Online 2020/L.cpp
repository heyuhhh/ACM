// Author : heyuhhh
// Created Time : 2021/02/27 12:46:34
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

struct Fenwick_tree {
    int c[N];
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x) {
        for (; x < N; x += lowbit(x)) {
            ++c[x];
        }
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
} bit;

int v[N], ls[N], rs[N];
int minv[N], maxv[N];

struct seg {
    int l, r, t;
};

void dfs(int u) {
    if (u == 0) return;
    minv[u] = maxv[u] = v[u];
    dfs(ls[u]);
    dfs(rs[u]);
    minv[u] = min({minv[u], minv[ls[u]], minv[rs[u]]});
    maxv[u] = max({maxv[u], maxv[ls[u]], maxv[rs[u]]});
}

void run() {
    minv[0] = INF, maxv[0] = -INF;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i] >> rs[i] >> v[i];
    }
    dfs(1);
    vector<seg> v;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        v.emplace_back(seg{minv[i], maxv[i], 0});
        tmp.emplace_back(minv[i]);
        tmp.emplace_back(maxv[i]);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(seg{l, r, i});
        tmp.emplace_back(l);
        tmp.emplace_back(r);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (auto& it : v) {
        it.l = lower_bound(all(tmp), it.l) - tmp.begin() + 1;
        it.r = lower_bound(all(tmp), it.r) - tmp.begin() + 1;
    }
    sort(all(v), [&] (seg A, seg B) {
        return A.l < B.l;
    });
    vector<int> suf(sz(tmp) + 2);
    for (int i = sz(tmp), j = sz(v) - 1; i >= 1; i--) {
        suf[i] = suf[i + 1];
        while (j >= 0 && v[j].l == i) {
            if (v[j].t == 0) ++suf[i];
            --j;
        }
    }
    sort(all(v), [&] (seg A, seg B) {
        if (A.r == B.r) return A.t < B.t;
        return A.r < B.r;
    });
    vector<int> pre(sz(tmp) + 1);
    for (int i = 1, j = 0; i <= sz(tmp); i++) {
        pre[i] = pre[i - 1];
        while (j < sz(v) && v[j].r == i) {
            if (v[j].t == 0) ++pre[i];
            ++j;
        }
    }
    vector<int> ans(q + 1);
    for (auto& it : v) {
        int l = it.l, r = it.r, t = it.t;
        if (t == 0) {
            bit.add(l);
        } else {
            ans[t] = pre[l - 1] + suf[r + 1] + bit.query(l, r);
        }
    }
    for (int i = 1; i <= q; i++) {
        ans[i] = 2 * (n - ans[i]) + 1;
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
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