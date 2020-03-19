#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1<<30
using namespace std;
typedef long long ll;
const int N =1005, M = 1e5+5;
int n,m,s,t,T,mx;
int d1[N],d2[N],d[N],vis[N],head[N];
pair <pair<int,int>,int> E[M];
struct Edge{
    int v,next,c,w;
}e[M<<1];
int tot;
void adde(int u,int v,int c,int w){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];e[tot].w=w;head[u]=tot++;
}
void spfa(int S){
    queue <int> q;q.push(S);
    memset(vis,0,sizeof(vis));vis[S]=1;
    for(int i=1;i<=n;i++) d2[i]=INF;d2[S]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d2[v]>d2[u]+e[i].w){
                d2[v]=d2[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int bfs(){
    memset(d,0,sizeof(d));d[s]=1;
    queue <int > q;q.push(s);
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
int dfs(int u,int a){
    if(u==t || a==0) return a;
    int flow=0,f;
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
    int flow=0;
    while(bfs()) flow+=dfs(s,INF);
    return flow;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        tot=0;memset(head,-1,sizeof(head));
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            E[i]=make_pair(make_pair(u,v),w);
            adde(u,v,1,w);
        }
        scanf("%d%d",&s,&t);
        spfa(s);
        for(int i=1;i<=n;i++) d1[i]=d2[i];
        tot=0;memset(head,-1,sizeof(head));
        for(int i=1;i<=m;i++){
            int u=E[i].first.first,v=E[i].first.second,w=E[i].second;
            adde(v,u,1,w);
        }
        spfa(t);
        mx=d1[t];
        tot=0;memset(head,-1,sizeof(head));
        for(int i=1;i<=m;i++){
            int u =E[i].first.first,v=E[i].first.second,w=E[i].second;
            if(d1[u]+d2[v]+w==mx){
                adde(u,v,1,INF);
                adde(v,u,0,INF);
            }
        }
        printf("%d\n",Dinic());
    }
    return 0;
}

