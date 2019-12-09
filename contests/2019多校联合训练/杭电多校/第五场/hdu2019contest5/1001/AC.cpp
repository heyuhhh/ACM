/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
PLL solveWA(LL x0, LL p){
    PLL r; 
    r.S = p / x0 + 1;
    r.F = r.S * x0 - p;
    PLL x = {x0, 1LL};
    while(r.F >= r.S) {
        if(r.F * 2 < x.F) {
            PLL nxt_r = MP((x.F / r.F + 1) * r.F - x.F , (x.F / r.F + 1) * r.S - x.S);
            x = r;
            r = nxt_r;
        }
        else {
            LL dif = x.F - r.F;
            LL tt = x.F / dif;
            // x.F - i * dif < r.S * i - x.S * (i-1)
            // x.F - x.S < (r.S + dif - x.S) * i
            LL need = (x.F - x.S) / (r.S + dif - x.S) + 1;
            if(need <= tt) return {x.F - need * dif, (r.S - x.S) * need + x.S};
            PLL nxt_r = {x.F - tt * dif, (r.S - x.S) * tt + x.S};
            x = r;
            r = nxt_r;
        }
    }
    return r;
}
PLL solveAC(LL x0, LL p){
    PLL r; 
    r.S = p / x0 + 1;
    r.F = r.S * x0 - p;
    PLL x = {x0, 1LL};
    while(r.F >= r.S) {
        if(r.F * 2 < x.F) {
            PLL nxt_r = MP((x.F / r.F + 1) * r.F - x.F , (x.F / r.F + 1) * r.S - x.S);
            x = r;
            r = nxt_r;
        }
        else {
            LL dif = x.F - r.F;
            LL tt = x.F / dif;
            // x.F - i * dif < r.S * i - x.S * (i-1)
            // x.F - x.S < (r.S + dif - x.S) * i
            LL need = (x.F - x.S) / (r.S + dif - x.S) + 1;
            if(need <= tt) return {x.F - need * dif, (r.S - x.S) * need + x.S};
            PLL nxt_r = {x.F - tt * dif, (r.S - x.S) * tt + x.S};
            x = {x.F - (tt - 1) * dif, (r.S - x.S) * (tt - 1) + x.S};
            r = nxt_r;
        }
    }
    return r;
}
LL modmul(LL A,LL B,LL mod)
{
    return (A*B-(LL)((long double)A*B/mod)*mod+mod)%mod;
}

LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int main(){
    CASET{
        LL p, x;
        R(p, x);
        PLL ret=solveAC(x,p);
        //assert(ret.F<ret.S && modmul(ret.S,x,p)==ret.F);
        printf("%lld/%lld\n",ret.F,ret.S);
    }
    return 0;
}
