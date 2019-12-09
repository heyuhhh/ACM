#include<cstdio>
typedef long long ll;
int Case,m,d;ll k,ans;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll cal(ll n,int m){
  if(n<1)return 0;
  for(ll i=n+1;;i++)if(gcd(n,i)==1){
    m--;
    if(!m)return i-n;
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%lld%d",&k,&m);
    ans=-1;
    for(d=1;d<700;d++)if(cal(k^d,m)==d){
      if(ans==-1)ans=k^d;
      else if(ans>(k^d))ans=k^d;
    }
    printf("%lld\n",ans);
  }
}