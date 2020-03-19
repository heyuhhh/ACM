#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,k;
ll a[N],b[N],c[N];
vector <ll> vec[N];
bool check(ll x){
//x=25;
    for(int i=1;i<=k;i++) vec[i].clear();
    memcpy(c,a,sizeof(a));
    for(int i=1;i<=n;i++){
        ll pos=a[i]/b[i]+1;
        if(pos<=k){
            vec[pos].push_back(i);
            c[i]=a[i]%b[i];
        }
    }
    ll last=1;
    for(int i=1;i<=k;i++){
        while(last<=k&&vec[last].empty()) last++;
        if(last==k+1) return true;
        if(last<i) return false ;
        int now = vec[last].back();
        if(c[now]+x<b[now]){
            c[now]+=x;
            continue ;
        }
        c[now]+=x;
        vec[last].pop_back();
        if(last+c[now]/b[now]<=k){
            vec[last+c[now]/b[now]].push_back(now);
            c[now]%=b[now];
        }
    }
    return true;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll l=0,r=1e16,mid;
    while(l<r){
        mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==1e16) cout<<-1;
    else cout<<r;
    return 0;
}
