/*
 * Author:  heyuhhh
 * Created Time:  2020/3/25 19:33:55
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
const int N = 4e5 + 5; //四倍空间
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
inline Poly operator * (Poly a, int b) {
    for(ri i = 0; i < sz(a); i++) a[i] = mul(a[i], b);
    return a;   
}
inline Poly operator + (cs Poly &a, cs Poly &b) {
    Poly c = a; c.resize(max(sz(a), sz(b)));
    for(ri i = 0; i < sz(b); i++) c[i] = add(c[i], b[i]);
    return c;   
}
inline Poly operator - (cs Poly &a, cs Poly &b) {
    Poly c = a; c.resize(max(sz(a), sz(b)));
    for(ri i = 0; i < sz(b); i++) c[i] = dec(c[i], b[i]);
    return c;   
}

//求导
inline Poly Deriv(Poly a) {
    for(ri i = 0; i + 1 < sz(a); i++) a[i] = mul(a[i + 1], i + 1);
    a.pop_back();
    return a;   
}

//积分
inline Poly Integ(Poly a) {
    a.push_back(0);
    for(ri i = sz(a) - 1; i; i--) a[i] = mul(a[i - 1], inv[i]);
    a[0] = 0;
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

//多项式ln
inline Poly Ln(Poly a, int lim){
	a = Integ(Deriv(a) * Inv(a, lim));
	a.resize(lim);
	return a;
}
inline Poly Ln(cs Poly &a) {return Ln(a, sz(a));}

//多项式exp
inline Poly Exp(cs Poly &a, int lim){
	Poly c, b(1, 1);
	for(ri i = 2; (i >> 1) < lim; i <<= 1) {
		c = Ln(b, i);
		for(ri j = 0; j < i; j++) c[j] = dec(j < sz(a) ? a[j] : 0, c[j]);
		c[0] = add(c[0], 1);
		b = b * c;
		b.resize(i);
	}
	b.resize(lim);
	return b;
}
inline Poly Exp(cs Poly &a) {return Exp(a, sz(a));}

//三角函数
cs int w4 = qpow(3, (MOD - 1) / 4);
inline Poly Cos(cs Poly &a, int lim) {
	Poly c = a; c.resize(lim);
	c = (Exp(c * w4) + Exp(c * (MOD - w4))) * inv2;
	return c;
}
inline Poly Cos(cs Poly &a) {return Cos(a, sz(a));}
inline Poly Sin(cs Poly &a, int lim){
	Poly c = a; c.resize(lim);
	c = (Exp(c * w4) - Exp(c * (MOD - w4))) * mul(inv2, qpow(w4, MOD - 2));
	return c;
}
inline Poly Sin(cs Poly &a) {return Sin(a, sz(a));}

void run() {
    init();
    int n, op; cin >> n >> op;
    Poly a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    Poly b;
    if(op == 0) b = Sin(a);
    else b = Cos(a);
    for(auto it : b) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
