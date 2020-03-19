#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;
const int N = 105,M = 100005,P = 1005;
int n,F,D;
int head[P+5],d[P+5],tot;
struct Edge{
    int v,next,c;
}e[M];
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].c=w;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
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
int dfs(int s,int a){
    int flow=0,f;
    if(s==P || a==0) return a;
    for(int i=head[s];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[s]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[s]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(0,P))
        max_flow+=dfs(0,INF);
    return max_flow;
}
int main(){
    scanf("%d%d%d",&n,&F,&D);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=F;i++) adde(0,i,1);
    for(int i=F+1;i<=F+D;i++) adde(i,P,1);
    for(int i=1,k1,k2;i<=n;i++){
        adde(300+i,400+i,1);
        scanf("%d%d",&k1,&k2);
        for(int j=1,c;j<=k1;j++){
            scanf("%d",&c);
            adde(c,300+i,1);
        }
        for(int j=1,c;j<=k2;j++){
            scanf("%d",&c);
            adde(400+i,F+c,1);
        }
    }
    printf("%d",Dinic());
    return 0;
}

