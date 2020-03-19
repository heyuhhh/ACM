#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5+5,M  = 2e5+5;
int n,m,ans;
int head[N];
struct Edge{
    int u,v,next;
}e[M<<1];
int T,tot;
int dfn[N],low[N],cut[N],f[N],pa[N];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
void init(){
    T=0;tot=0;ans=0;
    memset(head,-1,sizeof(head));
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
    memset(pa,0,sizeof(pa));
    for(int i=0;i<=n;i++) f[i]=i;
}
int find(int x){
    return f[x]==x ? x : f[x]=find(f[x]);
}
void Union(int u,int v){
    int fx=find(u),fy=find(v);
    if(fx!=fy) f[fx]=fy;
    return ;
}
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++T;
    int son=0;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue ;
        if(!dfn[v]){
            pa[v]=u;
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                cut[v]=1;
                ans++;
            }else Union(u,v);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int lca(int u,int v){
    if(dfn[u]<dfn[v]) swap(u,v);
    while(dfn[u]>dfn[v]){
        int fx=find(u),fy=find(pa[u]);
        if(fx!=fy){
            ans--;
            f[fx]=fy;
        }
        u=pa[u];
    }
    while(dfn[v]>dfn[u]){
        int fx=find(v),fy=find(pa[v]);
        if(fx!=fy){
            ans--;
            f[fx]=fy;
        }
        v=pa[v];
    }
    return ans ;
}
int main(){
    int cnt = 0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n+m<=0) break ;
        cnt++;
        init();
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            adde(u,v);adde(v,u);
        }
        Tarjan(1,-1);
        int q;
        printf("Case %d:\n",cnt);
        scanf("%d",&q);
        while(q--){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",lca(u,v));
        }
    }
    return 0;
}
