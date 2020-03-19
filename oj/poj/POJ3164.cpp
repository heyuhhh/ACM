#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 105,M = 1e4+5;
int n,m;
struct Point{
    int x,y;
}p[N];
double dis(int x,int y){
    return sqrt((double)(p[x].x-p[y].x)*(p[x].x-p[y].x)+(double)(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
struct Edge{
    int u,v;
    double w;
}e[M];
int pre[N]; //记录前驱.
int id[N],vis[N];
double in[N];
double dirMst(int root){
    double ans=0;
    while(1){
        for(int i=0;i<=n;i++) in[i]=INF;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v;
            double w=e[i].w;
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
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[i].u=u-1;e[i].v=v-1;e[i].w=dis(u,v);
        }
        double ans = dirMst(0);
        if(ans==-1) puts("poor snoopy");
        else printf("%.2f\n",ans);
    }
    return 0;
}
