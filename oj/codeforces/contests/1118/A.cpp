#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,a,b;
int t;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if(2*a>=b){
            ll ans = n/2*b;
            if(n&1) ans+=a;
            cout<<ans<<endl;
        }else{
            ll ans = a*n;
            cout<<ans<<endl;
        }
    }
    return 0;
}
