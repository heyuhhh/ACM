#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
ll a[N],sum[N];
ll h;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>h>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(h+sum[i]<=0){
            cout<<i;
            return 0;
        }
    }
    if(sum[n]>=0){
        cout<<-1;
        return 0;
    }
//
    ll tmp = h;
    ll ans = 1e18;
    for(ll i=1;i<=n;i++){
        tmp = h ;
        tmp+=sum[i];
        ll now = abs(sum[n]);
        ll cnt = (tmp-1)/now+1;
        ans=min(ans,cnt*n+i);
    }
    cout<<ans;
    return 0;
}
