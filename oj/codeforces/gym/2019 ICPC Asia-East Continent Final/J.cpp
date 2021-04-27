// Author : heyuhhh
// Created Time : 2021/03/31 11:13:25
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
const int N = 5e5 + 5, MOD = 998244353;
struct BIT {
    int c[N];
    int lowbit(int x) {return x & (-x);}
    void clear(int x) {
        for (++x; x < N; x += lowbit(x)) c[x] = 0;
    }
    void add(int x, int v = 1) {
        for(++x; x < N; x += lowbit(x)) c[x] += v;
    }
    int query(int x) {
        int res = 0;
        for(++x; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);   
    }
}bit; 

struct node {
    int l, r, info, v;
    bool operator < (const node& A) const {
        return l < A.l;
    }
};

void run() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        bit.clear(i);
    }
    vector<int> p(n);
    vector<int> at(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        at[p[i]] = i;
    }
    set<node> S;
    auto in = [&] (int x) {
        auto it = S.upper_bound(node{x, -1, -1, -1});
        if (it == S.begin()) return false;
        --it;
        int l = it -> l, r = it -> r;
        return l <= x && x <= r;
    };
    auto merge = [&] (int l, int r, int has, int op) {
        if (op == 1) {
            if (S.empty()) {
                return node{l, r, 1, r - l + 1 - has};
            }
            auto it = S.upper_bound(node{l, -1, -1, -1});
            if (it == S.begin()) {
                return node{l, r, 1, r - l + 1 - has};
            }
            --it;
            int L = it -> l, R = it -> r;
            if (R < l) {
                return node{l, r, 1, r - l + 1 - has};
            }
            S.erase(it);
            int used = R - L + 1 - (it -> v) + has;
            return node{L, r, 3, r - L + 1 - used};
        } else {
            if (S.empty()) {
                return node{l, r, 2, r - l + 1 - has};
            }
            auto it = S.upper_bound(node{r, -1, -1, -1});
            if (it == S.begin()) {
                return node{l, r, 2, r - l + 1 - has};
            }
            --it;
            int L = it -> l, R = it -> r;
            if (R < l) {
                return node{l, r, 2, r - l + 1 - has};
            }
            S.erase(it);
            int used = R - L + 1 - (it -> v) + has;
            return node{l, R, 3, R - l + 1 - used};
        }
    };
    auto find = [&] (int x) {
        auto it = S.upper_bound(node{x, 0, 0, 0});
        --it;
        node cur = *it;
        S.erase(it);
        --cur.v;
        if (cur.info == 3) {
            S.insert(cur);
        }
        return cur;
    };
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int atPos = at[i];
        if (in(atPos)) {
            auto tmp = find(atPos);
            ans = 1ll * ans * (1 + tmp.v) % MOD;
            int op = tmp.info;
            int has = tmp.r - tmp.l + 1 - tmp.v;
            if (op == 1) {
                int l = max(0, tmp.l - c);
                S.insert(merge(l, tmp.r, has, 1));
            } else if (op == 2) {
                int r = min(n - 1, tmp.r + c);
                S.insert(merge(tmp.l, r, has, 2));
            }
        } else {
            int l = atPos - c;
            int r = atPos + c;
            if (l >= 0 && !bit.query(l, atPos - 1)) S.insert(merge(l, atPos - 1, bit.query(l, atPos - 1), 1));
            if (r < n && !bit.query(atPos + 1, r)) S.insert(merge(atPos + 1, r, bit.query(atPos + 1, r), 2));
            bit.add(atPos);
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}