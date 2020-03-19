#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

const int N = 10005 ,M = 50005 ;
int n,m,tot,num,T;
int head[N],dfn[N],low[N],vis[N],scc[N];
struct Edge{
    int u,v,next ;
}e[M];
void adde(int u,int v){
    e[++tot].u=u;e[tot].v=v;
    e[tot].next=head[u];head[u]=tot ;
}
stack <int> s;
void Tanjan(int u){
    dfn[u]=low[u]=++T;vis[u]=1;
    s.push(u);
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!vis[v]){
            Tanjan(v);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        num++;int now;
        do{
            now = s.top();s.pop();
            scc[now]=num;
        }while(!s.empty() && now!=u);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        adde(u,v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) Tanjan(i);
    }
    int out[N]={0},in[N]={0};
    for(int u=1;u<=n;u++){
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(scc[u]!=scc[v]){
                out[scc[u]]++;
                in[scc[v]]++;
            }
        }
    }
    int cnt=0,ans=0,tag;
    for(int i=1;i<=num;i++) if(!out[i]) cnt++,tag=i;
    if(cnt==1){
        for(int i=1;i<=n;i++) if(scc[i]==tag) ans++;
        printf("%d",ans);
    }else puts("0");
    return 0;
}

