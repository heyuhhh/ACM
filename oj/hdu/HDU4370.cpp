#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 305;
int n,tot,mn;;
int vis[N],head[N],c[N][N],d[N];
struct Edge{
    int v,w,next;
}e[N*N<<1];
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
void spfa(int s){
    memset(vis,0,sizeof(vis));
    queue<int> q;q.push(s);vis[s]=1;
    memset(d,INF,sizeof(d));d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
            if(v==s){
                mn=min(mn,d[u]+e[i].w);
            }
        }
    }
    return ;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&c[i][j]);
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue ;
                adde(i,j,c[i][j]);
            }
        }
        mn=INF;
        spfa(1);
        int tmp=mn,ans=INF;
        mn=INF;
        ans=d[n];
        spfa(n);
        ans=min(ans,mn+tmp);
        cout<<ans<<endl;
    }
    return 0;
}
