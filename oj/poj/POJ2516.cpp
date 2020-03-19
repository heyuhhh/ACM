#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define t 200
#define INF 99999999
using namespace std;
typedef long long ll;
const int N = 205;
int n,m,k,tot;
int head[N],need[N][N],supply[N][N],d[N],a[N],vis[N],p[N],pre[N];
struct Edge{
    int v,next,c,w;
}e[(N*N)<<1];
void adde(int u,int v,int c,int w){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;e[tot].w=w;head[u]=tot++;
    e[tot].v=u;e[tot].next=head[v];e[tot].c=0;e[tot].w=-w;head[v]=tot++;
}
int SPFA(int &flow,int &cost){
    for(int i=0;i<=t;i++) d[i]=a[i]=INF;d[0]=0;
    memset(vis,0,sizeof(vis));vis[0]=1;
    memset(p,-1,sizeof(p));memset(pre,-1,sizeof(pre));
    queue <int> q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 && d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                p[v]=u;pre[v]=i;
                a[v]=min(a[u],e[i].c);
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(d[t]==INF) return 0;
    flow+=a[t];cost+=d[t]*a[t];
    for(int i=t;i!=-1;i=p[i]){
        int edge=pre[i];
        e[edge].c-=a[t];
        e[edge^1].c+=a[t];
    }
    return 1;
}
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        if(!n &&!m &&!k) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                scanf("%d",&need[i][j]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=k;j++)
                scanf("%d",&supply[i][j]);
        int ans=0;
        bool flag=false;
        for(int K=1;K<=k;K++){
            tot=0;memset(head,-1,sizeof(head));
            for(int i=1;i<=n;i++){
                for(int j=1,s;j<=m;j++){
                    scanf("%d",&s);
                    adde(i,j+n,INF,s);
                }
            }
            int sum=0;
            for(int i=1;i<=n;i++) adde(0,i,need[i][K],0),sum+=need[i][K];
            for(int i=n+1;i<=n+m;i++) adde(i,t,supply[i-n][K],0);
            if(flag) continue ;
            int flow=0,cost=0;
            while(SPFA(flow,cost));
            if(sum>flow) flag=true;
            ans+=cost;
        }
        if(flag) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}

