#include<cstdio>
const int N=85,M=100000,inf=~0U>>1;
int Case,n,cnt,m,goal,have,num[N],lim[N],i,j;
int S,T,x,y,g[N],v[N<<1],nxt[N<<1],ed,vis[N];
int cost[N],col[N],use[N],ans;
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x){
  if(vis[x])return;
  vis[x]=1;
  for(int i=g[x];i;i=nxt[i])if(use[i>>1])dfs(v[i]);
}
inline bool check(){
  int i;
  for(i=0;i<=n;i++)vis[i]=0;
  dfs(0);
  for(i=0;i<=n;i++)if(!vis[i])return 0;
  return 1;
}
inline bool check2(){
  for(int i=1;i<=cnt;i++)if(num[i]<lim[i])return 0;
  return 1;
}
namespace Matroid{
int g[N],v[M],nxt[M],ed,q[M],h,t,d[N],pre[N],w[N];bool in[N];
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
inline void ext(int x,int y,int z){
  if(d[x]<=y)return;
  d[x]=y;
  pre[x]=z;
  if(in[x])return;
  q[++t]=x;
  in[x]=1;
}
inline bool find(){
  int i,j;
  S=m+1,T=m+2;
  for(ed=0,i=1;i<=T;i++)g[i]=0;
  for(i=1;i<=m;i++)if(use[i]){
    w[i]=-cost[i];
    use[i]^=1;
    num[col[i]]--;
    if(check())add(S,i);
    if(check2())add(i,T);
    num[col[i]]++;
    use[i]^=1;
  }else w[i]=cost[i];
  for(i=1;i<=m;i++)if(use[i])for(j=1;j<=m;j++)if(!use[j]){
    use[i]^=1,use[j]^=1;
    num[col[i]]--;num[col[j]]++;
    if(check())add(j,i);
    if(check2())add(i,j);
    num[col[i]]++;num[col[j]]--;
    use[i]^=1,use[j]^=1;
  }
  for(i=1;i<=T;i++)d[i]=inf,in[i]=0;
  q[h=t=1]=S;
  d[S]=0,in[S]=1;
  while(h<=t){
    x=q[h++];
    for(i=g[x];i;i=nxt[i])ext(v[i],d[x]+w[v[i]],x);
    in[x]=0;
  }
  if(d[T]==inf)return 0;
  ans+=d[T];
  while(pre[T]!=S){
    T=pre[T];
    if(use[T])num[col[T]]--;else num[col[T]]++;
    use[T]^=1;
  }
  return 1;
}
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&cnt);
    m=goal=ans=0;
    for(i=0;i<=n;i++)g[i]=0;
    for(ed=i=1;i<=cnt;i++){
      scanf("%d%d",&num[i],&lim[i]);
      goal+=lim[i];
      for(j=0;j<num[i];j++){
        m++;
        col[m]=i;
        scanf("%d%d%d",&x,&y,&cost[m]);
        add(x-1,y);
        add(y,x-1);
        use[m]=1;
        ans+=cost[m];
      }
    }
    if(!check()){
      puts("-1");
      continue;
    }
    have=m;
    while(have>goal){
      if(!Matroid::find())break;
      have--;
    }
    if(have!=goal)ans=-1;
    printf("%d\n",ans);
  }
}