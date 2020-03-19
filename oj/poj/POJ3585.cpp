#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1e9
#define mp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,T;
int dp[N];
vector <pair<int,int> > g[N];
void dfs(int node,int pa){
    int tmp = 0;
    for(int i=0;i<g[node].size();i++){
        int v=g[node][i].first,w=g[node][i].second;
        if(v==pa) continue ;
        dfs(v,node);
        tmp+=min(dp[v],w);
    }
    if(tmp>0) dp[node]=tmp;
    return ;
}
int ans=0;
void go(int u,int pa,int sum){
    ans=max(ans,sum);
    int len = g[u].size();
    for(int i=0;i<len;i++){
        int v=g[u][i].first,w=g[u][i].second;
        if(v==pa) continue ;
        if(len==1) go(v,u,dp[v]+w);
        else go(v,u,dp[v]+min(sum-min(dp[v],w),w));
    }
}
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        if(n==0){
            puts("0");
            continue ;
        }
        ans=0;memset(dp,INF,sizeof(dp));
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(mp(v,w));
            g[v].push_back(mp(u,w));
        }
        dfs(1,-1);
        for(int i=1;i<=n;i++) dp[i]=(dp[i]==INF?0:dp[i]);
        go(1,-1,dp[1]);
        cout<<ans<<endl;
    }
    return 0;
}

