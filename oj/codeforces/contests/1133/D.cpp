#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N],b[N],c[N],d[N],f[N];
ll n,k;
map <pair<ll,ll>,ll>mp;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int cnt = 0;
    for(int i=1;i<=n;i++){
        ll g=__gcd(abs(a[i]),abs(b[i]));
        if(b[i]==0 && a[i]==0){
            cnt++;
            continue ;
        }else if(b[i]==0){
            ans++;
            continue ;
        }else if(a[i]==0){
            continue ;
        }
        a[i]/=g;b[i]/=g;
        c[i]=abs(a[i]);d[i]=abs(b[i]);
        if((a[i]<0&&b[i]>0) ||(a[i]>0&&b[i]<0)){
            c[i]=-c[i],d[i]=abs(d[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0||a[i]==0) continue ;
        mp[make_pair(c[i],d[i])]++;
        if(mp[make_pair(c[i],d[i])]>ans){
            ans=mp[make_pair(c[i],d[i])];
        }
    }
    cout<<ans+cnt;
    return 0;
}
