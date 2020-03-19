#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 99999999
using namespace std;
typedef long long ll;
const int N = 1e5+5 ;
int T,s,t,u,v,tot,n,m;
int head[N],d[N];
struct Edge{
    int v,next,c;
}e[N<<1];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;head[u]=tot++;
    e[tot].v=u;e[tot].next=head[v];e[tot].c=c;head[v]=tot++;
}
int bfs(){
    memset(d,0,sizeof(d));d[s]=1;
    queue<int> q;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(!d[v] &&e[i].c>0){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int u,int a){
    if(u==t || a==0) return a;
    int flow=0,f;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[u]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f>0){
            flow+=f;
            e[i].c-=f;
            e[i^1].c+=f;
            a-=f;
            if(a==0) break ;
        }
    }
    if(!flow) d[u]=-1;
    return flow;
}
int Dinic(){
    int flow= 0;
    while(bfs()) flow+=dfs(s,INF);
    return flow;
}
int main(){
    scanf("%d",&T);
    while(T--){
        tot=0;memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        int minx = 99999999,maxx = -99999999 ;
        for(int i=1,u,v;i<=n;i++){
            scanf("%d%d",&u,&v);
            if(minx>u){
                minx=u;s=i;
            }
            if(maxx<u){
                maxx=u;t=i;
            }
        }
        for(int i=1,u,v,c;i<=m;i++){
            scanf("%d%d%d",&u,&v,&c);
            adde(u,v,c);
        }
        printf("%d\n",Dinic());
    }
    return 0;
}

