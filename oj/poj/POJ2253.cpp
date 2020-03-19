#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 205;
int n;
int x[N],y[N],head[N],vis[N];
int tot;
double d[N];
double dis(int a,int b){
    return sqrt((double)(x[a]-x[b])*(x[a]-x[b])+(double)(y[a]-y[b])*(y[a]-y[b]));
}
struct Edge{
    int u,v,next;
    double w;
}e[N*N<<1];
struct node{
    int u;
    double d;
    bool operator < (const node &A)const{
        return d>A.d;
    }
};
void adde(int u,int v,double w){
    e[tot].v=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot++;
}
void Dijkstra(int s){
    priority_queue <node> q;
    for(int i=1;i<=n;i++) d[i]=INF;
    memset(vis,0,sizeof(vis));
    node now;d[s]=0;
    now.d=0;now.u=s;
    q.push(now);
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>max(d[u],e[i].w)){
                d[v]=max(d[u],e[i].w);
                now.d=d[v];now.u=v;
                q.push(now);
            }
        }
    }
}
int main(){
    int cnt =0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break ;
        cnt++;
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue ;
                adde(i,j,dis(i,j));
            }
        }
        Dijkstra(1);
        printf("Scenario #%d\n",cnt);
        printf("Frog Distance = %.3f\n",d[2]);
        printf("\n");
    }
    return 0;
}
