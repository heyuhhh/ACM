#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define INF 1e9
#define t 300
using namespace std;
typedef long long ll;
const int N = 305;
int T,cnt;
int n,m,F,tot;
int head[N],f[N],map[N],d[N];
vector <int > g[N];
vector <int > vec[N];
set <int > S[N];
struct Edge{
    int v,next,c;
}e[(N*N)<<1];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
int find(int x){
    return f[x]==x ? f[x] : f[x]=find(f[x]);
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
    while(bfs())
        flow+=dfs(0,INF);
    return flow;
}
int check(int mid){
    memset(head,-1,sizeof(head));tot=0;
    for(int i=1;i<=cnt;i++) for(auto v:vec[i]) for(auto k:S[i]) adde(v,n+k,1);
    for(int i=1;i<=n;i++) adde(0,i,mid);
    for(int i=n+1;i<=n+n;i++) adde(i,t,mid);
    int max_flow=Dinic();
    if(max_flow==mid*n) return 1;
    return 0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(g,0,sizeof(g));memset(map,0,sizeof(map));
        scanf("%d%d%d",&n,&m,&F);
        for(int i=0;i<=t;i++) f[i]=i,g[i].clear(),vec[i].clear(),S[i].clear();
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        for(int i=1,x,y;i<=F;i++){
            scanf("%d%d",&x,&y);
            int fx=find(x),fy=find(y);
            if(fx!=fy) f[fx]=fy;
        }
        cnt=0 ;
        for(int i=1;i<=n;i++){
            int fx=find(i);
            if(fx==i){
                vec[++cnt].push_back(i);
                map[fx]=cnt;
            }
        }
        for(int i=1;i<=n;i++)
            if(f[i]!=i) vec[map[f[i]]].push_back(i);
        for(int i=1;i<=cnt;i++){
            for(auto v:vec[i]){
                for(auto tmp:g[v]) S[i].insert(tmp);
            }
        }
        int l=0,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) l=mid+1;
            else r=mid;
        }
        printf("%d\n",l-1);
    }
    return 0;
}

