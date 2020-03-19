#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;

typedef long long ll ;
const int N =5e5+5 ;
int a[N],dp[25][N];
int n,st;
vector <int> vec[N];
ll ans;
void dfs(int u,int pa){
    dp[0][u]=pa;
    for(int i=1;i<20;i++){
        if(dp[i-1][u]==-1) break ;
        dp[i][u]=dp[i-1][dp[i-1][u]];
    }
    ll minx = INF;
    int i;
    for(i=0;i<20;i++){
        if(dp[i][u]==-1) break ;
        minx=min((ll)(i+1)*a[dp[i][u]]+a[u],minx);
    }
    minx=min((ll)(i+1)*a[st]+a[u],minx);
    if(u!=st) ans+=minx;
    for(auto v:vec[u]){
        if(v!=pa) dfs(v,u);
    }
}
int main(){
    scanf("%d",&n);
    st=0;a[0]=1e9+5;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<a[st])st=i;
    }
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    dfs(st,-1);
    printf("%I64d",ans);
    return 0;
}

