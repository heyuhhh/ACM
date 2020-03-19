#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m,tot;
int head[N];
struct Edge{
    int u,v,next,w;
}e[N*N<<1];
int T;
int dfn[N],low[N],cut[N*N];
void adde(int u,int v,int w){
    e[tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
void init(){
    T=0;tot=0;
    memset(head,-1,sizeof(head));
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
}
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++T;
    int k = 0;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre &&!k){
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
            cut[i]=cut[i^1]=1;
        }
    }
}int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n+m<=0) break;
        init();
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adde(u,v,w);adde(v,u,w);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                Tarjan(i,i);
                cnt++;
            }
        }
        if(cnt>1){
            cout<<0<<endl;
            continue ;
        }
        int ans = 0x3f3f3f3f;
        for(int i=0;i<tot;i+=2){
            if(cut[i])ans=min(ans,e[i].w);
        }
        if(ans==0x3f3f3f3f) puts("-1");
        else cout<<max(ans,1)<<endl;
    }
    return 0;
}
