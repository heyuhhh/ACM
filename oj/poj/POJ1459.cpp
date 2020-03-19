#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 99999999
#define t 200
using namespace std;
typedef long long ll;
const int N = 205;
int head[N],d[N];
int tot,n,np,nc,m;
struct Edge{
    int v,c,next;
}e[(N*N)<<1];
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].c=w;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
int bfs(){
    memset(d,0,sizeof(d));d[0]=1;
    queue <int > q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 && !d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int s,int a){
    if(s==t || a==0) return a;
    int flow=0,f;
    for(int i=head[s];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[s]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f>0){
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
    int flow=0;
    while(bfs()) flow+=dfs(0,INF);
    return flow;
}
int main(){
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
        tot=0;memset(head,-1,sizeof(head));
        for(int i=1,u,v,w;i<=m;i++){
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&w);
            u++;v++;
            adde(u,v,w);
        }
        for(int i=1,u,w;i<=np;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&w);
            u++;
            adde(0,u,w);
        }
        for(int i=1,v,w;i<=nc;i++){
            while(getchar()!='(');
            scanf("%d)%d",&v,&w);
            v++;
            adde(v,t,w);
        }
        printf("%d\n",Dinic());
    }
    return 0;
}

