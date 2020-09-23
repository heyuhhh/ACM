// Author : heyuhhh
// Created Time : 2020/09/16 15:46:25
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
const int N = (1 << 19);

struct FT {
    int c[N];
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (++x; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    int query(int x) {
        int res = 0;
        for (++x; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    int find(int x) {
        int p = 0;
        int all = 0;
        for (int i = 18; i >= 0; i--) {
            if (all + c[p | (1 << i)] < x) {
                p |= (1 << i);
                all += c[p];
            }
        }
        if (p == (1 << 19) - 1) return 0;
        return p + 1;
    }
} bit;

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        a[i] = i - a[i];
    }

    vector<vector<pii>> Q(n);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        int l = x, r = n - y - 1;
        Q[r].emplace_back(l, i);
    }
    dbg(a);
    vector<int> ans(q + 1);
    for (int r = 0; r < n; r++) {
        if (a[r] >= 0) {
            int p = bit.find(a[r]);
            dbg(r, p);
            bit.add(0, 1), bit.add(p, -1);
        }

        for (auto& it : Q[r]) {
            int l = it.fi, id = it.se;
            ans[id] = bit.query(l);
        }
    }
    for (int i = 1; i <= 20; i++) {
        dbg(bit.c[i]);
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