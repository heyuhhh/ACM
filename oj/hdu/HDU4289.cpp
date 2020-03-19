#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 99999999
using namespace std;
typedef long long ll;
const int N = 505,M = 1e5;
int head[N],d[N];
int tot,n,m,s,t;
struct Edge{
    int v,next,c;
}e[M];
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
    return d[t]!=0;
}
int dfs(int u,int a){
    int flow=0,f;
    if(u==t || a==0) return a;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[u]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f>0){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[u]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(s,t))
        max_flow+=dfs(s,INF);
    return max_flow;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(head,-1,sizeof(head));tot=0;
        scanf("%d%d",&s,&t);
        t+=200;
        for(int i=1,c;i<=n;i++){
            scanf("%d",&c);
            adde(i,i+200,c);
        }
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            adde(u+200,v,INF);
            adde(v+200,u,INF);
        }
        printf("%d\n",Dinic());
    }
    return 0;
}

