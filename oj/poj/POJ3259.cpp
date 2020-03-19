#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 505,M = 2505;
int T,n,m,w;
int head[N],d[N],c[N],vis[N];
struct Edge{
    int u,v,w,next;
}e[M<<2];
int tot;
void adde(int u,int v,int w){
    e[tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
int spfa(int s){
    queue <int> q;
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));memset(c,0,sizeof(c));
    q.push(s);vis[s]=1;d[s]=0;c[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(c[u]>n){
            return 1;
        }
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    c[v]++;
                }
            }
        }
    }
     return 0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&w);
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=m;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            adde(u,v,c);adde(v,u,c);
        }
        for(int i=1;i<=w;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            adde(u,v,-c);
        }
        int flag=0;
        if(spfa(1)) flag=1;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
