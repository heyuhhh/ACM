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

const int mod = 998244353;

int kpow(ll a, int b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1; 
    }
    return r;
}

void FWT(int a[],int n){
    for(int d=1; d<n; d<<=1)  
        for(int m=d<<1,i=0; i<n; i+=m)  
            for(int j=0; j<d; j++){  
                int x=a[i+j],y=a[i+j+d];  
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;  
            }
}

void solve(int a[],int n){
    FWT(a,n);
    rep(i, 0, n) a[i] = 1ll * a[i] * a[i] % mod * a[i] % mod;
    FWT(a,n);
    ll inv = kpow(n, mod - 2);
    rep(i, 0, n) a[i] = a[i] * inv % mod;
}

const int N = pw(20) + 5;
int n, a[N], nn, ret, ans;

inline int add(int x, int y) { if ((x += y) >= mod) x -= mod; return x < 0 ? x + mod : x; }
inline int mul(int x, int y) { return (ll)x * y % mod; }

int main() {
    
    while (scanf("%d",&n)!=EOF) {
        for (nn=1; nn<n; nn<<=1);
        ret=0, ans=0;
        rep(i, 0, nn) a[i] = (i < n);
        n = nn;
        FWT(a,n);
        rep(i, 0, n) a[i] = 1ll * a[i] * a[i] % mod * a[i] % mod;
        FWT(a,n);
        ll inv = kpow(n, mod - 2);
        rep(i, 0, n) a[i] = a[i] * inv % mod;
        rep(i, 0, nn) {
            ret = (ret + 1ll * i * a[i]) % mod;
            ans = (ans + 1ll * i * i % mod * a[i]) % mod;
        }
        ret = mul(ret,ret);
        ret -= ans, ret %=mod;
        ret = mul(ret, mod + 1 >>1);
        if (ret<0) ret+=mod;
        printf("%d\n",ret);
    }
    
    return 0;
}
