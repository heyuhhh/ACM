#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define s 0
#define t 2*n+1
#define INF 1e9
using namespace std;
typedef long long ll;
const int N = 505, M = 1505;
int n,m,tot,need;
int lim[N],has[N],head[N],d[N];
ll mp[N][N];
struct Edge{
    int v,next,c;
}e[(N*N)<<1];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
bool bfs(int S,int T){
    memset(d,0,sizeof(d));d[S]=1;
    queue <int > q;q.push(S);
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
    return d[T]!=0;
}
int dfs(int S,int a){
    int flow=0,f;
    if(S==t || a==0) return a;
    for(int i=head[S];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[S]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[S]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(0,t)) max_flow+=dfs(0,INF);
    return max_flow;
}
bool check(ll x){
    memset(head,-1,sizeof(head));tot=0;
    for(int i=1;i<=n;i++) adde(s,i,has[i]);
    for(int i=n+1;i<=2*n;i++) adde(i,t,lim[i-n]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(mp[i][j]<=x) adde(i,j+n,INF);
    int flow = Dinic();
    for(int i=head[s];i!=-1;i=e[i].next){
        int now = e[i].c;
        if(now>0) return false;
    }
    return true ;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&has[i],&lim[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=i==j ? 0 : 1e18;
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        scanf("%d%d%I64d",&u,&v,&w);
        ll tmp = mp[u][v];
        mp[u][v]=mp[v][u]=min(tmp,w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(mp[i][j]>mp[i][k]+mp[k][j] && mp[i][k]!=1e18 && mp[k][j]!=1e18)
                    mp[i][j]=mp[i][k]+mp[k][j];
    ll l = 0,r = 1e18,mid;
    while(l<r){
        mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(r==1e18) cout<<-1;
    else cout<<l<<endl;
    return 0;
}

