#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5,MOD = 998244353 ;
ll n,m;
char s1[N],s2[N];
ll sum[N];
ll qp(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans=a*ans%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans ;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s1);
    scanf("%s",s2);
    if(s1[n-1]=='1') sum[0]=1;
    for(int i=n-2;i>=0;i--){
        if(s1[i]=='1') sum[n-i-1]=(sum[n-i-2]+qp(2,n-1-i))%MOD;
        else sum[n-i-1]=sum[n-i-2];
    }
    ll ans = 0;
    for(int i=m-1;i>=0;i--){
        if(s2[i]=='1'){
            ans=(ans+sum[min(m-1-i,n-1)])%MOD;
        }
    }
    cout<<ans;
    return 0;
}
