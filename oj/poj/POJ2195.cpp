#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const int N = 105 ,INF = 99999999,t = 505;
int n,m,cnt,tot,num;
int map[N][N],d[N][N],head[N*N],dis[N*N],vis[N*N],a[N*N],p[N*N],pre[N*N];
int Dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
struct Edge{
    int u,v,next,c,w;
}e[N*N*N];
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].c=1;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].w=-w;e[tot].next=head[v];head[v]=tot++;
}
int BellmanFord(int s,int t,int &flow,int &cost){
    for(int i=0;i<=t+5;i++) dis[i]=INF,a[i]=INF;
    queue <int> q;memset(vis,0,sizeof(vis));memset(p,-1,sizeof(p));
    memset(pre,-1,sizeof(pre));
    q.push(s);vis[s]=1;dis[s]=0;p[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 &&dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                a[v]=min(a[u],e[i].c);
                p[v]=u;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[t]==INF) return 0;
    flow+=a[t];
    cost+=a[t]*dis[t];
    for(int i=t;i>0;i=p[i]){//
        e[pre[i]].c-=a[t];
        e[pre[i]^1].c+=a[t];
    }
    return 1;
}
int Min_cost(){
    int flow=0,cost=0;
    while(BellmanFord(0,t,flow,cost));
    return cost;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        tot=0;num=0;cnt=0;
        memset(head,-1,sizeof(head));
        vector <pair<int,int> > h;
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++){
            char s[N];
            scanf("%s",s);
            for(int j=0;j<m;j++){
                if(s[j]=='H'){
                    map[i][j+1]=2;
                    h.push_back(make_pair(i,j+1));
                }
                if(s[j]=='m') map[i][j+1]=1,num++;
            }
        }
        for(int i=1;i<=num;i++) adde(0,i,0);
        for(int i=num+1;i<=2*num;i++) adde(i,t,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]!=1) continue ;
                cnt++;int tmp=0;
                for(int k=0;k<h.size();k++){
                    tmp++;
                    pair <int,int> v = h[k];
                    adde(cnt,num+tmp,Dis(i,j,v.first,v.second));
                }
            }
        }
        printf("%d\n",Min_cost());
    }
    return 0;
}

