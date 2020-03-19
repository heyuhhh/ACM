#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 105;
int t,n,m;
int num[N][N],d[N][N];
char mp[N][N];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct Edge{
    int u,v,w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N*N<<1];
struct node{
    int x,y;
};
int f[N*N];
int tot,cnt;
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
int Kruskal(){
    int ans=0;
    for(int i=0;i<=105;i++) f[i]=i;
    for(int i=1;i<=tot;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx==fy) continue ;
        f[fx]=fy;
        ans+=e[i].w;
    }
    return ans ;
}
bool ok(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m && mp[x][y]!='#';
}
void bfs(int sx,int sy){
    queue <node> q;
    memset(d,INF,sizeof(d));d[sx][sy]=0;
    node now;
    now.x=sx;now.y=sy;
    q.push(now);
    while(!q.empty()){
        node cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=cur.x+dx[i],y=cur.y+dy[i];
            if(!ok(x,y)||d[x][y]<=d[cur.x][cur.y]+1) continue ;
            d[x][y]=d[cur.x][cur.y]+1;
            now.x=x;now.y=y;
            q.push(now);
            if(mp[x][y]=='A'||mp[x][y]=='S'){
                e[++tot].u=num[sx][sy];e[tot].v=num[x][y];e[tot].w=d[x][y];
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d%d",&m,&n);
        tot = cnt = 0;
        char c;
        while(1){
            scanf("%c",&c);
            if(c!=' ') break ;
        }
        int first=1;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            getchar();
            first=0;
            for(int j=1;j<=m;j++){
                scanf("%c",&mp[i][j]);
                if(mp[i][j]=='S'||mp[i][j]=='A') num[i][j]=++cnt;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(num[i][j]) bfs(i,j);
            }
        }
        sort(e+1,e+tot+1);
        int ans = Kruskal();
        cout<<ans<<endl;
    }
    return 0;
}
