#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int K=5;
int Case,n,i,x;ll ans;map<int,ll>T[K];
void ins(int o,int x,ll p){
  if(o>=K)return;
  T[o][x]+=p;
  ans+=p;
  while(p){
    map<int,ll>::iterator it=T[o].lower_bound(x+1);
    if(it==T[o].end())return;
    ll t=min(p,it->second);
    ans-=t;
    p-=t;
    ins(o+1,it->first,t);
    if(t==it->second)T[o].erase(it);else it->second-=t;
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    ans=0;
    for(i=0;i<K;i++)T[i].clear();
    for(i=1;i<=n;i++){
      scanf("%d",&x);
      ins(0,x,x);
      printf("%lld%c",ans,i<n?' ':'\n');
    }
  }
}