#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const int MAXN = 2e5 + 5, MAXM = 4e5 + 5, BOUND = 2e5, MOD = 1e9+7, INF = 0x3f3f3f3f, base = 10000;
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
char s[MAXN];
int mp[5][2] = {{1,0},{2,0},{2,3},{4,0},{2,0}};
void run(){
    int n;cin>>n;
    cin>>(s+1);
    int ans=0,sta=0;
    bool flag=false;
    rep(i,1,n){
        if(sta==2 && s[i]=='C'){
            if(!flag){
                flag=true;
                ans++;
            }
        }
        if(sta==1 && s[i]=='P' && i+1<=n && s[i+1]=='C'){
            if(!flag){
                flag=true;
                ans++;
                //cout<<"lalala\n";
            }
        }
        if(s[i]=='C'){
            sta = mp[sta][0];
        }else if(s[i]=='P'){
            sta = mp[sta][1];
        }
        if(sta==4)ans++;
        if(i==n && sta==3){
            if(!flag){
                flag=true;
                ans++;
            }
        }
        //cout<<sta<<" \n"[i==n];
        //cout<<ans<<" \n"[i==n];
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _;cin>>_;
    while(_--)run();
    return 0;
}