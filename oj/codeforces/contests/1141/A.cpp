#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans = 1e18;
void dfs(ll k,ll cnt ){
    if(k>m) return ;
    if(k==m){
        ans=min(ans,cnt);
        return ;
    }
    dfs(2*k,cnt+1);dfs(3*k,cnt+1);
}
int main(){
    cin>>n>>m;
    dfs(n,0);
    if(ans==1e18) cout<<-1;
    else cout<<ans;
    return 0;
}
