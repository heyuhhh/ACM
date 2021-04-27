// Author : heyuhhh
// Created Time : 2020/10/02 15:49:06
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
const int N = 5e5 + 5;

int n, m, q;
int len[N], st[N], at[N], tot;
int a[N];

struct node {
    int idx, left, i;
};

struct SegTree {
    node tr[N << 2], lz[N << 2];
    void tag(int o, node v) {
        tr[o] = lz[o] = v;
    }
    void push_down(int o) {
        if(lz[o].i != 0) {
            tag(o << 1, lz[o]);
            tag(o << 1|1, lz[o]);
            lz[o] = node{0, 0, 0}; 
        }
    }
    void update(int o, int l, int r, int L, int R, node v) {
        if(L <= l && r <= R) {
            tag(o, v);
            return;
        }   
        push_down(o);
        int mid = (l + r) >> 1;
        if(L <= mid) update(o << 1, l, mid, L, R, v);
        if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    }
    node query(int o, int l, int r, int p) {
        if (l == r) {
            return tr[o];
        }
        push_down(o);
        int mid = (l + r) >> 1;
        if (p <= mid) return query(o << 1, l, mid, p);
        return query(o << 1|1, mid + 1, r, p);
    }
}seg;

struct SegTree2 {
    int val[N << 2], lz[N << 2];
    void push_down(int o) {
        if(lz[o] != 0) {
            lz[o << 1] += lz[o];
            lz[o << 1|1] += lz[o];
            lz[o] = 0;
        }
    }
    void build(int o, int l, int r) {
        lz[o] = 0;
        if(l == r) {
            val[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    }    
    void update(int o, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            ++lz[o];
            return;
        }   
        push_down(o);
        int mid = (l + r) >> 1;
        if(L <= mid) update(o << 1, l, mid, L, R);
        if(R > mid) update(o << 1|1, mid + 1, r, L, R);
    }    
    int query(int o, int l, int r, int p) {
        if (l == r) {
            return val[o] + lz[o];
        }
        push_down(o);
        int mid = (l + r) >> 1;
        if (p <= mid) return query(o << 1, l, mid, p);
        return query(o << 1|1, mid + 1, r, p);
    }
}seg2;

int ans[N];

void run() {
    memset(ans, -1, sizeof(ans));
    cin >> n >> m >> q;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        st[i] = tot;
        cin >> len[i];
        for (int j = st[i]; j < st[i] + len[i]; j++) {
            cin >> a[j];
        }
        tot += len[i];
    }
    for (int i = 1; i <= m; i++) {
        at[i] = 1;
    }
    map<pii, vector<pii>> mp;
    vector<pair<int, pii>> querys;
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, p;
            cin >> x >> p;
            seg.update(1, 1, n, p, p + len[x] - 1, node{x, p, at[x]});
        } else if (op == 2) {
            int p;
            cin >> p;
            node cur = seg.query(1, 1, n, p);
            if (cur.i == 0) {
                ans[i] = 0;
                continue;
            }
            mp[MP(cur.idx, cur.i)].emplace_back(p - cur.left + st[cur.idx], i);
        } else {
            int x, l, r;
            cin >> x >> l >> r;
            ++at[x];
            querys.emplace_back(MP(x, MP(st[x] + l - 1, st[x] + r - 1)));
        }
    }
    seg2.build(1, 1, tot - 1);
    for (int i = 1; i <= m; i++) {
        at[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (auto it : mp[MP(i, 1)]) {
            int T = it.se, pos = it.fi;
            ans[T] = seg2.query(1, 1, tot - 1, pos);
        }
    }
    for (auto it : querys) {
        int x = it.fi;
        int l = it.se.fi, r = it.se.se;
        ++at[x];
        seg2.update(1, 1, tot - 1, l, r);
        for (auto it2 : mp[MP(x, at[x])]) {
            int T = it2.se, pos = it2.fi;
            ans[T] = seg2.query(1, 1, tot - 1, pos);
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i] != -1) {
            cout << ans[i] % 256 << '\n';
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