// Author : heyuhhh
// Created Time : 2020/09/19 20:31:18
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
const int N = 2e5 + 5, MOD = 998244353;

int sumv[N << 2];

void push_up(int o) {
    sumv[o] = (sumv[o << 1] + sumv[o << 1|1]) % MOD;
}
void build(int o, int l, int r) {
    if(l == r) {
        sumv[o] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}
void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        sumv[o] = v;
        return;
    }   
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}
int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sumv[o];
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = (res + query(o << 1|1, mid + 1, r, L, R)) % MOD;
    return res;
}

void run() {
    int n, k;
    cin >> n >> k;
    build(1, 1, n);
    vector<pii> a(k);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = MP(l, r);
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    update(1, 1, n, 1, 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int L = max(1, i - a[j].se), R = i - a[j].fi;
            if (L > R) continue;
            dp[i] = (dp[i] + query(1, 1, n, L, R)) % MOD;
        }
        update(1, 1, n, i, i, dp[i]);
    }
    cout << dp[n] << '\n';
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