#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
int n;
int a[N],x[N],y[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    ll ans = 1;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    ans+=min(x[1],y[1]);
    for(int i=2;i<=n;i++){
        if(x[i]>y[i]){
            int dx=x[i]-x[i-1],dy=y[i]-y[i-1];
            if(y[i]<x[i-1]) continue ;
            if(y[i-1]<x[i-1]) ans+=(y[i]-x[i-1]+1);
            else if(y[i-1]>x[i-1]) ans+=dy+1;
            else ans+=min(dx,dy);
        }else{
            int dx=x[i]-x[i-1],dy=y[i]-y[i-1];
            if(x[i]<y[i-1]) continue ;
            if(x[i-1]<y[i-1]) ans+=(x[i]-y[i-1]+1);
            else if(x[i-1]>y[i-1]) ans+=dx+1;
            else ans+=min(dx,dy);
        }
    }
    cout<<ans;
}
