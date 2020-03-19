#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define s 0
#define t n+1
#define INF 1e9
using namespace std;
typedef long long ll;
const int N = 205,M = 1005;
int n,m,T,tot;
int head[N],in[N],out[N],d[N];
struct Edge{
    int v,next,c;
}e[M<<2];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;head[u]=tot++;
    e[tot].v=u;e[tot].next=head[v];e[tot].c=0;head[v]=tot++;
}
bool bfs(int S,int T){
    memset(d,0,sizeof(d));d[S]=1;
    queue <int > q;q.push(S);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(!d[v] && e[i].c>0){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[T]!=0;
}
int dfs(int S,int a){
    int flow=0,f;
    if(S==t || a==0) return a;
    for(int i=head[S];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[S]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[S]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(0,t)){
        max_flow+=dfs(0,INF);
    }
    return max_flow;
}
int main(){
    scanf("%d",&T);
    while(T--){
        tot=0;memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));memset(out,0,sizeof(out));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,op;
            scanf("%d%d%d",&u,&v,&op);
            if(op==0) adde(u,v,1);
            else adde(u,v,0);
            in[v]++;out[u]++;
        }
        int flag=1,sum=0;
        for(int i=1;i<=n;i++){
            int now = in[i]-out[i];
            if(now&1) flag=0;
            if(now>0) adde(i,t,now/2);
            if(now<=0) adde(s,i,-now/2),sum+=now/2;
        }
        sum=-sum;
        if(!flag){
            puts("impossible");
            continue ;
        }
        int flow = Dinic();
        if(flow==sum) puts("possible");
        else puts("impossible");
    }
    return 0;
}

