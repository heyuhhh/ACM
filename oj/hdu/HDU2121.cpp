#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#define INF 1e17
using namespace std;
typedef long long ll;
int n,m,t;
const int N = 1010,M = 10005;
struct Edge{
    int u,v,w;
}e[M<<1];
int pre[N]; //记录前驱
int Rt;
ll id[N],vis[N],in[N];
ll dirMst(int root){
    ll ans=0;
    while(1){
        for(int i=0;i<=n;i++) in[i]=INF;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(w<in[v] && v!=u){
                pre[v]=u;
                in[v]=w;
                if(u==root) Rt=i;
            }
        }           //求最小入边集
        in[root]=0;
        pre[root]=root;
        for(int i=0;i<n;i++){
            if(in[i]==INF) return -1;
            ans+=in[i];
        }
        int idx = 0; //新标号
        for(int i=0;i<n;i++){
            if(vis[i] == -1 ){
                int u = i;
                while(vis[u] == -1){
                    vis[u] = i;
                    u = pre[u];
                }
                if(vis[u]!=i || u==root) continue;     //判断是否形成环
                for(int v=pre[u];v!=u;v=pre[v] )
                    id[v]=idx;
                id[u] = idx++;
            }
        }
        if(idx==0) break;
        for(int i=0;i<n;i++){
            if(id[i]==-1) id[i]=idx++;
        }
        for(int i=1;i<=m;i++){
            e[i].w-=in[e[i].v];
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
        }
        n = idx;
        root = id[root];//给根新的标号
    }
    return ans;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        ll sum = 0;
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            e[i]=Edge{u,v,w};
            sum+=w;
        }
        sum++;
        for(int i=0;i<n;i++){
            e[i+m+1]=Edge{n,i,sum};
        }
        ll tmp=m;
        m+=n;n++;
        ll ans = dirMst(n-1);
        if(ans>2*sum) printf("impossible\n\n");
        else printf("%lld %lld\n\n",ans-sum,Rt-tmp-1ll);
    }
}
