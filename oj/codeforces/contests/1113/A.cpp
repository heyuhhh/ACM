#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,v;
int main(){
    cin>>n>>v;
    int fir=2,las=n-v;
    int ans=v;
    if(n-1<=v){
        cout<<n-1;
        return 0;
    }
    for(int i=2;i<=las;i++){
        ans+=i;
    }
    cout<<ans;
    return 0;
}
