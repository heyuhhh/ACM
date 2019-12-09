#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int P = 998244353, SZ = 150000, G = 3;
ll kpow(ll a, ll b) {ll r=1;for(; b; b>>=1,a=a*a%P) {if(b&1)r=r*a%P;}return r;}
ll Inv(ll x) {return kpow(x, P-2);}
ll w[2][SZ], rev[SZ]; int N;

inline void work(int n){
	for (N = 1; N < n; N <<= 1);
	int d = __builtin_ctz(N);
	w[0][0] = w[1][0] = 1;
	for (int i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
		rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
		w[0][i] = (ll)x * w[0][i-1] % P, w[1][i] = (ll) y * w[1][i-1] % P;
	}
}
	
inline void FFT(int *a, int f){
	rep(i, 0, N) a[i] = (a[i] % P + P) % P;
	rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < N; i <<= 1)
		for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
			for (int k = 0, l = 0, x, y; k < i; k++, l += t)
				x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
	if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
}

struct poly {
	vi ps;
	inline int cs() { return ps.size()-1;}
	inline int& operator [] (int x) {return ps[x];}
	inline void sc(int x) {ps.resize(x+1);}
	inline void clr() {int p=cs()+1;while(p&&!ps[p-1]) --p;sc(p-1);}
};

namespace PolyMul {int ta[SZ], tb[SZ];}
inline poly operator * (poly &a, poly &b) {
	using namespace PolyMul;
	int t = a.cs() + b.cs();
	if (1ll * a.cs() * b.cs() <= t * 50ll) {
		poly g; g.sc(t); int *G = &g[0], *A = &a[0], *B = &b[0];
		per(i, 0, a.cs()+1){
			register int *h = G+i; register int x = A[i];
			per(j, 0, b.cs()+1) h[j] = (h[j] + (ll)x * B[j]) % P;
		}
		return g;
	}
	poly c; c.sc(t); work(t+1);
	per(i, 0, a.cs()+1) ta[i] = a[i]; per(i, 0, b.cs()+1) tb[i] = b[i];
	rep(i, a.cs()+1, N) ta[i] = 0; rep(i, b.cs()+1, N) tb[i] = 0;
	FFT(ta, 0); FFT(tb, 0);
	rep(i, 0, N) ta[i] = (ll) ta[i] * tb[i] % P;
	FFT(ta, 1); rep(i, 0, t+1) c[i] = ta[i]; c.clr();
	return c;
}

namespace PolyInv {int ay[SZ],a0[SZ],tmp[SZ];}
inline void ginv(int t) {
	using namespace PolyInv;
	if (t == 1) {a0[0] = kpow(ay[0], P-2);return;}
	ginv((t+1)>>1); work(t+t+3);
	rep(i, t, N) tmp[i] = a0[i] = 0;
	rep(i, 0, t) tmp[i] = ay[i];
	FFT(tmp, 0); FFT(a0, 0);
	rep(i, 0, N) a0[i]=(2-(ll)tmp[i]*a0[i])%P*a0[i]%P;
	FFT(a0,1); rep(i, t, N) a0[i] = 0;
}

inline poly inv(poly x) {
	using namespace PolyInv;
	poly y; y.sc(x.cs()); per(i, 0, x.cs()+1) ay[i]=x[i];
	ginv(x.cs()+1); per(i, 0, x.cs()+1) y[i]=a0[i]; y.clr();
	return y;
}
inline poly operator + (poly a,poly b) {
	a.sc(max(a.cs(), b.cs()));
	per(i, 0, b.cs()+1) (a[i]+=b[i])%=P;
	a.clr(); return a;
}
inline poly operator - (poly a,poly b) {
	a.sc(max(a.cs(),b.cs()));
	per(i, 0, b.cs()+1) (a[i]-=b[i])%=P;
	a.clr(); return a;
}
inline void div(poly &a, poly &b, poly &d, poly &r) {
	int n = a.cs(), m = b.cs();
	if(n<m) {d.sc(0); d[0]=0; r=a; return;}
	poly aa = a; reverse(all(aa.ps));
	poly bb = b; reverse(all(bb.ps));
	bb.sc(n-m); bb=inv(bb); d=aa*bb; d.sc(n-m);
	reverse(all(d.ps)); r=a-b*d; r.clr();
}

inline poly operator % (poly a, poly b) {
	a.clr(); b.clr(); if(a.cs() < b.cs()) return a;
	poly d, r; div(a,b,d,r); return r;
}

poly vvs[SZ];
inline void gvs(int m, int* x, int id) {
	if(m==1) { vvs[id].sc(1), vvs[id][1]=1, vvs[id][0]=-*x; return;}
	int hf = m>>1;
	gvs(hf,x,id*2); gvs(m-hf,x+hf,id*2+1);
	vvs[id] = vvs[id*2] * vvs[id*2+1];
}
namespace PolyGetv {int xs[SZ], anss[SZ];};
inline void gv(poly f, int m, int* x,int* ans,int id) {
	if(f.cs() <= 700) {
		int c=f.cs(), *F=&f.ps[0];
		rep(i, 0, m) {
			register ll t=0; register int v=x[i];
			for(register int j=c; ~j; --j) t=(t*v+F[j])%P;
			ans[i]=t;
		}
		return;
	}
	int hf=m>>1;
	gv(f%vvs[id*2],hf,x,ans,id*2);
	gv(f%vvs[id*2+1],m-hf,x+hf,ans+hf,id*2+1);
}

inline vi getv(poly a, vi x) {
	using namespace PolyGetv;
	a.clr(); if(!x.size()) return vi();
	int m = sz(x); rep(i, 0, m) xs[i]=x[i];
	gvs(m, xs, 1); gv(a % vvs[1], m, xs, anss, 1);
	vi ans; ans.resize(m);
	rep(i, 0, m) ans[i] = anss[i];
	return ans;
}

const int M = 1e5 + 7;
int n, Q;
ll p[M], t, ret, INV[M], a, b, c, d, q, fac[M], aa[M],bb[M],cc[M],ans[M];
vi X, Y, id;

int main() {
	p[0] = fac[0]=1; rep(i, 1, M) fac[i]=fac[i-1]*i%P;
	INV[M-1] = Inv(fac[M-1]); per(i, 0, M-1) INV[i] = INV[i+1] * (i+1) % P;
	while (scanf("%d%d",&n,&Q)!=EOF) {
		ret = 0; a=b=c=d=1,a=-a; q=c*Inv(b)%P;
		poly A, B; A.sc(n); B.sc(n);
		for (ll tmp=1,k=0; k<=n; ++k,tmp=tmp*q%P) A[k]=tmp*kpow(k+1,n)%P*INV[k]%P*(1-((k&1)<<1))%P,B[k]=tmp*INV[k]%P;
		A = A * B; rep(i,0,n+1) p[i] = A[i] * fac[i] % P;
		X.clear(); id.clear();
		rep(i, 1, Q+1) {
			ll tmp; ans[i] = 0;
			scanf("%lld%lld%lld%lld",&aa[i],&bb[i],&cc[i],&tmp),aa[i]%=P,bb[i]%=P,(cc[i]+=P)%=P;
			if ((cc[i]+1)%P==0) {ans[i]=-1;continue;}
			aa[i]=-aa[i],X.pb(kpow(cc[i]+1,P-2)*cc[i]%P),id.pb(i);;
		}
		poly g; g.sc(n); rep(i, 0, n+1) g[i] = p[i]; Y = getv(g, X);
		rep(i, 1, Q+1) {
			if (ans[i] < 0) { printf("-1\n");continue;}
			ll t=kpow(cc[i]+1,P-2),ret=Y[i-1]*t%P*bb[i]%P*kpow(aa[i],n)%P*INV[n]%P;
			printf("%lld\n",(ret+P)%P);
		}
	}
	return 0;
}
