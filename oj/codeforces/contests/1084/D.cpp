#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int n;
ll a[N],dp[N];
ll ans;
vector <pair<int,int> > g[N];
void dfs(int node,int pa){
    ans=max(ans,a[node]);
    ll mx=0;
    for(auto v:g[node]){
        if(v.first==pa) continue ;
        dfs(v.first,node);
        ans=max(ans,mx+dp[v.first]-v.second+a[node]);
        mx=max(mx,dp[v.first]-v.second);
    }
    dp[node]=mx+a[node];
    return ;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        g[u].push_back(make_pair(v,c));
        g[v].push_back(make_pair(u,c));
    }
    dfs(1,-1);
    cout<<ans<<endl;
    return 0;
}
