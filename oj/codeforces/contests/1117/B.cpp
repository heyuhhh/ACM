#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,m,k;
ll a[N];
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll fir = a[1],sec = a[2];
    ll ans=0;
    if(fir==sec){
        cout<<m*fir;
    }else{
        ans = k*fir+sec;
        ll tmp = m/(k+1);
        ans*=tmp;
        tmp*=(k+1);
        ans+=(m-tmp)*fir;
        cout<<ans;
    }
    return 0;
}
