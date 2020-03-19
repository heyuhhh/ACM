#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b;

int main(){
    cin>>n>>b;
    ll ans = 2e18;
    for(ll i=2;i*i<=b;i++){
        ll a=0,c=0;
        if(b%i!=0) continue ;
        while(b%i==0) b/=i,c++;
        ll m=n;
        while(m) a+=m/i,m/=i;
        ans=min(ans,a/c);
    }
    if(b>1){
        ll a=0;
        while(n) a+=n/b,n/=b;
        ans=min(ans,a);
    }
    cout<<ans<<endl;
    return 0;
}
