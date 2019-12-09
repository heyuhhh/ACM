#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=300010;
int Case,n,m,i,j,x,A,B,f[N],d[N],a[N],e[N][2],g[N],nxt[N];ll ans;map<int,ll>T[N];
inline void add(int x,int y){nxt[y]=g[x];g[x]=y;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    ans=0;
    for(i=1;i<=n;i++)g[i]=0,T[i].clear();
    for(i=2;i<=n;i++)scanf("%d",&f[i]),d[i]=d[f[i]]+1;
    for(i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
    for(i=1;i<=m;i++)scanf("%d%d%d",&x,&e[i][0],&e[i][1]),add(x,i);
    for(i=n;i;i--){
      T[i][d[i]]+=a[i];
      for(j=g[i];j;j=nxt[j]){
        A=d[i]+e[j][0],B=e[j][1];
        while(B&&T[i].size()){
          map<int,ll>::iterator it=T[i].upper_bound(A);
          if(it==T[i].begin())break;
          it--;
          x=B<it->second?B:it->second;
          B-=x;
          it->second-=x;
          ans-=x;
          if(!it->second)T[i].erase(it);
        }
      }
      if(i>1){
        x=f[i];
        if(T[x].size()<T[i].size())swap(T[x],T[i]);
        for(map<int,ll>::iterator it=T[i].begin();it!=T[i].end();it++)if(it->second)T[x][it->first]+=it->second;
      }
    }
    printf("%lld\n",ans);
  }
}