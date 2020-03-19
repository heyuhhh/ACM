#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std ;
typedef long long ll;
const int N = 4005;
int n,tot;
int head[N];
struct Edge{
    int u,v,next;
}e[4100010];
void adde(int u,int v){
    e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
vector <int> ans[N],g[N];
stack <int> s;
int T,num;
int scc[N],dfn[N],low[N],vis[N];
void Tarjan(int u){
    dfn[u]=low[u]=++T;vis[u]=1;
    s.push(u);
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!vis[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!scc[v]){
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
    while(scanf("%d",&n)!=EOF){
        memset(scc,0,sizeof(scc));
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++) g[i].clear(),ans[i].clear();
        num=0;T=0;tot=0;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                int l;
                scanf("%d",&l);
                g[i].push_back(l);
                adde(i,l+n);
            }
        }
        for(int i=1;i<=n;i++){
            int l;
            scanf("%d",&l);
            adde(l+n,i);
        }
        for(int i=1;i<=2*n;i++){
            if(!vis[i]) Tarjan(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=head[i];j!=-1;j=e[j].next){
                int v=e[j].v;v-=n;
                if(scc[i]==scc[v+n]) ans[i].push_back(v);
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",(int)ans[i].size());
            sort(ans[i].begin(),ans[i].end());
            for(int j=0;j<ans[i].size();j++){
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

