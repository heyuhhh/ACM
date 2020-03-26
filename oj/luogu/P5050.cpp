/*
 * Author:  heyuhhh
 * Created Time:  2020/3/26 21:17:48
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int MOD = 998244353, inv2 = (MOD + 1) >> 1;
const int N = 64000 * 4 + 5; //四倍空间
typedef vector <int> Poly;
#define ri register int
#define cs const
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD;}
inline int qpow(int a, int b) {int res = 1; while(b) {if(b & 1) res = mul(res, a); a = mul(a, a); b >>= 1;} return res;}
int rev[N], inv[N];
inline void init() {
    inv[0] = inv[1] = 1;
    for(ri i = 2; i < N; i++) inv[i] = mul(inv[MOD % i], MOD - MOD / i);
}      
inline void init_rev(int len) {
    for(ri i = 0; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * (len >> 1));   
}
inline void NTT(Poly &a, int n, int op) {
    for(ri i = 0; i < n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(ri i = 1; i < n; i <<= 1) {
        int wn = qpow(op == -1 ? (MOD + 1) / 3 : 3, (MOD - 1) / i / 2);
        for(ri j = 0; j < n; j += (i << 1)) {
            for(ri k = 0, x, y, w = 1; k < i; ++k, w = mul(w, wn)) {
                x = a[j + k], y = mul(w, a[j + k + i]);
                a[j + k] = add(x, y);
                a[j + k + i] = dec(x, y);
            }   
        }
    }   
    if(op == -1) for(ri i = 0; i < n; i++) a[i] = mul(a[i], inv[n]);
}
inline Poly operator - (cs Poly &a, cs Poly &b) {
    Poly c = a; c.resize(max(sz(a), sz(b)));
    for(ri i = 0; i < sz(b); i++) c[i] = dec(c[i], b[i]);
    return c;   
}
inline Poly operator * (Poly a, Poly b) {
    int n = sz(a), m = sz(b), l = 1;
    while(l < n + m - 1) l <<= 1;
    init_rev(l);
    a.resize(l), NTT(a, l, 1);
    b.resize(l), NTT(b, l, 1);
    for(ri i = 0; i < l; i++) a[i] = mul(a[i], b[i]);
    NTT(a, l, -1);
    a.resize(n + m - 1);
    return a;
}
//多项式取逆
inline Poly Inv(cs Poly &a, int lim) {
 	Poly c, b(1, qpow(a[0], MOD - 2));
	for(ri l = 4; (l >> 2) < lim; l <<= 1) {
		init_rev(l);
		c = a, c.resize(l >> 1);
		c.resize(l), NTT(c, l, 1);
		b.resize(l), NTT(b, l, 1);
		for(ri i = 0; i < l; i++) b[i] = mul(b[i], dec(2, mul(c[i], b[i])));
		NTT(b, l, -1);
		b.resize(l >> 1);
	}
	b.resize(lim);
	return b;      
}
inline Poly Inv(cs Poly &a) {return Inv(a, sz(a));}
//多项式除法
inline Poly operator / (Poly a, Poly b) {
	ri len = 1, deg = sz(a) - sz(b) + 1;
    reverse(all(a)), reverse(all(b));
	while(len <= deg) len <<= 1;
	b = Inv(b, len), b.resize(deg);
	a = a * b, a.resize(deg);
    reverse(all(a));
	return a;
}
inline Poly operator % (const Poly &a, const Poly &b) {
	Poly c = a - (a / b) * b;
	c.resize(sz(b) - 1);
	return c;
}
int a[N], b[N]; //b[i] = f(a[i])
Poly P[N];
void DC_NTT(int o, int l, int r) {
    if(l == r) {
        P[o].resize(2);
        P[o][0] = MOD - a[l], P[o][1] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    DC_NTT(o << 1, l, mid), DC_NTT(o << 1|1, mid + 1, r);
    P[o] = P[o << 1] * P[o << 1|1];
}
void solve(const Poly &f, int o, int l, int r) {
    if(l == r) {
        b[l] = f[0];
        return;
    }   
    int mid = (l + r) >> 1;
    Poly rl = f, rr = f;
    if(sz(rl) >= sz(P[o << 1])) rl = rl % P[o << 1];
    if(sz(rr) >= sz(P[o << 1|1])) rr = rr % P[o << 1|1];
    solve(rl, o << 1, l, mid), solve(rr, o << 1|1, mid + 1, r);
}

void run() {
    init();
    int n, m; cin >> n >> m;
    Poly f(n + 1);
    for(int i = 0; i <= n; i++) cin >> f[i];
    for(int i = 1; i <= m; i++) cin >> a[i];
    DC_NTT(1, 1, m);
    solve(f, 1, 1, m);
    for(int i = 1; i <= m; i++) cout << b[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
