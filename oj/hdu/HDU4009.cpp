#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1005;
int n,x,y,z,tot;
struct Point{
    int x,y,z;
}p[N];
int dis(int a,int b){
    return abs(p[a].x-p[b].x)+abs(p[a].y-p[b].y)+abs(p[a].z-p[b].z);
}
struct Edge{
    int u,v,w;
}e[N*N];
int pre[N]; //记录前驱.
int id[N],vis[N],in[N];
int dirMst(int root){
    int ans=0;
    while(1){
        memset(in,INF,sizeof(in));
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=tot;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(w<in[v] && v!=u){
                pre[v]=u;
                in[v]=w;
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
        for(int i=1;i<=tot;i++){
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
    while(scanf("%d%d%d%d",&n,&x,&y,&z)!=EOF){
        if(n+x+y+z<=0) break ;
        tot=0;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                int id;
                scanf("%d",&id);
                e[++tot].u=i;e[tot].v=id;
                if(p[i].z>=p[id].z) e[tot].w=dis(i,id)*y;
                else e[tot].w=dis(i,id)*y+z;
            }
        }
        for(int i=1;i<=n;i++){
            e[++tot].u=0;e[tot].v=i;e[tot].w=p[i].z*x;
        }
        n++;
        int ans = dirMst(0);
        cout<<ans<<endl;
    }
    return 0;
}
