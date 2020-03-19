#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m,c,t,tot;
int head[N],d[N],vis[N],belong[N],lay[N];
struct Edge{
    int v,w,next ;
}e[N<<3];
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
    q.push(node{0,s});
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                q.push(node{d[v],v});
            }
        }
    }
}
int main(){
    cin>>t;
    int cnt =0;
    while(t--){
        cnt++;
        scanf("%d%d%d",&n,&m,&c);
        memset(head,-1,sizeof(head));tot=0;
        memset(belong,0,sizeof(belong));
        memset(lay,0,sizeof(lay));
        for(int i=1,tmp;i<=n;i++){
            scanf("%d",&tmp);
            lay[tmp]=1;
            belong[i]=tmp;
        }
        for(int i=2;i<=n;i++){
            if(!lay[i] || !lay[i-1]) continue ;
            adde(i+n,i+n-1,c);
            adde(i+n-1,i+n,c);
        }
        for(int i=1;i<=n;i++){
            int tmp = belong[i];
            adde(n+tmp,i,0);
            if(tmp>1) adde(i,tmp+n-1,c);
            if(tmp<n) adde(i,tmp+n+1,c);
            //adde(i,n+tmp,0);
        }
        for(int i=1,u,v,w;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            adde(u,v,w);adde(v,u,w);
        }
        Dijkstra(1);
        printf("Case #%d: ",cnt);
        if(d[n]==INF) puts("-1");
        else cout<<d[n]<<endl;
    }
    return 0;
}
