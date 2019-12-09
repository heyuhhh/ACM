#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2010,M=4100;
int Case,n,m,i,j,k,cb,b[N],pos[N];ll pre[M],suf[M],s[M],v[M],ans;
struct E{int x,y,z;}e[N];
inline bool cmp(const E&a,const E&b){return a.x<b.x;}
void build(int x,int a,int b){
  pre[x]=suf[x]=s[x]=v[x]=0;
  if(a==b){
    pos[a]=x;
    return;
  }
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void change(int x,int p){
  x=pos[x];
  s[x]+=p;
  if(s[x]>0)pre[x]=suf[x]=v[x]=s[x];else pre[x]=suf[x]=v[x]=0;
  for(x>>=1;x;x>>=1){
    pre[x]=max(pre[x<<1],s[x<<1]+pre[x<<1|1]);
    suf[x]=max(suf[x<<1|1],s[x<<1|1]+suf[x<<1]);
    s[x]=s[x<<1]+s[x<<1|1];
    v[x]=max(max(v[x<<1],v[x<<1|1]),suf[x<<1]+pre[x<<1|1]);
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(cb=0,i=1;i<=n;i++){
      scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
      b[++cb]=e[i].y;
    }
    sort(b+1,b+cb+1);
    for(m=0,i=1;i<=cb;i++)if(i==1||b[i]!=b[m])b[++m]=b[i];
    sort(e+1,e+n+1,cmp);
    ans=0;
    for(i=1;i<=n;i++)e[i].y=lower_bound(b+1,b+m+1,e[i].y)-b;
    for(i=1;i<=n;i++)if(i==1||e[i].x!=e[i-1].x){
      build(1,1,m);
      for(j=i;j<=n;j=k){
        for(k=j;k<=n&&e[j].x==e[k].x;k++)change(e[k].y,e[k].z);
        if(ans<v[1])ans=v[1];
      }
    }
    printf("%lld\n",ans);
  }
}