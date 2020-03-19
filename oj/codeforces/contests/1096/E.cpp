#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005,MOD = 998244353;
ll p,s,r;
ll fac[N+N];
ll qp(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans ;
}
ll inv(ll x){
    return qp(x,MOD-2);
}
ll C(ll n,ll m){
    if(n==m) return 1;
    if(m>n) return 0;
    return fac[n]*inv(fac[m]*fac[n-m]%MOD)%MOD;
}
ll g(ll S,ll P,ll m){
    ll ans=0,tmp;
    if(!S && !P) return 1;  //!!
    for(int i=0;i<=P;i++){
        tmp = C(P,i)*C(S+P-1-i*(m+1),P-1)%MOD;
        if(i&1) ans-=tmp;
        else ans+=tmp;
        ans%=MOD;
        if(ans<0) ans+=MOD;
    }
    return ans ;
}
int main(){
    cin>>p>>s>>r;
    fac[0]=1;
    for(int i=1;i<=1e4;i++) fac[i]=fac[i-1]*i%MOD;
    ll w=0;
    for(int t=r;t<=s;t++){
        for(int q=1;q<=p;q++){
            if(s-q*t<0) continue ;
            w=(w+(C(p-1,q-1)*g(s-q*t,p-q,t-1)%MOD)*inv(q)%MOD)%MOD;
        }
    }
    cout<<w*inv(C(s-1-r+p,p-1))%MOD;
    return 0;
}

