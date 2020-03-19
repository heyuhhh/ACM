#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 2e5+5,M = 1e6+5;
int n,m;
int head[N];
struct Edge{
    int u,v,next;
    bool operator < (const Edge &A){
        if(u==A.u) return v<A.v;
        return u<A.u;
    }
}e[M<<1],g[M<<1];
int T,tot,cnt;
int dfn[N],low[N],cut[N],num[N],f[N];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
void init(){
    T=0;tot=0;cnt=0;
    memset(head,-1,sizeof(head));
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    for(int i=0;i<=n+1;i++) f[i]=i;
}
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) f[fx]=fy;
}
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++T;
    int k=0;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre && !k){
            k=1;
            continue ;
        }
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
        if(low[v]>dfn[u]){
            cut[v]=1;
        }else Union(u,v);
    }
}
int mx=0,node=1;
void dfs(int u,int d,int pa){
    if(d>mx){
        mx=d;
        node=u;
    }
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pa) continue ;
        dfs(v,d+1,u);
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m) break ;
        init();
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            adde(u,v);adde(v,u);
            if(u>v)swap(u,v);
            g[i].u=u;g[i].v=v;
        }
        sort(g+1,g+m+1);
        Tarjan(1,0);
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=m;i++){
            int u=g[i].u,v=g[i].v;
            if(g[i].u==g[i-1].u&&g[i].v==g[i-1].v) continue ;
            int fx=find(u),fy=find(v);
            if(!num[fx]) num[fx]=++cnt;
            if(!num[fy]) num[fy]=++cnt;
            if(num[fx]==num[fy]) continue ;
            adde(num[fx],num[fy]);adde(num[fy],num[fx]);
        }
        mx=0;
        dfs(1,0,-1);
        mx=0;
        dfs(node,0,-1);
        cout<<cnt-1-mx<<endl;
    }
    return 0;
}
