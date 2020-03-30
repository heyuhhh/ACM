const int MOD = 998244353, inv2 = (MOD + 1) >> 1;
const int N = 4e5 + 5, M = (1 << 19); //四倍空间,M=2^x且M>=N
typedef vector <int> Poly;
#define ri register int
#define cs const
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD;}
inline int qpow(int a, int b) {int res = 1; while(b) {if(b & 1) res = mul(res, a); a = mul(a, a); b >>= 1;} return res;}
int rev[N], inv[N], pw[M], W[2][M];
inline void init() {
    inv[0] = inv[1] = 1;
    for(ri i = 2; i < N; i++) inv[i] = mul(inv[MOD % i], MOD - MOD / i);
    int w0 = qpow(3, (MOD - 1) / M), w1 = qpow((MOD + 1) / 3, (MOD - 1) / M);
    W[0][0] = W[1][0] = 1;
    for(ri i = 1; i < M; i++) {
        W[0][i] = mul(W[0][i - 1], w0);
        W[1][i] = mul(W[1][i - 1], w1);
    }
}      
inline void init_rev(int len) {
    for(ri i = 0; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * (len >> 1));   
}
inline void NTT(Poly &a, int n, int op) {
    for(ri i = 0; i < n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(ri i = 1; i < n; i <<= 1) {
        int t = M / (i << 1), t2 = (op == -1 ? 1 : 0);
        for(ri j = 0; j < i; ++j) pw[j] = W[t2][j * t];
        int wn = (op == -1 ? W[1][i] : W[0][i]);
        for(ri j = 0; j < n; j += (i << 1)) {
            for(ri k = 0, x, y; k < i; ++k) {
                x = a[j + k], y = mul(pw[k], a[j + k + i]);
                a[j + k] = add(x, y);
                a[j + k + i] = dec(x, y);
            }   
        }
    }   
    if(op == -1) for(ri i = 0; i < n; i++) a[i] = mul(a[i], inv[n]);
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
inline Poly Deriv(Poly a) {
    for(ri i = 0; i + 1 < sz(a); i++) a[i] = mul(a[i + 1], i + 1);
    a[sz(a) - 1] = 0;
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
//多点求值
//已知a[i],f 求解b[i] = f(a[i])
Poly P[N];
inline void DC_NTT(int o, int l, int r, const Poly& a) {
    if(l == r) {
        P[o].resize(2);
        P[o][0] = MOD - a[l], P[o][1] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    DC_NTT(o << 1, l, mid, a), DC_NTT(o << 1|1, mid + 1, r, a);
    P[o] = P[o << 1] * P[o << 1|1];
}
inline void DC_MOD(const Poly &f, const Poly &a, Poly &b, int o, int l, int r) {
    if(r - l <= 1000) {
        for(int i = l; i <= r; i++) {
            int res = 0;
            int x = 0, j = sz(f);
            int a1 = a[i], a2 = mul(a1, a1), a3 = mul(a1, a2), a4 = mul(a1, a3);
            int a5 = mul(a1, a4), a6 = mul(a1, a5), a7 = mul(a1, a6), a8 = mul(a1, a7);
            while(j >= 8)
                x = (1ll * mul(x, a8) + mul(f[j - 1], a7) + mul(f[j - 2], a6) + mul(f[j - 3], a5)
                    + mul(f[j - 4], a4) + mul(f[j - 5], a3) + mul(f[j - 6], a2) 
                    + mul(f[j - 7], a1) + f[j - 8]) % MOD, j -= 8;
            while(j--) x = add(mul(x, a1), f[j]);
            b[i] = x;
        }   
        return;
    }
    int mid = (l + r) >> 1;
    Poly lf = f, rf = f;
    if(sz(lf) >= sz(P[o << 1])) lf = lf % P[o << 1];
    if(sz(rf) >= sz(P[o << 1|1])) rf = rf % P[o << 1|1];
    DC_MOD(lf, a, b, o << 1, l, mid), DC_MOD(rf, a, b, o << 1|1, mid + 1, r);
}
inline void getval(const Poly &f, const Poly &a, Poly &b) {
    //DC_NTT(1, 0, n - 1, x);
    DC_MOD(f, a, b, 1, 0, sz(a) - 1);
}

//多项式快速插值
//已知点对(x_i,y_i)，求解插值多项式
inline Poly DC_NTT2(int o, int l, int r, const Poly& v) {
    if(r == l) {
        Poly t(1, v[l]);
        return t;
    }
    int mid = (l + r) >> 1;
    Poly lf = DC_NTT2(o << 1, l, mid, v), rf = DC_NTT2(o << 1|1, mid + 1, r, v);
    return lf * P[o << 1|1] + rf * P[o << 1];
}

inline Poly fast_interpolation(const Poly &x, const Poly &y) {
    int n = sz(x);
    DC_NTT(1, 0, n - 1, x);
    Poly M = P[1], val(n);
    M = Deriv(M);
    getval(M, x, val);
    for(ri i = 0; i < n; i++) val[i] = mul(y[i], qpow(val[i], MOD - 2));
    return DC_NTT2(1, 0, n - 1, val);
}
