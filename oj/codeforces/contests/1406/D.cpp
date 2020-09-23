// Author : heyuhhh
// Created Time : 2020/09/12 23:25:30
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

ll sumv[N << 2], lz[N << 2];
int a[N];

void tag(int o, int l, int r, ll v) {
    sumv[o] += 1ll * (r - l + 1) * v;
    lz[o] += v;
}

void push_up(int o) {
    sumv[o] = sumv[o << 1] + sumv[o << 1|1];
}

void push_down(int o, int l, int r) {
    if(lz[o] != 0) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;   
    }
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void build(int o, int l, int r) {
    if(l == r) {
        sumv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}

ll query(int o, int l, int r, int p) {
    if (l == r) {
        return sumv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if (p <= mid)
        return query(o << 1, l, mid, p);
    else
        return query(o << 1|1, mid + 1, r, p);
}

struct BIT {
    ll c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, ll v) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    ll query(int x) {
        ll res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);   
    }
    void modify(int x, ll v) {
        ll pre = query(x, x);
        ll d = v - pre;
        add(x, d);
    }
}bit; 

int n;

ll get() {
    ll now = query(1, 1, n, 1) + bit.query(n);
    if (now > 0) {
        return (now + 1) / 2;
    } else {
        return now / 2;
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] >= 0) {
            bit.add(i, a[i] - a[i - 1]);
        }
    }
    build(1, 1, n);
    cout << get() << '\n';
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, n, l, r, x);
        ll L = query(1, 1, n, l), R = query(1, 1, n, r);
        if (l > 1) {
            ll LL = query(1, 1, n, l - 1);
            bit.modify(l, max(0ll, L - LL));
        }
        if (r < n) {
            ll RR = query(1, 1, n, r + 1);
            bit.modify(r + 1, max(0ll, RR - R));
        }
        cout << get() << '\n';
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