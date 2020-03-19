//n*n!-n!*sum_k(1<=k<n)1/k!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353,N = 1e6+5;
ll fac[N],inv[N];
ll n;
ll qp(ll a,ll b){
    ll ans =1;
    while(b){
        if(b&1) ans=a*ans%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans ;
}
int main(){
    cin>>n;
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++) fac[i]=i*fac[i-1]%MOD;
    for(int i=1;i<=n;i++) inv[i]=qp(fac[i],MOD-2);
    ll ans = n*fac[n]%MOD;
    ll tmp = fac[n];
    ll sum = 0;
    for(int i=1;i<n;i++)
        sum=(sum+inv[i])%MOD;
    ans = ((ans-tmp*sum)%MOD+MOD)%MOD;
    cout<<ans;
    return 0;
}
/*
//i:1~n-1
//(n-i)*i*(f[n]/f[n-i+1])
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353 ,N = 1e6+5;
ll n;
ll fac[N];
ll qp(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans ;
}
int main(){
    cin>>n;
    ll ans = 1;
    fac[0]=1;
    for(int i=1;i<=1e6;i++) fac[i]=fac[i-1]*i%MOD;
    for(int i=n-1;i>=1;i--){
        ll d = n-i;
        ll now = fac[n]*qp(fac[n-i+1],MOD-2)%MOD;
        ans=(ans+(ll)i*now%MOD*d%MOD)%MOD;//out
    }
    cout<<ans;
    return 0;
}

*/
