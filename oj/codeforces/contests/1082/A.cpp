#include <bits/stdc++.h>
using namespace std;

long long t,n,x,y,d;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>x>>y>>d;
        bool flag=false;
        long long ans=9999999999;
        if(abs(y-x)%d==0) ans=abs(y-x)/d;
        if((y-1)%d==0 ) ans=min(ans,(x-1)/d+((x-1)%d!=0)+(y-1)/d);
        if((n-y)%d==0 ) ans=min(ans,(n-x)/d+((n-x)%d!=0)+(n-y)/d);
        if(ans!=9999999999) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}

