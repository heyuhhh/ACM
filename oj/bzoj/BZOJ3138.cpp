/*
 * Author:  heyuhhh
 * Created Time:  2019/11/6 16:25:01
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 40005;

int n, m;
int a[N];

int f[N << 2], g[N << 2];
int lzf[N << 2], lzg[N << 2];

void push_up(int o) {
    f[o] = min(f[o << 1], f[o << 1|1]);
    g[o] = max(g[o << 1], g[o << 1|1]);
}

void push_down(int o) {
    if(lzf[o] != 0) {
        f[o << 1] += lzf[o];
        f[o << 1|1] += lzf[o];
        lzf[o << 1] += lzf[o];
        lzf[o << 1|1] += lzf[o];
        lzf[o] = 0;
    }
    if(lzg[o] != 0) {
        g[o << 1] += lzg[o];
        g[o << 1|1] += lzg[o];
        lzg[o << 1] += lzg[o];
        lzg[o << 1|1] += lzg[o];
        lzg[o] = 0;
    }
}

void build(int o, int l, int r) {
    if(l == r) {
        f[o] = g[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid); build(o << 1|1, mid + 1, r);
    push_up(o);
}

void updf(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        f[o] += v;
        lzf[o] += v;
        return;
    }
    push_down(o);
    int mid = (l + r) >> 1;
    if(L <= mid) updf(o << 1, l, mid, L, R, v);
    if(R > mid) updf(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void updg(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        g[o] += v;
        lzg[o] += v;
        return;
    }
    push_down(o);
    int mid = (l + r) >> 1;
    if(L <= mid) updg(o << 1, l, mid, L, R, v);
    if(R > mid) updg(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

int queryf(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) return f[o];
    push_down(o);
    int mid = (l + r) >> 1;
    int res = INF;
    if(L <= mid) res = queryf(o << 1, l, mid, L, R);
    if(R > mid) res = min(res, queryf(o << 1|1, mid + 1, r, L, R));
    return res;
}

int queryg(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) return g[o];
    push_down(o);
    int mid = (l + r) >> 1;
    int res =  -INF;
    if(L <= mid) res = queryg(o << 1, l, mid, L, R);
    if(R > mid) res = max(res, queryg(o << 1|1, mid + 1, r, L, R));
    return res;
}

void run(){
    cin >> n;
    int x, y, z, p; cin >> x >> y >> z >> p;
    for(int i = 1; i <= n; i++) {
        a[i] = ((i - x) * (i - x) + (i - y) * (i - y)
                + (i - z) * (i - z)) % p, a[i] += a[i - 1];
    }
    build(1, 0, n);
    cin >> m;
    cin >> a[1] >> a[2] >> x >> y >> z >> p;
    for(int i = 3; i <= m; i++) a[i] = (a[i - 1] * x + a[i - 2] * y + z) % p;
    for(int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        a[i] = min(a[i], queryf(1, 0, n, r, n) - queryg(1, 0, n, 0, l - 1));
        updf(1, 0, n, r, n, -a[i]);
        updg(1, 0, n, l, n, -a[i]);
        cout << a[i] << '\n';
    }
}

int main() {
    //freopen("../input.in", "r", stdin);
    //freopen("../output.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
	return 0;
}
