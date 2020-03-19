#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int t,n,m,tot;
int head[N],num[N],in[N],out[N];
stack <int> s;
struct Edge{
    int u,v,next;
}e[N<<1],g[N<<1];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
int T,cc;
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
        cc++;int now;
        do{
            now = s.top();s.pop();
            scc[now]=cc;
            num[cc]++;
        }while(!s.empty() && now!=u);
    }
}
int main(){
    cin>>t;
    int Case=0;
    while(t--){
        Case++;
        memset(head,-1,sizeof(head));tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[i].u=u;g[i].v=v;
            adde(u,v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(scc,0,sizeof(scc));T=0;
        memset(vis,0,sizeof(vis));cc=0;
        memset(num,0,sizeof(num));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++){
            if(!vis[i]) Tarjan(i);
        }
        printf("Case %d: ",Case);
        if(cc==1){
            puts("-1");
            continue ;
        }
        for(int i=1;i<=m;i++){
            int u=g[i].u,v=g[i].v;
            if(scc[u]==scc[v]) continue ;
            in[scc[v]]++;out[scc[u]]++;
        }
        ll tmp = n*(n-1)-m;
        ll ans = 0;
        for(int i=1;i<=cc;i++){
            if(!in[i] || !out[i]) ans=max(ans,tmp-num[i]*(n-num[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
