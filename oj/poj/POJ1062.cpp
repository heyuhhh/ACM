#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 105,t = 101;
int m,n;
vector <int> vec[N],pri[N];
int l[N],head[N],vis[N];
struct Edge{
    int u,v,w,next;
}e[N*N<<1];
int tot;
void adde(int u,int v,int w){
    e[tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
int ans=INF;
void dfs(int u,int mx,int mn,int sum){
    vis[u]=1;
    if(u==t){
        ans=min(ans,sum);
        return ;
    }
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(vis[v]) continue ;
        if((abs(l[v]-mn)>m || abs(l[v]-mx)>m) &&v!=t) continue ;
        dfs(v,max(l[v],mx),min(l[v],mn),sum+e[i].w);
        vis[v]=0;
    }
}
int main(){
    scanf("%d%d",&m,&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        int p,x;
        scanf("%d%d%d",&p,&l[i],&x);
        adde(i,t,p);
        for(int j=1,tmp;j<=x;j++){
            scanf("%d%d",&tmp,&p);
            adde(i,tmp,p);
        }
    }
    dfs(1,l[1],l[1],0);
    cout<<ans;
    return 0;
}
