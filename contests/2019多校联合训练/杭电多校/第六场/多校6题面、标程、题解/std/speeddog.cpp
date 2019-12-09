#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=250010,M=524305;
int Case,n,m,_,i,x,y,pos[N];ll sa[M],sb[M],la[M],lb[M],alla;
struct E{int x,y;}e[N];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
struct Num{
  ll u,d;
  Num(){}Num(ll _u,ll _d){u=_u,d=_d;}
  void write(){
    ll z=gcd(u,d);
    printf("%lld/%lld\n",u/z,d/z);
  }
}q[N];
inline int cmp(const Num&a,const Num&b){
  ll t=a.u*b.d-b.u*a.d;
  if(t<0)return -1;
  return t?1:0;
}
inline bool cmpn(const Num&a,const Num&b){return cmp(a,b)<0;}
inline int lower(int A,int B){
  Num x(A,B);
  int l=1,r=m,mid,t;
  while(1){
    mid=(l+r)>>1;
    t=cmp(x,q[mid]);
    if(!t)return mid;
    if(t<0)r=mid-1;else l=mid+1;
  }
}
void build(int x,int a,int b){
  sa[x]=sb[x]=la[x]=lb[x]=0;
  if(a==b){pos[a]=x;return;}
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void modify(int A,int B){
  int x=pos[lower(B,A+B)];
  alla+=A;
  sa[x]+=A;
  sb[x]+=B;
  la[x]+=A;
  lb[x]+=B;
  for(x>>=1;x;x>>=1){
    sa[x]+=A;
    sb[x]+=B;
    la[x]=la[x<<1];
    lb[x]=lb[x<<1];
  }
}
inline void query(){
  int x=1,a=1,b=m,mid;
  ll prea=0,preb=0;
  Num f,g;
  while(a<b){
    mid=(a+b)>>1;
    x<<=1;
    f=Num((alla-(prea+sa[x])-(preb+sb[x]))*q[mid].u+(preb+sb[x])*q[mid].d,q[mid].d);
    g=Num((alla-(prea+sa[x]+la[x+1])-(preb+sb[x]+lb[x+1]))*q[mid+1].u+(preb+sb[x]+lb[x+1])*q[mid+1].d,q[mid+1].d);
    if(cmp(f,g)<0){
      prea+=sa[x];
      preb+=sb[x];
      x++;
      a=mid+1;
    }else b=mid;
  }
  prea+=sa[x];
  preb+=sb[x];
  f=Num((alla-prea-preb)*q[a].u+preb*q[a].d,q[a].d);
  f.write();
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    q[1]=Num(0,1);
    q[m=2]=Num(1,1);
    for(i=1;i<=n;i++){
      scanf("%d%d",&x,&y);
      e[i].x=x;
      e[i].y=y;
      q[++m]=Num(y,x+y);
    }
    sort(q+1,q+m+1,cmpn);
    for(_=0,i=1;i<=m;i++)if(i==1||cmp(q[i],q[_]))q[++_]=q[i];
    m=_;
    build(1,1,m);
    alla=0;
    for(i=1;i<=n;i++)modify(e[i].x,e[i].y),query();
  }
}