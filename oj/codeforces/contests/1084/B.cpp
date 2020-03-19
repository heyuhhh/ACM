#include <bits/stdc++.h>
#define INF 9999999999999999
using namespace std;
typedef long long ll;
const int N = 1005;
ll n,s,minx=INF;
ll v[N];
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) scanf("%I64d",&v[i]),minx=min(minx,v[i]);
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=(v[i]-minx);
    if(sum>=s){
        cout<<minx;
        return 0;
    }
    s-=sum;
    ll now = s/n+(s%n!=0);
    ll ans = minx-now;
    if(ans>=0) cout<<ans;
    else cout<<-1;
    return 0;
}
