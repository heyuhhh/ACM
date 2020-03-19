#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define mp make_pair
#define INF 1e9
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 505;
int n,k,T;
int head[N],vis[N],d[N],a[N],pa[N],pre[N];
struct Edge{
    int v,next,c,w;
}e[N*N];
int tot ;
void adde(int u,int v,int c,int w){
    e[tot].v=v;e[tot].next=head[u];e[tot].w=w;e[tot].c=c;head[u]=tot++;
    e[tot].v=v;e[tot].next=head[v];e[tot].w=-w;e[tot].c=0;head[v]=tot++;
}
int spfa(int s,int t,int &flow,int &cost){
    for(int i=0;i<=t+1;i++) d[i]=a[i]=INF;d[s]=0;
    memset(vis,0,sizeof(vis));vis[s]=1;
    memset(pre,-1,sizeof(pre));memset(pa,-1,sizeof(pa));
    queue <int> q;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 && d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                pa[v]=u;pre[v]=i;
                a[v]=min(a[v],e[i].c);
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(d[t]==INF) return 0;
    flow+=a[t];
    cost+=a[t]*d[t];
    for(int i=t;i!=-1;i=pa[i]){
        int edge = pre[i];
        e[edge].c-=a[t];
        e[edge^1].c+=a[t];
    }
    return 1;
}
int Min_cost(int s,int t){
    int flow=0,cost=0;
    while(spfa(s,t,flow,cost));
    return cost;
}
int main(){
    cin>>T;
    while(T--){
        tot=0;memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&k);
        vector <int> x;
        vector <pair<pii,int> > g[205];
        for(int i=1;i<=n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            x.push_back(u);
            x.push_back(v);
            g[i].push_back(mp(mp(u,v),w));
        }
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        int len = x.size();
        for(int i=0;i<len-1;i++) adde(i,i+1,k,0);
        for(int i=1;i<=n;i++){
            int u=g[i].first.first,v=g[i].first.second,w=g[i].second;
            int p1 = lower_bound(x.begin(),x.end(),u)-x.begin();
            int p2 = lower_bound(x.begin(),x.end(),v)-x.begin();
            adde(p1,p2,1,-w);
        }
        printf("%d\n",Min_cost(0,len-1));
    }
    return 0;
}

