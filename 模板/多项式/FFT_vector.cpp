const int N = 4e5 + 5, M = (1 << 19);
const double pi = acos(-1.0);
#define ri register int
#define cs const
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD;}
struct C {
	double x, y;
	C(double xx = 0, double yy = 0) { x = xx, y = yy; };
};
C operator + (C a, C b) { return C(a.x + b.x, a.y + b.y); }
C operator - (C a, C b) { return C(a.x - b.x, a.y - b.y); }
C operator * (C a, C b) { return C(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
typedef vector<Complex> Poly;
int rev[N];     
inline void init_rev(int len) {
    for(ri i = 0; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * (len >> 1));   
}
void FFT(Poly &A, int limit, int type) {
	for(ri i = 0; i < limit; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(ri i = 1; i < limit; i <<= 1) {
		C Wn(cos(pi / i), type * sin(pi / i));
		for (int j = 0; j < limit; j += (i<<1)) {
			C w(1, 0);
			for (int k = 0; k < i; k++, w = w * Wn) {
				C x = A[j + k], y = w * A[j + k + i];
				A[j + k] = x + y;
				A[j + k + i] = x - y;	
			}
		}
	}
    if(type == -1) for(int i = 0; i < limit; i++) A[i].x /= limit;
}

inline Poly operator * (Poly a, Poly b) {
    int n = sz(a), m = sz(b), l = 1;
    while(l < n + m - 1) l <<= 1;
    init_rev(l);
    a.resize(l), FFT(a, l, 1);
    b.resize(l), FFT(b, l, 1);
    for(ri i = 0; i < l; i++) a[i] = a[i] * b[i];
    FFT(a, l, -1);
    a.resize(n + m - 1);
    return a;
}
