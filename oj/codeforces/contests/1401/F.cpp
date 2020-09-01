// Author : heyuhhh
// Created Time : 2020/08/22 11:02:23
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

ll sumv[N << 2];
int rev[N << 2], rev2[N << 2];

int n, q;
int a[N];

void pushup(int o) {
    sumv[o] = sumv[o << 1] + sumv[o << 1|1];
}

void build(int o, int l, int r) {
    if (l == r) {
        sumv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1|1, mid + 1, r);
    pushup(o);
}

void modify(int o, int l, int r, int p, int v, int f) {
    f ^= rev2[r - l + 1];
    if (l == r) {
        sumv[o] = v;
        return;
    }
    int now = (f ^ rev[r - l + 1]);
    if (now) {
        int mid = (l + r) >> 1;
        int len = mid - l + 1;
        if (p <= mid) {
            modify(o << 1|1, mid + 1, r, p + len, v, f);
        } else {
            modify(o << 1, l, mid, p - len, v, f);
        }
    } else {
        int mid = (l + r) >> 1;
        if (p <= mid) modify(o << 1, l, mid, p, v, f);
        else modify(o << 1|1, mid + 1, r, p, v, f);
    }
    pushup(o);
}

ll query(int o, int l, int r, int L, int R, int f) {
    f ^= rev2[r - l + 1];
    if (l >= L && r <= R) {
        return sumv[o];
    }
    int now = (f ^ rev[r - l + 1]);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (now) {
        int len = mid - l + 1;
        if (L <= mid) {
            res += query(o << 1|1, mid + 1, r, min(r, L + len), min(R + len, r), f);
        }
        if (R > mid) {
            res += query(o << 1, l, mid, max(l, L - len), max(l, R - len), f);
        }
    } else {
        if (L <= mid) res += query(o << 1, l, mid, L, min(mid, R), f);
        if (R > mid) res += query(o << 1|1, mid + 1, r, max(mid + 1, L), R, f);
    }
    return res;
}

void run() {
    cin >> n >> q;
    for (int i = 1; i <= 1 << n; i++) {
        cin >> a[i];
    }
    build(1, 1, 1 << n);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            modify(1, 1, 1 << n, x, k, 0);
        } else if (op == 2) {
            int k;
            cin >> k;
            rev2[1 << k] ^= 1;
        } else if (op == 3) {
            int k;
            cin >> k;
            rev[1 << (k + 1)] ^= 1;
        } else {
            int l, r;
            cin >> l >> r;
            ll res = query(1, 1, 1 << n, l, r, 0);
            cout << res << '\n';
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