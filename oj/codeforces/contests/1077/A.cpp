#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a,b,k;

int main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        ll ans=(k/2)*(a-b);
        if(k&1)ans+=a;
        cout<<ans<<endl;
    }
    return 0;
}
