#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 30005,M = 150005;
int n,m;
int head[N],vis[N],d[N];
struct Edge{
    int u,v,w,next ;
}e[M<<1];
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
                now.u=v;now.d=d[v];
                q.push(now);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        adde(u,v,c);
    }
    Dijkstra(1);
    cout<<d[n];
    return 0;
}
