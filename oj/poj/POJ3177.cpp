#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 5005, M = 20005;
int n,m,cnt;
struct Edge{
    int u,v,next;
    bool operator < (const Edge &A)const{
        if(u==A.u) return v<A.v;
        return u<A.u;
    }
}e[M<<1],g[M<<1];
int T,tot;
int dfn[N],low[N],cut[N],f[N],d[N],num[N],head[N];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
void init(){
    T=0;tot=0;cnt=0;
    memset(head,-1,sizeof(head));
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
}
int find(int x){
    return f[x]==x ? f[x] : f[x]=find(f[x]);
}
int same(int x,int y){
    return find(x)==find(y);
}
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) f[fx]=fy;
}
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++T;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue ;
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                cut[v]=1;
            }else Union(u,v);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        adde(u,v);adde(v,u);
        g[i].u=u;g[i].v=v;
    }
    sort(g+1,g+m+1);
    for(int i=1;i<=n;i++) f[i]=i;
    Tarjan(1,0);
    for(int i=1;i<=m;i++){
        int u=g[i].u,v=g[i].v;
        if(g[i].u==g[i-1].u&&g[i].v==g[i-1].v) continue ;
        if(same(u,v)) continue ;
        int fx=find(u),fy=find(v);
        if(!num[fx]) num[fx]=++cnt;
        if(!num[fy]) num[fy]=++cnt;
        d[num[fx]]++;d[num[fy]]++;
    }
    int ans = 0;
    for(int i=1;i<=cnt;i++) if(d[i]==1) ans++;
    cout<<(ans+1)/2;
    return 0;
}
