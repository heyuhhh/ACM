#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1005;
int T;
int n,tot,m;
int head[N],vis[N],d[N];
struct Edge{
    int u,v,next,w;
}e[N*N<<1];
struct node{
    int d,u;
    bool operator < (const node &A)const{
        return d<A.d;
    }
};
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot++;
}
void Dijkstra(int s){
    priority_queue <node> q;
    memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
    node now;d[s]=INF;
    now.d=INF;now.u=s;
    q.push(now);
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]<min(d[u],e[i].w)){
                d[v]=min(d[u],e[i].w);
                now.d=d[v];now.u=v;
                q.push(now);
            }
        }
    }
}
int main(){
    cin>>T;
    int cnt = 0,first=1;
    while(T--){
        cnt++;
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=m;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            adde(u,v,c);adde(v,u,c);
        }
        Dijkstra(1);
        printf("Scenario #%d:\n",cnt);
        cout<<d[n]<<endl;
        cout<<endl;
    }
    return 0;
}
