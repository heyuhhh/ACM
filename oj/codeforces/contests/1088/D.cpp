#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 9999999999
using namespace std;

const int N = 3e5+5 ;
typedef long long ll;
int a[N],head[N],vis[N];
int n,tot,k;
struct Edge{
    int u,v,next;
}e[N<<1];
ll dp[N];
ll ans=-INF;
void adde(int u,int v){
    e[++tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot;
    e[++tot].u=v;e[tot].v=u;e[tot].next=head[v];head[v]=tot;
}
void dfs(int node,int f){
    dp[node]=a[node];
    vis[node]=1;
    for(int i=head[node];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!vis[v]){
            vis[v]=1;
            dfs(v,f);
            if(dp[v]>0) dp[node]+=dp[v];
        }
    }
    if(!f) ans=max(ans,dp[node]);
    else{
        if(dp[node]==ans){
            k++;
            dp[node]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1,u,v;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        adde(u,v);
    }
    dfs(1,0);
    memset(vis,0,sizeof(vis));
    dfs(1,1);
    cout<<ans*k<<" "<<k<<endl;
    return 0;
}

