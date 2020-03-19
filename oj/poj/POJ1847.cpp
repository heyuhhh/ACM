#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 105;
int A,B,n,k;
int d[N],head[N],vis[N];
struct Edge{
    int u,v,w,next ;
}e[N*N<<1];
int tot;
struct node{
    int d,u;
    bool operator < (const node &A)const{
        return d>A.d;
    }
};
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
void Dijkstra(int s){
    priority_queue <node> q;memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));d[s]=0;
    node now;
    now.d=0;now.u=s;
    q.push(now);
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[cur.u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                now.d=d[v];now.u=v;
                q.push(now);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&A,&B);
    memset(head,-1,sizeof(head));
    for(int i=1,v;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&v);
            if(j==1) adde(i,v,0);
            else adde(i,v,1);
        }
    }
    Dijkstra(A);
    if(d[B]==INF) cout<<-1;
    else cout<<d[B];
    return 0;
}
