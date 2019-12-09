#include<cstdio>
#include<algorithm>
using namespace std;
const int N=15,K=60;
int Case,n,m,x,y,i,j,ca,cb,a[N],b[N];long long ans;
struct E{int x,y,k,t;}e[N];
inline int abs(int x){return x>0?x:-x;}
inline bool check(int x,int y){
  for(int i=0;i<n;i++)if((abs(x-e[i].x)+abs(y-e[i].y))%e[i].k!=e[i].t)return 0;
  return 1;
}
inline int cal(int l,int r){
  r-=l+1;
  if(r<0)return 0;
  return r/K+1;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    a[ca=1]=b[cb=1]=m+1;
    for(i=0;i<n;i++){
      scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].k,&e[i].t);
      a[++ca]=e[i].x;
      b[++cb]=e[i].y;
    }
    sort(a+1,a+ca+1);
    sort(b+1,b+cb+1);
    ans=0;
    for(i=0;i<ca;i++)if(a[i]<a[i+1])for(j=0;j<cb;j++)if(b[j]<b[j+1])
      for(x=0;x<K;x++)for(y=0;y<K;y++)if(check(a[i]+x,b[j]+y))
        ans+=1LL*cal(a[i]+x,a[i+1])*cal(b[j]+y,b[j+1]);
    printf("%lld\n",ans);
  }
}