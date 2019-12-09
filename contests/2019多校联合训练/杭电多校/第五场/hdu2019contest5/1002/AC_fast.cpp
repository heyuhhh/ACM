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
const int SIZE = 1e5+10;
const int MAX_LV = 29;
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;
int nxt[SIZE*31][2];
int cnt[SIZE*31][2];
int an[SIZE], an_cnt;
int id;
int get_bit(int x,int v) {return (x>>v) & 1;}
void add(int v, int ty) {
    int now = 0;
    for(int i = MAX_LV;i >= 0; i--) {
        int bit = get_bit(v, i);
        if(!nxt[now][bit]){
            nxt[now][bit] = id++;
        }
        now = nxt[now][bit];
        cnt[now][ty]++;
    }
}
int find_one(int ty){
    int now = 0;
    int ret = 0;
    for(int i = MAX_LV; i >= 0; i--) {
        if(nxt[now][0] && cnt[nxt[now][0]][ty]) {
            now = nxt[now][0];
        }
        else {
            now = nxt[now][1];
            ret |= 1 << i;
        }
    }
    return ret;
}
void del(int v, int ty) {
    int now = 0;
    for(int i = MAX_LV; i >= 0; i--) {
        now = nxt[now][get_bit(v, i)];
        cnt[now][ty]--;
    }
}
int find_near(int v, int ty){
    int now = 0;
    int ret = 0;
    for(int i = MAX_LV; i >= 0; i--) {
        int bit = get_bit(v, i);
        if(nxt[now][bit] && cnt[nxt[now][bit]][1 ^ ty]) {
            now = nxt[now][bit];
            ret |= bit << i;
        }
        else {
            now = nxt[now][bit ^ 1];
            ret |= (1 ^ bit) << i;
        }
    }
    return ret;
}
bool find_pair(int x,int ty, int lt) {
    while(1) {
        int y = find_near(x, ty);
        if(y == lt) {
            an[an_cnt++] = x ^ y;
            del(x, ty);
            del(y, ty ^ 1);
            return 1;
        }
        if(find_pair(y, ty ^ 1, x)) {
            return 0;
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        id = 1;
        REP(i,N){
            int v; 
            scanf("%d", &v);
            add(v, 0);
        }
        REP(i,N){
            int v; 
            scanf("%d", &v);
            add(v, 1);
        }
        an_cnt=0;
        while(an_cnt < N) {
            int x = find_one(0);
            find_pair(x, 0, -1);
        }
        sort(an, an + N);
        REP(i, N) printf("%d%c", an[i], " \n"[i == N - 1]);
        memset(nxt, 0, sizeof(int) * 2 * id);
    }
    return 0;
}
