#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const int MAXN = 5e5 + 5, MAXM = 4e5 + 5, BOUND = 2e5, MOD = 1e9+7, INF = 0x3f3f3f3f, base = 10000;
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
#define MP std::make_pair
#define ri register int
//#define sz(a) int((a).size())
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
char s[MAXN*2],t[MAXN];
int p[MAXN*2],n;
void manacher(){
	s[0]=s[1]='#';
	for(int i=1;i<=n;i++){
		s[i*2] = t[i];
		s[i*2+1]='#';
	}
	int _n=n*2+1;
	int m,mx=0;
	for(int i=_n+1;!s[i];i++)s[i]='0';
	for(int i=1;i<=_n;i++){
		if(mx>i)p[i]=min(p[2*m-i],p[m]+m-i);
	else p[i]=1;
	for(;s[i+p[i]]==s[i-p[i]];++p[i]);
		if(p[i]+i>mx)mx=p[i]+i,m=i;
	}
}
int bit[MAXN];
void upd(int x,int v){
    for(;x;x-=x&-x)bit[x]+=v;
}
int que(int x){
    int ans=0;
    for(;x<=n;x+=x&-x)ans += bit[x];
    return ans;
}

priority_queue<pii> q;
void run(){
    cin>>(t+1);
    n=strlen(t+1);
    rep(i,0,n)bit[i]=0;
    while(!q.empty())q.pop();
    manacher();
    ll ans=0;
    rep(i,1,n){
        while(!q.empty() && -(q.top().fi)<i)upd(q.top().se,-1),q.pop();
        ans += que(i-p[i*2]/2+1);
        upd(i,1);
        q.push({-(i+p[i*2]/2-1),i});
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _;cin>>_;
    while(_--)run();
    return 0;
}
