/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 9:25:18
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#pragma GCC optimize(2)
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
const int MOD = 998244353, inv2 = (MOD + 1) >> 1;
const int N = 4e5 + 5, M = (1 << 19); //四倍空间,M=2^x且M>=N
typedef vector <int> Poly;
#define ri register int
#define cs const
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD < 0 ? 1ll * a * b % MOD + MOD : 1ll * a * b % MOD;}
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
//多项式取逆
inline Poly Inv(cs Poly &a, int lim) {
 	Poly c, b(1);
    if(a[0] == 1) b[0] = 1;
    else if(a[0] == 2) b[0] = inv2;
    else b[0] = qpow(a[0], MOD - 2);
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
 	Poly c, d, b(1, 1);
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
int read() {
    int n, c, sign = 0;
    while ((c = getchar()) < '-')
        ;
    if (c == '-')
        sign = 1, n = 0;
    else
        n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return sign ? -n : n;
}
void run() {
    init();
    int n, m; n = read(), m = read();
    Poly g(100000 + 5, 0); g[0] = 1;
    for(ri i = 0, x; i < n; i++) {
        x = read(); g[x] = MOD - 4;
    }
    g = Sqrt(g, m + 1);
    g[0] = add(g[0], 1);
    g = Inv(g, m + 1);
    for(ri i = 1; i <= m; i++) printf("%d\n", 2 * g[i] % MOD);
}

int main() {
    run();
    return 0;
}
