#include<cstdio>
const int N=2010,K=2010,P=1000000007;
int Case,n,m,cnt,val[K],i,x,y,a[N],ans;
int g[N],nxt[N<<1],v[N<<1],ok[N<<1],ed,son[N],f[N],all,now;
int dp[N][K],tmp[K];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];ok[ed]=1;g[x]=ed;}
void findroot(int x,int y){
  son[x]=1;f[x]=0;
  for(int i=g[x];i;i=nxt[i])if(ok[i]&&v[i]!=y){
    findroot(v[i],x);
    son[x]+=son[v[i]];
    if(son[v[i]]>f[x])f[x]=son[v[i]];
  }
  if(all-son[x]>f[x])f[x]=all-son[x];
  if(f[x]<f[now])now=x;
}
void dfs(int x,int y){
  int i,j,k=a[x];
  for(i=1;i<=cnt;i++)tmp[i]=0;
  for(i=j=1;i<=cnt;i++){
    int t=val[i]/k;
    if(!t)continue;
    while(val[j]>t)j++;
    up(tmp[j],dp[x][i]);
  }
  for(i=1;i<=cnt;i++)dp[x][i]=tmp[i];
  for(i=g[x];i;i=nxt[i])if(ok[i]){
    int u=v[i];
    if(u==y)continue;
    for(j=1;j<=cnt;j++)dp[u][j]=dp[x][j];
    dfs(u,x);
    for(j=1;j<=cnt;j++)up(dp[x][j],dp[u][j]);
  }
}
void solve(int x){
  int i;
  for(i=1;i<=cnt;i++)dp[x][i]=0;
  dp[x][1]=1;
  dfs(x,0);
  for(i=1;i<=cnt;i++)up(ans,dp[x][i]);
  for(i=g[x];i;i=nxt[i])if(ok[i]){
    ok[i^1]=0;
    f[0]=all=son[v[i]];
    findroot(v[i],now=0);
    solve(now);
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    cnt=ans=0;
    for(i=1;i<=n;i++)g[i]=son[i]=f[i]=0;
    for(i=1;i<=m;i=m/(m/i)+1)val[++cnt]=m/i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(ed=i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    f[0]=all=n;findroot(1,now=0);solve(now);
    printf("%d\n",ans);
  }
}