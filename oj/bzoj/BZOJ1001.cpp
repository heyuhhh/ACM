#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f
using namespace std;

const int N = 1000005,M = 6000005;
struct Edge{
    int v,c,next;
}e[M];
int head[N],d[N],cur[N];
int n,m,tot=0;
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].c=w;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=w;e[tot].next=head[v];head[v]=tot++;
}
bool bfs(int s,int t){
    queue<int> q;
    memset(d,0,sizeof(d));d[s]=1;
    q.push(s);
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
int dfs(int s,int a){
    if(s==n*m || a==0) return a;
    int flow=0,f;
    for(int &i=cur[s];i!=-1;i=e[i].next){
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
    int ans = 0;
    while(bfs(1,n*m)){
        for(int i=1;i<=n*m;i++) cur[i]=head[i];
        ans+=dfs(1,INF);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int w;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            scanf("%d",&w);
            adde(m*(i-1)+j,m*(i-1)+j+1,w);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&w);
            adde(j+(i-1)*m,j+i*m,w);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            scanf("%d",&w);
            adde((i-1)*m+j,i*m+j+1,w);
        }
    }
    cout<<Dinic();
    return 0;
}
 
