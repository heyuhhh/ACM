#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 99999999
using namespace std;
typedef long long ll;
const int N = 2000, M = 50000;
int n,m,cnt,tot,t;
int peo[N],head[N],d[N];

struct Edge{
    int v,next,c;
}e[M];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
int bfs(){
    memset(d,0,sizeof(d));d[0]=1;
    queue <int > q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 && !d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int s,int a){
    if(s==t || a==0) return a;
    int flow=0,f;
    for(int i=head[s];i!=-1;i=e[i].next){
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
    int flow=0;
    while(bfs()) flow+=dfs(0,INF);
    return flow;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        cnt=tot=0;memset(head,-1,sizeof(head));
        memset(peo,0,sizeof(peo));
        for(int i=1;i<=n;i++){
            int x = 0;
            for(int j=1,op;j<=m;j++){
                x<<=1;
                scanf("%d",&op);
                x+=op;
            }
            if(!peo[x]) cnt++;
            peo[x]++;
        }
        t=cnt+m+1;
        for(int i=1;i<=m;i++){
            int c;
            scanf("%d",&c);
            adde(cnt+i,t,c);
        }
        int p=0;
        for(int i=0;i<(1<<m);i++){
            if(!peo[i]) continue ;
            p++;
            adde(0,p,peo[i]);
            for(int j=0;j<m;j++)
                if(i&(1<<j)) adde(p,m-j+cnt,peo[i]);
        }
        int ans = Dinic();
        if(ans==n) puts("YES");
        else puts("NO");
    }
    return 0;
}

