#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=100010,M=310,inf=3000000,MO=(1<<19)-1;
unsigned int wx[inf],wy[inf],wz[inf];
int Case,n,m,lim,K,i,ans[M];
struct E{int x,y,z,r;}e[N];
inline bool cmp(const E&a,const E&b){return a.r>b.r;}
inline ll sqr(ll x){return x*x;}
inline bool check(const E&a,const E&b){return sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z)<=sqr(a.r+b.r+lim*2);}
inline int dis(const E&a,const E&b){
  ll tmp=sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z);
  int l=0,r=inf,mid,ret;
  while(l<=r){
    mid=(l+r)>>1;
    if(tmp<=sqr(a.r+b.r+mid*2))r=(ret=mid)-1;else l=mid+1;
  }
  return ret;
}
struct EV{ull v;int w;EV*nxt;}*g[MO+7],pool[N],*cur,*p;
int pos[N],at[N],cnt,d[N],en[N],id[N],last[MO+7],CUR;
inline int ins(int A,int B,int C){
  int u=(wx[A]^wy[B]^wy[C])&MO;
  ull v=(((ull)A)<<42)|(((ull)B)<<21)|C;
  if(last[u]<CUR)last[u]=CUR,g[u]=NULL;
  for(p=g[u];p;p=p->nxt)if(p->v==v)return p->w;
  cnt++;
  d[cnt]=0;
  p=cur++;
  p->v=v;
  p->w=cnt;
  p->nxt=g[u];
  g[u]=p;
  return cnt;
}
inline int ask(int A,int B,int C){
  int u=(wx[A]^wy[B]^wy[C])&MO;
  ull v=(((ull)A)<<42)|(((ull)B)<<21)|C;
  if(last[u]<CUR)return 0;
  for(p=g[u];p;p=p->nxt)if(p->v==v)return p->w;
  return 0;
}
inline void build(int st,int pre){
  cnt=0;
  cur=pool;
  CUR++;
  for(int i=st;i<=n;i++){
    pos[i]=ins(e[i].x/pre,e[i].y/pre,e[i].z/pre);
    d[pos[i]]++;
  }
  for(int i=1;i<=cnt;i++)d[i]+=d[i-1];
  for(int i=1;i<=cnt;i++)en[i]=d[i];
  for(int i=st;i<=n;i++)id[d[pos[i]]--]=i;
}
inline int cal(int _lim,int mode=0){
  int pre=~0U>>1;
  lim=_lim;
  m=0;
  for(int i=1;i<=n;i++){
    int now=(e[i].r+lim)*2;
    if(now*2<pre&&i<n)build(i+1,pre=now);
    int A=e[i].x/pre,B=e[i].y/pre,C=e[i].z/pre;
    for(int x=A-1;x<=A+1;x++)if(x>=0)
      for(int y=B-1;y<=B+1;y++)if(y>=0)
        for(int z=C-1;z<=C+1;z++)if(z>=0){
          int o=ask(x,y,z);
          if(!o)continue;
          for(int j=en[o-1]+1;j<=en[o];j++){
            int k=id[j];
            if(k<=i)break;
            if(check(e[i],e[k])){
              m++;
              if(mode)ans[m]=dis(e[i],e[k]);
              if(m>=K)return m;
            }
          }
        }
  }
  return m;
}
int main(){
  for(wx[0]=324673,i=1;i<inf;i++)wx[i]=wx[i-1]*233+17;
  for(wy[0]=812376,i=1;i<inf;i++)wy[i]=wy[i-1]*13331+97;
  for(wz[0]=921375,i=1;i<inf;i++)wz[i]=wz[i-1]*10007+53;
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
      scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].z,&e[i].r);
      e[i].x<<=1;
      e[i].y<<=1;
      e[i].z<<=1;
      e[i].r<<=1;
    }
    sort(e+1,e+n+1,cmp);
    int l=0,r=inf,mid,fin;
    while(l<=r){
      mid=(l+r)>>1;
      if(cal(mid)<K)l=mid+1;else r=(fin=mid)-1;
    }
    for(i=1;i<=K;i++)ans[i]=fin;
    if(fin)cal(fin-1,1);
    sort(ans+1,ans+K+1);
    for(i=1;i<=K;i++)printf("%d\n",ans[i]);
  }
}