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
struct Data{
    LL a,b;
    Data(int _a = 1, int _b = 0): a(_a), b(_b){
        if(a < 0) {
            a = -a;
            b = -b;
        }
    }
    void simplication() {
        if(!b) a = 1;
        else {
            LL gg = __gcd(a, abs(b));
            a/=gg;
            b/=gg;
        }
    }
    bool operator<(const Data& d2) const {
        return b*d2.a < a * d2.b;
    }
    bool operator<=(const Data& d2) const {
        return b*d2.a <= a * d2.b;
    }
    bool operator==(const Data& d2) const {
        return b * d2.a == a * d2.b;
    }
}d[SIZE];
int dn;
void solve() {
    int N;
    LL C;
    R(N,C);
    dn = 0;
    REP(i,N){
        int a,b;
        R(a,b);
        b = -b;
        if(!a) {
            C -= abs(b);
        }
        else {
            if(a < 0) {
                a = -a;
                b = -b;
            }
            d[dn++] = Data(a, b);
        }
    }
    if(!dn) {
        if(C == 0) W(-1);
        else W(0);
        return;
    }
    sort(d, d + dn);
    vector<Data> an;
    LL sum_a = 0, sum_b = 0;
    REP(i, dn) {
        sum_a += d[i].a;
        sum_b += d[i].b;
    }
    {
        Data res(sum_a, C + sum_b);
        if(d[dn-1] <= res) {
            an.PB(res);
        }
    }
    for(int i = dn - 1; i >= 0; i--) {
        sum_a -= d[i].a * 2;
        sum_b -= d[i].b * 2;
        if(sum_a == 0) {
            if(sum_b + C == 0) {
                if(d[i-1] < d[i]) {
                    W(-1);
                    return;
                }
            }
            continue;
        }
        Data res(sum_a, C + sum_b);
        if(i) {
            if(res <= d[i] && d[i-1] <= res) {
                an.PB(res);
            }
        }
        else {
            if(res <= d[i]) {
                an.PB(res);
            }
        }
    }
    REP(i,SZ(an)){
        an[i].simplication();
    }
    SORT_UNIQUE(an);
    printf("%d",SZ(an));
    for(auto x: an) {
        printf(" %lld/%lld",x.b,x.a);
    }
    W("");
}
int main(){
    CASET{
        solve();
    }
    return 0;
}
