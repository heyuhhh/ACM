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

LL mul(LL A,LL B,LL mod)
{
    return (A*B-(LL)((long double)A*B/mod)*mod+mod)%mod;
}
/*
long long mul(long long a,long long b,long long m){
    if(a<=9000000000000000000LL/b)return a*b%m;
    long long i,res=0;
    for(i=1;i<=b;i*=2,(a*=2)%=m)
        if(b&i)(res+=a)%=m;
    return res;
}
*/
LL mypow(LL x, LL y, LL mod){
    LL res=1;
    while(y) {
        if(y&1) res = mul(res, x, mod);
        y>>=1;
        x = mul(x, x, mod);
    }
    return res;
}
map<LL,LL> prime_root;
bool is_prime_root(LL p, LL x) {
    if((p-1)%2==0 && mypow(x,(p-1)/2, p) == 1) return 0;
    if((p-1)%3==0 && mypow(x,(p-1)/3, p) == 1) return 0;
    return 1;
}
LL get_prime_root(LL p){
    for(LL i=2;;i++){
        if(is_prime_root(p,i))return prime_root[p] = i;
    }
}
map<LL,PII>power23;
PII get23power(LL p){
    if(power23.count(p))return power23[p];
    PII ret{0,0};
    LL now=p-1;
    while(now%2==0){
        ret.F++;
        now/=2;
    }
    while(now%3==0){
        ret.S++;
        now/=3;
    }
    assert(now==1);
    return ret;
}
LL get_power(LL rt, LL x, LL p, PII pp) {
    LL tt = p - 1;
    LL now = rt;
    LL res = 0;
    LL ker = 1;
    REP(i, pp.F) {
        tt /= 2;
        if(mypow(x, tt, p) != 1) {
            x = mul(x, now, p);
            res += ker;
        }
        ker *= 2;
        now = mul(now, now, p);
    }
    REP(i, pp.S) {
        tt /= 3;
        if(mypow(x, tt, p) != 1) {
            x = mul(x, now, p);
            res += ker;
            if(mypow(x, tt, p) != 1) {
                x = mul(x, now, p);
                res += ker;
            }
        }
        now = mul(now, mul(now, now, p), p);
        ker *= 3;
    }
    res = (p - 1 - res) % (p - 1); 
    return res;
}
// a*x+b*y=z
struct gcd_t {long long x,y,z;};
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
int main(){
    CASET{
        LL p,a,b;
        R(p,a,b);
        LL _a=a,_b=b;
        int rt;
        if(prime_root.count(p)) rt = prime_root[p];
        else rt = get_prime_root(p);
        PII pp=get23power(p);
        a = get_power(rt, a, p, pp);
        b = get_power(rt, b, p, pp);
        if(a == 0) {
            if(b == 0) {
                W(1);
            }
            else{
                W(-1);
            }
        }
        else {
            gcd_t gg=gcd(a,p-1);
            if(b%gg.z) W(-1);
            else {
                if(gg.x<0)gg.x+=p-1;
                LL res = mul(gg.x, b / gg.z, (p - 1)/gg.z);
                assert(mypow(_a,res,p) == _b);
                W(res);
            }
        }
    }
    return 0;
}
