// Author : heyuhhh
// Created Time : 2020/08/14 17:05:53
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e6 + 5;

int a[N], sum[N];

struct node {
    int max[2];
    int s[2];
    void init() {
        max[0] = max[1] = -INF;
        s[0] = s[1] = INF;
    }
}v[N << 2];

int dp[N];

void upd(node& res, node A) {
    if (A.max[0] >= res.max[0]) {
        if (A.max[0] == res.max[0]) {
            res.s[0] = min(res.s[0], A.s[0]);
        } else {
            res.max[1] = res.max[0];
            res.s[1] = res.s[0];
            res.max[0] = A.max[0];
            res.s[0] = A.s[0];
        }
        if (A.max[1] == res.max[1]) {
            res.s[1] = min(res.s[1], A.s[1]);
        } else if (A.max[1] > res.max[1]) {
            res.max[1] = A.max[1];
            res.s[1] = A.s[1];
        }
    } else {
        if (A.max[0] == res.max[1]) {
            res.s[1] = min(res.s[1], A.s[0]);
        } else if (A.max[0] > res.max[1]) {
            res.max[1] = A.max[0];
            res.s[1] = A.s[0];
        }
    }
}

void push_up(int o) {
    v[o] = v[o << 1];
    upd(v[o], v[o << 1|1]);
}

void build(int o, int l, int r) {
    v[o].init();
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1|1, mid + 1, r);
    push_up(o);
}

node query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return v[o];
    }
    int mid = (l + r) >> 1;
    node res;
    res.init();
    if (L <= mid) res = query(o << 1, l, mid, L, R);
    if (R > mid) upd(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}

void update(int o, int l, int r, int x, int val) {
    if (l == r) {
        v[o].max[0] = val;
        v[o].s[0] = sum[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(o << 1, l, mid, x, val);
    else update(o << 1|1, mid + 1, r, x, val);
    push_up(o);
}

void run() {
    int n, L, R;
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    build(1, 0, n);
    update(1, 0, n, 0, 0);
    auto f = [&] (int a) {
        if (a > 0) return 1;
        if (a == 0) return 0;
        return -1;
    };
    for (int i = 1; i <= n; i++) {
        int l = i - R, r = i - L;
        l = max(l, 0);
        if (l > r) continue;

        node t = query(1, 0, n, l, r);
        // dbg(t.max[0], t.s[0], t.max[1], t.s[1]);
        dp[i] = t.max[0] + f(sum[i] - t.s[0]);
        dp[i] = max(dp[i], t.max[1] + f(sum[i] - t.s[1]));
        update(1, 0, n, i, dp[i]);
        // dbg(i, dp[i]);
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}