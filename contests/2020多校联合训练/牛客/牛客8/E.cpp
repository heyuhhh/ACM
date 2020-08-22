// Author : heyuhhh
// Created Time : 2020/08/03 13:00:26
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

const int MAX = 100000;

ll ans[N];

struct segment_tree {
    ll flag[N << 2];
    void tag(int o, int v) {
        flag[o] += v;
    }
    void update(int o, int l, int r, int L, int R, int v) {
        R = min(R, MAX);
        if (L > MAX) return;
        if(L <= l && r <= R) {
            tag(o, v);
            return;
        }   
        int mid = (l + r) >> 1;
        if(L <= mid) update(o << 1, l, mid, L, R, v);
        if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    }
    ll res;
    void query(int o, int l, int r, int p) {
        r = min(r, MAX);
        if (l > MAX) return;
        res += flag[o];
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (p <= mid) query(o << 1, l, mid, p);
        else query(o << 1|1, mid + 1, r, p);
    }
    ll query(int p) {
        res = 0;
        query(1, 1, MAX, p);
        return res;
    }
}A, B;


void run() {
    for (int x = 1; x <= MAX; ++x) {
        for (int m = 3; m <= MAX; ++m) {
            ll L = 1ll * m * x + 3, R = 1ll * m * (x + 2) - 3;
            if (L > (ll)MAX) break;

            int mid = (L + R) >> 1;
            if ((R - L + 1) % 4 == 3) {
                if (L & 1) {
                    B.update(1, 1, MAX, L, mid, 1);
                    A.update(1, 1, MAX, mid + 2, R + 1, -1);
                } else {
                    A.update(1, 1, MAX, L, mid, 1);
                    B.update(1, 1, MAX, mid + 2, R + 1, -1);
                }
            } else {
                if (L & 1) {
                    B.update(1, 1, MAX, L, mid, 1);
                    A.update(1, 1, MAX, mid + 1, R + 1, -1);
                } else {
                    A.update(1, 1, MAX, L, mid, 1);
                    B.update(1, 1, MAX, mid + 1, R + 1, -1);
                }
            }

        }
    }
    for (int i = 1; i <= MAX; i++) {
        ans[i] = (i & 1 ? B.query(i) : A.query(i));
    }
    for (int i = 1; i <= MAX; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= MAX; i++) {
        ans[i] += ans[i - 1];
    }
    int T;
    cin >> T;
    int _ = 0;
    while (T--) {
        ++_;
        int l, r;
        cin >> l >> r;
        cout << "Case #" << _ << ": ";
        cout << ans[r] - ans[l - 1] << '\n';
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