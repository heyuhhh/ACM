#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5,MOD = 998244353 ;
map <int,int>r;
int n;
int a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        r[a[i]]=i;
    }
    ll ans = 1;
    for(int i=1;i<=n;i++){
        int cur = r[a[i]];
        if(i>1){
            ans*=2;
            if(ans>=MOD) ans-=MOD;
        }
        while(i<cur){
            i++;
            cur=max(r[a[i]],cur);
        }
    }
    cout<<ans;
    return 0;
}

