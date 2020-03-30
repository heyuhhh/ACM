#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> Poly;
#define ri register int
#define cs const
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
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

struct cn{
    int x, y, w;
    cn operator * (cn a){
        cn ans;
        ans.x = (1ll * x * a.x % MOD + 1ll * y * a.y % MOD * w % MOD) % MOD;
        ans.y = (1ll * x * a.y % MOD + 1ll * y * a.x % MOD) % MOD;
        ans.w = w;
        return ans;
    }
    int operator ^ (int b){
        cn ans, x = *this;
        ans.x = 1, ans.y = 0, ans.w = w;
        while(b) {
            if(b & 1) ans = ans * x;
            x = x * x;
            b >>= 1;
        }
        return ans.x;
    }
};
//求解n的二次剩余
int sqrt_mod(int n) {
    if(n == 0) return 0;
    if(qpow(n, (MOD - 1) / 2) == MOD - 1) return -1;
    int a, w;
    while(true) {
        a = rand() % MOD;
        w = (1ll * a * a - n + MOD) % MOD;
        if(qpow(w, (MOD - 1) / 2) == MOD - 1) break;
    }
    cn x;
    x.x = a, x.y = 1, x.w = w;
    return x ^ ((MOD + 1) / 2);
}
inline print(cs Poly &a) {
    for(ri i = 0; i < sz(a); i++) cout << a[i] << ' ';
    cout << '\n';   
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
inline Poly operator * (Poly a, int b) {
    for(ri i = 0; i < sz(a); i++) a[i] = mul(a[i], b);
    return a;   
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

//多项式开根
inline Poly Sqrt(cs Poly &a, int lim) {
 	Poly c, d, b(1, sqrt_mod(a[0]));
	for(ri l = 4; (l >> 2) < lim; l <<= 1) {
		init_rev(l);
		c = a, c.resize(l >> 1);
		d = Inv(b, l >> 1);
		c.resize(l), NTT(c, l, 1);
		d.resize(l), NTT(d, l, 1);
		for(ri j = 0; j < l; j++) c[j] = mul(c[j], d[j]);
		NTT(c, l, -1);
		b.resize(l >> 1);
		for(ri j = 0; j < (l >> 1); j++) b[j] = mul(add(c[j], b[j]), inv2);
	}
	b.resize(lim);
	return b;   
};
inline Poly Sqrt(cs Poly &a) {return Sqrt(a, sz(a));}

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

//多项式k次方
inline Poly Ksm(Poly a, int k, int lim){
	a = Exp(Ln(a) * k);
	a.resize(lim);
	return a;
}
inline Poly Ksm(cs Poly &a, int k) {return Ksm(a, k, sz(a));}

int main() {
    init(); //记住要init
    return 0;   
}
