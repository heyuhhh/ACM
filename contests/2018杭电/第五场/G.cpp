#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const int MAXN = 1e6 + 5, MAXM = 1e6 + 5, BOUND = 2e5, MOD = 998244353, INF = 0x3f3f3f3f, base = 10000;
const int inv2 = (MOD + 1) >> 1;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0), eps = 1e-9;
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define lc(x) ch[x][0]
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rc(x) ch[x][1]
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define all(a) (a).begin(), (a).end()
#define sz(a) int(a.size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fi first
#define se second
#define ri register int
//#define sz(a) int((a).size())
const int N = 1e6+1,M = (1<<20);
inline int add(int a, int b) {return a + b >= MOD ? a + b - MOD : a + b;}
inline int dec(int a, int b) {return a < b ? a - b + MOD : a - b;}
inline int mul(int a, int b) {return 1ll * a * b % MOD;}
template <typename T>
inline void cmin(T &a,T b){a = min(a,b);}
template <typename T>
inline void cmax(T &a,T b){a = max(a,b);}
ll qpow(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%MOD)if(b&1)ans=ans*a%MOD;
    return ans;
}
mt19937 mrand(random_device{}());
struct Query{
    unsigned int l,r,v;
    bool operator <(const Query&rhs)const{
        return v>rhs.v;
    }
    void print(){cout<<l<<' '<<r<<' '<<v<<'\n';}
}Q[MAXM];
int nxt[MAXN],fa[MAXN];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool vis[MAXN];
void run(){
    int n,m;
    unsigned int X,Y,Z;
    cin>>n>>m>>X>>Y>>Z;
    auto RNG61 = [&](){
        X = X^(X<<11);
        X = X^(X>>4);
        X = X^(X<<5);
        X = X^(X>>14);
        unsigned int W = X^(Y^Z);
        X = Y;
        Y = Z;
        Z = W;
        return Z;
    };
    for(int i=1;i<=m;i++){
        unsigned int f1 = RNG61();
        unsigned int f2 = RNG61();
        unsigned int f3 = RNG61();
        Q[i].l = min(f1%n+1,f2%n+1), Q[i].r = max(f1%n+1,f2%n+1);
        Q[i].v = f3%(1ll<<30);
    }
    sort(Q+1,Q+1+m);
    for(int i=1;i<=n;i++)fa[i] = i + 1,vis[i]=0;
    ull ans=0;
    //cout<<"*************\n";
    for(int i=1;i<=m;i++){
        int l = Q[i].l, r = Q[i].r, v = Q[i].v;
        for (int j = l; j < r; j++) {
            if (!vis[j]) {
                int fj = find(j), fjj = find(j + 1);
                fa[fj] = fjj;
                ans ^= (ull)v * j;
                vis[j] = 1;
            } else {
                j = find(j) - 1;
            }
        }
        if (!vis[r]) {
            ans ^= (ull)v * r;
            vis[r] = 1;
        }
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _;
    for(cin>>_;_--;){
        run();
    }
    return 0;
}
