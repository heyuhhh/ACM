#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 105;
int n,tot;
int head[N],in[N],out[N],low[N],dfn[N],vis[N],scc[N];
struct Edge{
    int u,v,next;
}e[N*N<<1],edge[N*N<<1];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
stack <int> s;
int T,num;
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
    scanf("%d",&n);
    int m=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        int v;
        while(scanf("%d",&v)!=EOF){
            if(v==0) break ;
            edge[++m].u=i;edge[m].v=v;
            adde(i,v);
        }
    }
    //cout<<m<<endl;
    for(int i=1;i<=n;i++){
        if(!vis[i]) Tarjan(i);
    }
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v;
        if(scc[u]!=scc[v]){
            in[scc[v]]++;out[scc[u]]++;
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=1;i<=num;i++){
        if(!in[i]) cnt1++;
        if(!out[i]) cnt2++;
    }
    //cout<<num<<endl;
    if(num==1) cout<<1<<endl<<0;
    else cout<<cnt1<<endl<<max(cnt2,cnt1);
    return 0;
}
