#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 1e9
using namespace std;
typedef long long ll;
const int N = 505;
int n,m,tot;
int E[N][N];
int head[N],vis[N],d[N],pa[N],cnt[N],sum[N];
struct Edge{
    int u,v,next,w;
}e[(N*N)<<3];
struct Node{
    int x,y,w,c;
}p1[N],p2[N];
void adde(int u,int v,int w){
    e[tot].w=w;e[tot].v=v;e[tot].u=u;e[tot].next=head[u];head[u]=tot++;
}
int dis(int a,int b){
    return abs(p1[a].x-p2[b].x)+abs(p1[a].y-p2[b].y)+1;
}
int spfa(){
    for(int i=0;i<=n+m+1;i++) d[i]=1e9;d[0]=0;
    queue<int> q;q.push(0);memset(vis,0,sizeof(vis));vis[0]=1;
    memset(pa,-1,sizeof(pa));
    memset(cnt,0,sizeof(cnt));cnt[0]++;
    while(!q.empty()){
        int u =q.front();q.pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                pa[v]=u;
                if(!vis[v]){
                    vis[v]=1;
                    if(++cnt[v]>n+m+2) return v;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(head,-1,sizeof(head));tot=0;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&p1[i].x,&p1[i].y,&p1[i].w);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&p2[i].x,&p2[i].y,&p2[i].w);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int tmp;scanf("%d",&tmp);
                E[i][j]=tmp;
                sum[j]+=tmp;
                adde(i,j+n,dis(i,j));
                if(E[i][j]) adde(j+n,i,-dis(i,j));
            }
        }
        for(int i=1;i<=n;i++) adde(0,i,0);
        for(int i=1;i<=m;i++){
            if(p2[i].w>0 && sum[i]==0) adde(i+n,n+m+1,0);
            else if(sum[i]>0&&p2[i].w>sum[i]) adde(n+m+1,i+n,0),adde(i+n,n+m+1,0);
            else if(p2[i].w==sum[i]) adde(n+m+1,i+n,0);
        }
        int s = spfa();
        if(s==-1) cout<<"OPTIMAL";
        else{
            cout<<"SUBOPTIMAL"<<endl;
            memset(vis,0,sizeof(vis));
            int tmp=s;
            while(true){       //找到在负环中的点，当前求出来的点不一定在负环中
                if(!vis[tmp]){
                    vis[tmp]=1;tmp=pa[tmp];
                }else{
                    s=tmp;
                    break ;
                }
            }
            do{
                int u=pa[s];
                if(u<=n && s>n) E[u][s-n]++;
                if(u>n && s<=n) E[s][u-n]--;
                s=u;
            }while(s!=tmp);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<E[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

