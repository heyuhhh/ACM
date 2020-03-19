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
struct node{
    int x,y;
}p[N];
int t,n,tot;
int a[N];
double dis(int x,int y){
    return sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
struct Edge{
    int u,v;double w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N*N];
int f[N],mp[N][N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
double Kruskal(){
    double ans=0;
    for(int i=0;i<=n+1;i++) f[i]=i;
    for(int i=1;i<=tot;i++){
        int u=e[i].u,v=e[i].v;
        int fx=find(u),fy=find(v);
        if(fx==fy) continue ;
        f[fx]=fy;
        mp[u][v]=mp[v][u]=1;
        ans+=e[i].w;
    }
    return ans ;
}
double d[N][N];
int check[N];
void dfs(int u,int fa){
    for(int i=1;i<=n;i++){
        if(check[i]) d[i][u]=d[u][i]=max(d[i][fa],dis(fa,u));
    }
    check[u]=1;
    for(int i=1;i<=n;i++){
        if(mp[i][u] && i!=fa) dfs(i,u);
    }
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d%d%d",&x,&y,&a[i]);
            p[i]=node{x,y};
        }
        tot = 0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                e[++tot]=Edge{i,j,dis(i,j)};
        memset(mp,0,sizeof(mp));
        sort(e+1,e+tot+1);
        double sum=Kruskal();
        memset(d,0,sizeof(d));
        memset(check,0,sizeof(check));
        dfs(1,-1);
        double ans = 0;
        for(int i=1;i<=tot;i++){
            int u=e[i].u,v=e[i].v;
            double w=e[i].w;
            ans=max(ans,(a[u]+a[v])/(sum-d[u][v]));
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
