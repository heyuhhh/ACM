#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll a;
ll p2[30];
ll Print(ll x){
    for(ll i=3;i*i<=x;i++){
        if(x%i==0){
            return x/i;
        }
    }
    return 1;
}
int main(){
    cin>>q;
    p2[0]=1;
    for(int i=1;i<=26;i++) p2[i]=p2[i-1]*2;
    while(q--){
        cin>>a;
        int i;
        for(i=26;i>=0;i--) if((1<<i)&a) break ;
        if(a&(a+1)) cout<<p2[i+1]-1<<endl;
        else cout<<Print(a)<<endl;
    }
    return 0;
}
