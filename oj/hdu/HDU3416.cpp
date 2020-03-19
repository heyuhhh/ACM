#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define INF 1e9
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,int> pii;
const int N = 1005,M = 100005;
int T;
int n,m,s,t,tot,mx;
int head[N],d[N],pre[N],p[N],a[N],vis[N];
pii E[M];
struct Edge{
    int v,next,c,w;
}e[M<<1];
void adde(int u,int v,int c,int w){
    e[tot].v=v;e[tot].w=w;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].w=-w;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}

void min_cost(int &flow,int &cost,int F){
    while(F){
        for(int i=0;i<=n;i++) d[i]=INF,a[i]=INF;d[s]=0;
        memset(pre,-1,sizeof(pre));memset(p,-1,sizeof(p));
        memset(vis,0,sizeof(vis));
        queue <int> q;q.push(s);vis[s]=1;
        while(!q.empty()){
            int u=q.front();q.pop();vis[u]=0;
            for(int i=head[u];i+1;i=e[i].next){
                int v=e[i].v;
                if(e[i].c>0 && d[v]>d[u]+e[i].w){
                    d[v]=d[u]+e[i].w;
                    p[v]=u;pre[v]=i;
                    a[v]=min(a[u],e[i].c);
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        if(a[t]==INF) break;
        int f=min(a[t],F);
        cost+=f*d[t];
        flow+=f;
        F-=f;
        for(int i=t;i+1;i=p[i]){
            int edge = pre[i];
            e[edge].c-=f;
            e[edge^1].c+=f;
        }
    }
    return ;
}
void Build(){
    tot=0;memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u=E[i].first.first,v=E[i].first.second,t=E[i].second;
        adde(u,v,1,t);
    }
}
int check(int mid){
    Build();
    int flow = 0,cost = 0;
    min_cost(flow,cost,mid);
    if(cost==mx*flow && mid==flow) return 1;
    return 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            if(u==v) continue ;
            E[i]=mp(mp(u,v),t);
        }
        scanf("%d%d",&s,&t);
        Build();
        int cost =0 ,flow = 0;
        min_cost(flow,cost,1);
        mx = cost;
        if(mx==0){
            puts("0");
            continue ;
        }
        int l=1,r=n;
        while(l<r){
            int mid = (l+r)>>1;
            if(check(mid)) l=mid+1;
            else r=mid;
        }
        printf("%d\n",l-1);
    }
    return 0;
}

