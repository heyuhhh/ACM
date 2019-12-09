#include<cstdio>
typedef long long ll;
const ll inf=1000000000000000010LL;
const int N=50010,M=20,K=17,P=1000000007;
int Case,n,m,q,i,j,k,p[N];ll _;
char a[N];
int g[M][10];
bool can[N][10];
ll f[N][M],st[K][N][M],en[K][N][M];
char go[K][N][M];
int val[K][N][M];
inline ll fix(ll x){return x<inf?x:inf;}
inline int query(ll k){
  if(k>f[1][0])return -1;
  int x=1,y=0,ret=0,i;
  while(x<=n){
    for(i=K-1;~i;i--)if(x+(1<<i)<=n+1&&st[i][x][y]<k&&k<=en[i][x][y]){
      ret=(1LL*ret*p[1<<i]+val[i][x][y])%P;
      k-=st[i][x][y];
      y=go[i][x][y];
      x+=1<<i;
    }
    if(x>n)break;
    for(i=0;i<10;i++)if(can[x][i]){
      ll tmp=f[x+1][g[y][i]];
      if(k>tmp)k-=tmp;
      else{
        ret=(10LL*ret+i)%P;
        x++;
        y=g[y][i];
        break;
      }
    }
  }
  return ret;
}
int main(){
  for(p[0]=i=1;i<N;i++)p[i]=10LL*p[i-1]%P;
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d%d%s",&n,&m,&q,a+1);
    for(i=0;i<m;i++)for(j=0;j<10;j++)g[i][j]=(i*10+j)%m;
    for(i=1;i<=n;i++){
      if(a[i]=='?')for(j=0;j<10;j++)can[i][j]=1;
      else{
        for(j=0;j<10;j++)can[i][j]=0;
        can[i][a[i]-'0']=1;
      }
    }
    for(j=0;j<m;j++)f[n+1][j]=j==0;
    for(i=n;i;i--)for(j=0;j<m;j++){
      ll tmp=0;
      int nxt=-1;
      ll sz=-1;
      for(k=0;k<10;k++)if(can[i][k]){
        ll now=f[i+1][g[j][k]];
        tmp=fix(tmp+now);
        if(now>sz)nxt=k,sz=now;
      }
      f[i][j]=tmp;
      go[0][i][j]=g[j][nxt];
      val[0][i][j]=nxt;
      ll sum=0;
      for(k=0;k<nxt;k++)if(can[i][k])sum=fix(sum+f[i+1][g[j][k]]);
      st[0][i][j]=sum;
      en[0][i][j]=fix(sum+f[i+1][g[j][nxt]]);
    }
    for(k=1;k<K;k++)for(i=1;i+(1<<k)<=n+1;i++)for(j=0;j<m;j++){
      int x=go[k-1][i][j],len=1<<(k-1);
      go[k][i][j]=go[k-1][i+len][x];
      val[k][i][j]=(1LL*val[k-1][i][j]*p[len]+val[k-1][i+len][x])%P;
      st[k][i][j]=fix(st[k-1][i][j]+st[k-1][i+len][x]);
      en[k][i][j]=fix(st[k-1][i][j]+en[k-1][i+len][x]);
    }
    while(q--)scanf("%lld",&_),printf("%d\n",query(_));
  }
}