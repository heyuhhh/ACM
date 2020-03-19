#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 9999999999999999
using namespace std;
typedef long long ll;
const int N = 1005,M = 20005;
ll d[N];
int vis[N],head[N],c[N];
int n,ml,md;
struct Edge{
    int u,v,w,next;
}e[M<<1];
int tot;
void adde(int u,int v,int w){
    e[tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
ll spfa(int s){
    queue <int> q;
    for(int i=1;i<=n;i++) d[i]=INF;
    q.push(s);vis[s]=1;d[1]=0;c[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(c[u]>n) return -1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>=d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    c[v]++;
                }
            }
        }
    }
    return d[n];
}
int main(){
    cin>>n>>ml>>md;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=ml;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
    }
    for(int i=1;i<=md;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adde(v,u,-w);
    }
    ll flag = spfa(1);
    if(flag==INF){
        cout<<-2;
        return 0;
    }
    else if(flag==-1) cout<<-1;
    else cout<<d[n];
    return 0;
}
