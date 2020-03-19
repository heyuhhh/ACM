#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,k;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    k=(n+1)*n/(ll)2;
    int f=0;
    ll i;
    for(i=2;i*i<=k;i++){
        if(k%i==0){
            f=1;
            break ;
        }
    }
    if(!f || k/i<=1){
        cout<<"No";
    }else{
        cout<<"Yes"<<'\n';
        cout<<1<<" "<<i<<'\n';
        cout<<n-1;
        for(ll j=1;j<=n;j++){
            if(j==i) continue ;
            cout<<" "<<j;
        }
    }
    return 0;
}
